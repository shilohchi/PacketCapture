#ifndef PACKET_PRODUCER_THREAD_H_
#define PACKET_PRODUCER_THREAD_H_

#include <string>
#include <QThread>
#include "TrafficCounter.h"
#include "PoolWriter.h"
#include <cxxpcap/cxxpcap.h>
#include "PacketPool.h"

class PacketProducerThread : public QThread {
Q_OBJECT

private:
	cxxpcap::PacketCapture capture;
	
	std::string netinterface;

	std::string filter;
	
	std::shared_ptr<PacketPool> pool;

	TrafficCounter counter;
	
	PoolWriter writer;

protected:
	void run() override;

public:
	PacketProducerThread(std::shared_ptr<PacketPool> pool, QObject* parent = 0);
	
	void setInterface(std::string netinterface);

	void setFilter(std::string filter);
	
	TrafficCounter& getCounter();
	
	void stop();

};

#endif
