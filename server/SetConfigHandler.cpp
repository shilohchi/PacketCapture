#include "SetConfigHandler.h"
#include <QSettings>

QVariantMap SetConfigHandler::handleRequest(QVariantMap request) {
	if (request["target"] != "set_config") {
		return next->handleRequest(request);
	}

	QSettings settings("config/config.ini", QSettings::IniFormat);
	QVariantMap items = request["items"].toMap();
	QVariantMap response;
	for (auto it = items.begin(); it != items.end(); it++) {
		settings.setValue(it.key(), it.value());
	}
	response["status"] = "ok";
	return response;
}
