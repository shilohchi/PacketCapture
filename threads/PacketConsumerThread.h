#ifndef PACKET_CONSUMER_THREAD_H_
#define PACKET_CONSUMER_THREAD_H_

#include <QThread>
#include "PacketPool.h"
#include <memory>
class PacketConsumerThread : public QThread {
Q_OBJECT

private:
	int count = 0;

	bool stopping = false;
	
	std::string host{"localhost"};
	
	std::string dbname;

	std::string dbtype;

	std::string user;

	std::string password;

	std::shared_ptr<PacketPool> pool;

protected:
	void run() override;

public:
	PacketConsumerThread(std::shared_ptr<PacketPool> pool, QObject* parent = 0);

	void stop();

	void setDbtype(std::string dbtype);
	
	void setDbname(std::string dbname);

	void setHost(std::string host);
	
	void setUser(std::string user);

	void setPassword(std::string password);

signals:
	void valueChanged(int);
};

#endif
