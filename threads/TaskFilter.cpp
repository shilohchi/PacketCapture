#include <QStringList>
#include "TaskFilter.h"
#include <QSettings>
#include "assert_ex.h"
#include "errors.h"
#include <cxxpcap/cxxpcap.h>

using namespace std;
using namespace cxxpcap;

shared_ptr<PacketDTO> TaskFilter::intercept(shared_ptr<Packet> packet) {
	QSettings config("config/task.ini");
	config.setIniCodec("UTF-8");
	
	if (!validate(packet)) {
		return next->intercept(packet);
	}

	shared_ptr<UDPPacket> udppkt = dynamic_pointer_cast<UDPPacket>(packet);
	shared_ptr<PacketDTO> dto = IPPacketToPacketDTO(udppkt);
	
	dto->src_port = udppkt->getSourcePort();
	dto->dst_port = udppkt->getDestinationPort();

	dto->task_id = config.value("task/id").toString();
	dto->task_name = config.value("task/name").toString();

	auto data = udppkt->udp_data_begin();
	QStringList groups = config.childGroups();

	int category_index = config.value("task/category_index").toInt();
	for (int i = 0; i < groups.size(); i++) {
		if (groups.startsWith("task.category")) {
			bool ok;
			int category_id = config.value(groups[i] + "/id").toString().toInt(&ok, 16);
			assert_ex(ok, "任务配置中，分类信息id必须为16进制整数");
			if (data[category_index] == category_id) {
				dto->category_id = config.value(groups[i] + "/id").toString();
				dto->category_name = config.value(groups[i] + "/name").toString();
				break;
			}
		}
	}
	
	return dto;
}

/*
 * 协议验证。如果配置了任务，就进行验证。分三部分：
 * 1. 特征字节匹配
 * 2. 任务id匹配
 * 3. 分类信息index有效
 */
bool TaskFilter::validate(shared_ptr<Packet> packet) {
	bool isValid = true;
	QSettings config("config/task.ini");
	config.setIniCodec("UTF-8");

	try {
		QString protocol = config.value("protocol/transport_protocol").toString();
		// 协议必须为UDP
		assert_ex(protocol == "udp", "任务配置中，协议必须为udp");

		shared_ptr<UDPPacket> udppkt = dynamic_pointer_cast<UDPPacket>(packet);
		assert_ex(bool(udppkt), ::ValidationError(""));
		auto data = udppkt->udp_data_begin();

		QStringList groups = config.childGroups();
		// 验证特征字节
		for (int i = 0; i < groups.size(); i++) {
			if (groups[i].startsWith("protocol.validation")) {
				config.beginGroup(groups[i]);
				int index = config.value("index").toInt();
				QStringList values = config.value("value").toString().split(",");
				config.endGroup();

				bool flag = false;
				assert_ex(index < udppkt->udp_data_end() - udppkt->udp_data_begin(), ::ValidationError(""));
				for (int j = 0; j < values.size() && !flag; j++) {
					bool ok = false;
					int v = values[j].toInt(&ok, 16);
					assert_ex(!ok, "协议验证中，特征值必须是00至FF之间的16进制整数");
					flag = flag && (data[index] == v);
				}
				assert_ex(flag, ::ValidationError(""));
			}
		}
	
		// 任务ID验证
		int task_index = config.value("task/task_index").toInt();
		assert_ex(task_index < udppkt->udp_data_end() - udppkt->udp_data_begin(), ::ValidationError(""));
		bool ok = false;
		int task_id = config.value("task/id").toString().toInt(&ok, 16);
		assert_ex(!ok, "任务id必须是16进制整数");
		assert_ex(data[task_index] == task_id, ::ValidationError(""));

		// 分类信息index有效性验证
		int category_index = config.value("task/category_index").toInt();
		assert_ex(category_index < udppkt->udp_data_end() - udppkt->udp_data_begin(), ::ValidationError(""));
	} catch (::ValidationError& e) {
		isValid = false;
	}

	return isValid;
}
