#ifndef PACKET_CONSUMER_THREAD_H_
#define PACKET_CONSUMER_THREAD_H_

#include <memory>
#include <QThread>
#include "PacketPool.h"

class PacketConsumerThread : public QThread {
private:
	bool stopping = false;
	
	std::string host{"localhost"};

	std::string user;

	std::string password;

	std::shared_ptr<PacketPool> pool;

protected:
	void run() override;

public:
	PacketConsumerThread(std::shared_ptr<PacketPool> pool, QObject* parent = 0);

	void stop();

	void setHost(std::string host);

	void setPassword(std::string password);

};

#endif
