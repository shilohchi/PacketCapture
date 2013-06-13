#include "GetConfigHandler.h"
#include <QSettings>

QVariantMap GetConfigHandler::handleRequest(QVariantMap request) {
	if (request["target"] != "get_config") {
		return next->handleRequest(request);
	}

	QSettings settings("config/config.ini");

	QVariantList list;
	if (request["items"].canConvert<QVariantList>()) {
		list = request["items"].toList();
	} else {
		list.append(request["items"]);
	}

	QVariantMap response;
	QVariantMap result;
	for (int i = 0; i < list.size(); i++) {
		QString key = list[i].toString();
		if (!settings.contains(key)) {
			QVariantMap error;
			error["status"] = "error";
			return error;
		}
		result[key] = settings.value(key);
	}
	response["status"] = "ok";
	response["result"] = result;
	return response;
}
