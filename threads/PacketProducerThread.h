#ifndef PACKET_PRODUCER_THREAD_H_
#define PACKET_PRODUCER_THREAD_H_

#include <memory>
#include <string>
#include <QThread>
#include "PoolWriter.h"
#include "PacketPool.h"
#include <cxxpcap/cxxpcap.h>

class PacketProducerThread : public QThread {
Q_OBJECT

public:
	class TrafficStats : public cxxpcap::PacketReciever {
	private:
		int total = 0;

	public:
		void recievePacket(std::shared_ptr<cxxpcap::Packet> packet) override {
			total++;
		}

		int getTotal() {
			return total;
		}
	};

private:
	cxxpcap::PacketCapture capture;
	
	std::shared_ptr<PacketPool> pool;

	std::shared_ptr<PoolWriter> writer{new PoolWriter()};

	std::shared_ptr<TrafficStats> stats{new TrafficStats()};

protected:
	void run() override;

public:
	PacketProducerThread(std::shared_ptr<PacketPool> pool, QObject* parent = 0);
	
	int getStats();

	void stop();
};

#endif
