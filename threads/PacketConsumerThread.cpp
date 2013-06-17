#include "PacketConsumerThread.h"
#include "PacketDAOFactory.h"
#include "Filter.h"
#include "TaskFilter.h"
#include "NullFilter.h"
#include "TrivialFilter.h"
#include <QSettings>

using namespace std;
using namespace cxxpcap;

PacketConsumerThread::PacketConsumerThread(shared_ptr<PacketPool>  pool, QObject* parent) : 
		QThread(parent) {
	this->pool = pool;	
}

void PacketConsumerThread::run() {
	shared_ptr<IPacketDAO> dao = PacketDAOFactory::getPacketDAO();
	dao->open();

	while (!stopping) {
		shared_ptr<Packet> packet = pool->take();

		// 应用层过滤器
		shared_ptr<Filter> filters = createChain();	
		shared_ptr<PacketDTO> dto = filters->intercept(packet);	
		if (dto) {
			dao->insert(dto);
		}

		// 生成统计数据
		changeStats(dto);
	}
	dao->close();
}

shared_ptr<Filter> PacketConsumerThread::createChain() {
	QSettings config("config/task.ini", QSettings::IniFormat);
	config.setIniCodec("UTF-8");
	
	shared_ptr<Filter> head;

	if (config.contains("task/id")) { // 认为配置了任务
		shared_ptr<Filter> p(new TaskFilter());
		head = p;
		shared_ptr<Filter> tail = p;

		p = shared_ptr<Filter>(new NullFilter());
		tail->setNext(p);
		tail = p;
	} else {	// 没有配置任务
		shared_ptr<Filter> p(new TrivialFilter());
		head = p;
		shared_ptr<Filter> tail = p;

		p = shared_ptr<Filter>(new NullFilter());
		tail->setNext(p);
		tail = p;
	}

	return head;
}

void PacketConsumerThread::changeStats(shared_ptr<PacketDTO> dto) {
	// 当前总量和过滤后的实际量
	stats["global/current"]++;
	if (dto) {
		stats["global/saved"]++;

		// 按传输层协议
		QString transport_protocol = dto->transport_protocol;
		if (transport_protocol != "") {
			stats["protocol/" + transport_protocol]++;
		}

		// 按信息分类
		QString category = dto->category_name;
		if (category != "") {
			stats["category/" + category]++;
		}
	}
}

QMap<QString, int> PacketConsumerThread::getStats() {
	return stats;
}
