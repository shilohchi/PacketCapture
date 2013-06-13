#include "PacketPool.h"
#include <QMutexLocker>
#include <stdexcept>
#include <QThread>

using namespace std;
using namespace cxxpcap;

PacketPool::~PacketPool() {
	if (buffer) {
		delete[] buffer;
	}
}

PacketPool::PacketPool(int size) {
	if (size <= 0) {
		throw invalid_argument("");
	}
	this->emptySlotSem = shared_ptr<QSemaphore>(new QSemaphore(size));
	this->size = size;
	this->buffer = new shared_ptr<const Packet>[size];
}

void PacketPool::put(shared_ptr<const Packet> packet) {
	emptySlotSem->acquire();
	QMutexLocker(&this->mutex);
	buffer[head] = packet;
	head = (head + 1) % size;
	fullSlotSem->release();
}

shared_ptr<const Packet> PacketPool::take() {
	fullSlotSem->acquire();
	QMutexLocker(&this->mutex);
	shared_ptr<const Packet> packet = buffer[tail];
	tail = (tail + 1) % size;
	emptySlotSem->release();
	return packet;
}
