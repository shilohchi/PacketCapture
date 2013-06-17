#include "SetConfigHandler.h"
#include <QSettings>

QVariantMap SetConfigHandler::handleRequest(QVariantMap request) {
	if (request["target"] != "set_config") {
		return next->handleRequest(request);
	}

	QSettings settings("config/config.ini", QSettings::IniFormat);
	settings.setIniCodec("UTF-8");
	QVariantMap items = request["items"].toMap();
	QVariantMap response;

	// 依次设置每一项，未作检测，危险
	for (auto it = items.begin(); it != items.end(); it++) {
		settings.setValue(it.key(), it.value());
	}
	response["status"] = "ok";
	return response;
}
