#include "StartCaptureHandler.h"
#include "PacketPool.h"
#include <memory>

using namespace std;

StartCaptureHandler::StartCaptureHandler(PacketProducerThread** producer, PacketConsumerThread** consumer) {
	// producer, consumer都是二级指针，注意！！
	this->producer = producer;
	this->consumer = consumer;
}

QVariantMap StartCaptureHandler::handleRequest(QVariantMap request) {
	if (request["target"] != "start_capture") {
		return next->handleRequest(request);
	}
	
	if (*producer) {
		(*producer)->stop();
	}
	
	shared_ptr<PacketPool> pool(new PacketPool(1024));
	// *producer, *consumer都未释放，因难以确定释放时机，内存泄漏！！
	*producer = new PacketProducerThread(pool);
	*consumer = new PacketConsumerThread(pool);
	(*producer)->start();
	(*consumer)->start();

	QVariantMap response;
	response["status"] = "ok";
	return response;
}
