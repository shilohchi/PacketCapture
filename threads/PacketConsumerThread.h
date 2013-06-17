#ifndef PACKET_CONSUMER_THREAD_H_
#define PACKET_CONSUMER_THREAD_H_

#include "Filter.h"
#include <QThread>
#include "PacketPool.h"
#include <memory>
#include <QMap>
#include <QString>

class PacketConsumerThread : public QThread {
Q_OBJECT

private:
	QMap<QString, int> stats;

	int count = 0;

	bool stopping = false;
	
	std::shared_ptr<PacketPool> pool;

protected:
	void run() override;

	std::shared_ptr<Filter> createChain();
	
	void changeStats(std::shared_ptr<PacketDTO> dto);

public:
	PacketConsumerThread(std::shared_ptr<PacketPool> pool, QObject* parent = 0);

	void stop();
	
	QMap<QString, int> getStats();
};

#endif
