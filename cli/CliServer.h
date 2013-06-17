#ifndef CLI_SERVER_H_
#define CLI_SERVER_H_

#include "PacketProducerThread.h"
#include "PacketConsumerThread.h"
#include <QObject>
#include "Server.h"
#include <memory>

class CliServer : public QObject {
private:
	PacketProducerThread* producer = NULL;

	PacketConsumerThread* consumer = NULL;

	Server* server;

protected:
	std::shared_ptr<RequestHandler> createHandlerChain();

public:
	CliServer();

	void start();
};

#endif
