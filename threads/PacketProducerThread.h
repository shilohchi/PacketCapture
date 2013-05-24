#ifndef PACKET_PRODUCER_THREAD_H_
#define PACKET_PRODUCER_THREAD_H_

#include <cxxpcap/cxxpcap.h>
#include <string>
#include "PacketPool.h"
#include <QThread>
#include "TrafficCounter.h"
#include "PoolWriter.h"

class PacketProducerThread : public QThread {
Q_OBJECT

private:
	cxxpcap::PacketCapture capture;
	
	std::string interface;

	std::string filter;
	
	std::shared_ptr<PacketPool> pool;

	TrafficCounter counter;
	
	PoolWriter writer;

protected:
	void run() override;

public:
	PacketProducerThread(std::shared_ptr<PacketPool> pool, QObject* parent = 0);
	
	void setInterface(std::string interface);

	void setFilter(std::string filter);
	
	TrafficCounter& getCounter();
	
	void stop();

};

#endif
