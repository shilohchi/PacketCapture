#include "PacketProducerThread.h"

using namespace std;
using namespace cxxpcap;

PacketProducerThread::PacketProducerThread(shared_ptr<PacketPool> pool, QObject* parent) :
		QThread(parent) {
	this->pool = pool;
	this->writer.setPool(pool);
}

void PacketProducerThread::setFilter(string filter) {
	this->filter = filter;
}

void PacketProducerThread::setInterface(string interface) {
	this->interface = interface;
}

void PacketProducerThread::run() {
	capture.open(interface);
	capture.setFilter(filter);
	capture.addHandler(&this->counter);
	capture.addHandler(&this->writer);
	capture.start();
}

TrafficCounter& PacketProducerThread::getCounter() {
	return this->counter;
}

void PacketProducerThread::stop() {
	capture.stop();
}
