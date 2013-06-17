#ifndef START_CAPTURE_H_
#define START_CAPTURE_H_

#include "RequestHandler.h"
#include "PacketProducerThread.h"
#include "PacketConsumerThread.h"

class StartCaptureHandler : public RequestHandler {
private:
	PacketProducerThread** producer = NULL;

	PacketConsumerThread** consumer = NULL;

public:
	StartCaptureHandler(PacketProducerThread** producer, PacketConsumerThread** consumer);

	QVariantMap handleRequest(QVariantMap request) override;
};

#endif
