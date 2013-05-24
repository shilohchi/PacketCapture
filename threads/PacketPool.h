#ifndef PACKET_POOL_H_
#define PACKET_POOL_H_

#include <QSemaphore>
#include <QMutex>
#include <QMutexLocker>
#include <memory>
#include <cxxpcap/Packet.h>

class PacketPool {
private:
	QMutex mutex;

	int size;

	std::shared_ptr<const cxxpcap::Packet>*  buffer;

	std::shared_ptr<QSemaphore> fullSlotSem{new QSemaphore(0)};

	std::shared_ptr<QSemaphore> emptySlotSem{NULL};
	
	int head = 0;

	int tail = 0;

public:
	PacketPool(int size);

	virtual ~PacketPool();
	
	void put(std::shared_ptr<const cxxpcap::Packet> packet);

	std::shared_ptr<const cxxpcap::Packet> take();
};

#endif
