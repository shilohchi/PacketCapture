#include "GetConfigHandler.h"
#include <QSettings>

QVariantMap GetConfigHandler::handleRequest(QVariantMap request) {
	if (request["target"] != "get_config") {
		return next->handleRequest(request);
	}

	QSettings settings("config/config.ini", QSettings::IniFormat);

	QVariantList list;
	// items中的项指明要查询的配置
	if (request["items"].canConvert<QVariantList>()) {
		list = request["items"].toList();
	} else {
		list.append(request["items"]);
	}

	QVariantMap response;
	QVariantMap result;
	for (int i = 0; i < list.size(); i++) {
		QString key = list[i].toString();
		if (!settings.contains(key)) {		// 不含该项
			QVariantMap error;
			error["status"] = "error";
			error["msg"] = QString::fromUtf8("无法识别的查询项： ") + key;
			return error;
		}
		result[key] = settings.value(key);
	}
	response["status"] = "ok";
	response["result"] = result;
	return response;
}
