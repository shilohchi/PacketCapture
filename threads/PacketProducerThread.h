#ifndef PACKET_PRODUCER_THREAD_H_
#define PACKET_PRODUCER_THREAD_H_

#include <QThread>
#include <cxxpcap/cxxpcap.h>
#include <string>
#include "PacketPool.h"

class PacketProducerThread : public QThread, public cxxpcap::PacketReciever {
Q_OBJECT

private:
	cxxpcap::PacketCapture capture;
	
	std::string interface;

	std::string filter;
	
	std::shared_ptr<PacketPool> pool;

	int stats = 0;

protected:
	void run() override;

public:
	PacketProducerThread(std::shared_ptr<PacketPool> pool, QObject* parent = 0);
	
	void setInterface(std::string interface);

	void setFilter(std::string filter);

	void recievePacket(std::shared_ptr<const cxxpcap::Packet> packet) override;

signals:
	void statsChanged(int);
};

#endif
