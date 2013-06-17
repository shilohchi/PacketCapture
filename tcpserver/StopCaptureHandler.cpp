#include "StopCaptureHandler.h"

StopCaptureHandler::StopCaptureHandler(PacketProducerThread** producer) {
	// producer是二级指针，注意！！
	this->producer = producer;
}

QVariantMap StopCaptureHandler::handleRequest(QVariantMap request) {
	if (request["target"] != "stop_capture") {
		return next->handleRequest(request);
	}

	if (*producer) {
		(*producer)->stop();
	}

	QVariantMap response;
	response["status"] = "ok";
	return response;
}
