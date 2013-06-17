#ifndef GET_STATS_HANDLER_H_ 
#define GET_STATS_HANDLER_H_

#include "RequestHandler.h"
#include "PacketProducerThread.h"
#include "PacketConsumerThread.h"

class GetStatsHandler : public RequestHandler {
private:
	PacketProducerThread** producer = NULL;

	PacketConsumerThread** consumer = NULL;

public:
	GetStatsHandler(PacketProducerThread** producer, PacketConsumerThread** consumer);

	QVariantMap handleRequest(QVariantMap request) override;
};

#endif
