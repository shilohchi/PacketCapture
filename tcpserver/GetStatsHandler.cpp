#include "GetStatsHandler.h"

GetStatsHandler::GetStatsHandler(PacketProducerThread** producer, PacketConsumerThread** consumer) {
	this->producer = producer;
	this->consumer = consumer;
}

QVariantMap GetStatsHandler::handleRequest(QVariantMap request) {
	if (request["target"] != "get_stats") {
		return next->handleRequest(request);
	}

	QVariantMap response;
	if (*producer) {
		QVariantMap result;

		// 统计数据分为三类：global, protocol, category
		QMap<QString, int> stats = (*consumer)->getStats();
		for (auto it = stats.begin(); it != stats.end(); it++) {
			result[it.key()] = it.value();
		}
		
		result["global/total"] = (*producer)->getStats();

		response["status"] = "ok";
		response["result"] = result;
	} else {
		response["status"] = "error";
		response["msg"] = QString::fromUtf8("抓包器尚未初始化");
	}
	return response;
}

