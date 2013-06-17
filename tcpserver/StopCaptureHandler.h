#ifndef STOP_CAPTURE_H_
#define STOP_CAPTURE_H_

#include "RequestHandler.h"
#include "PacketProducerThread.h"

class StopCaptureHandler : public RequestHandler {
private:
	PacketProducerThread** producer;

public:
	StopCaptureHandler(PacketProducerThread** producer);

	QVariantMap handleRequest(QVariantMap request) override;
};

#endif
