#include "PacketProducerThread.h"
#include <QSettings>

using namespace std;
using namespace cxxpcap;

PacketProducerThread::PacketProducerThread(shared_ptr<PacketPool> pool, QObject* parent) :
		QThread(parent) {
	this->pool = pool;
	this->writer->setPool(pool);
}

void PacketProducerThread::run() {
	QSettings config("config/config.ini", QSettings::IniFormat);
	config.setIniCodec("UTF-8");
	
	string device = config.value("capture/device").toString().toStdString();
	capture.open(device);

	string filter = config.value("capture/rule").toString().toStdString();
	capture.setFilter(filter);

	capture.addHandler(this->stats);
	capture.addHandler(this->writer);

	capture.start();
}

void PacketProducerThread::stop() {
	capture.stop();
}

int PacketProducerThread::getStats() {
	return stats->getTotal();
}

