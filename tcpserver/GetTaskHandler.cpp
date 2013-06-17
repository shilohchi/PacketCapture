#include "GetTaskHandler.h"
#include <QSettings>
#include <QStringList>

QVariantMap GetTaskHandler::handleRequest(QVariantMap request) {
	if (request["target"] != "get_task") {
		return next->handleRequest(request);
	}
	
	QSettings config("config/task.ini", QSettings::IniFormat);
	config.setIniCodec("UTF-8");

	QVariantMap result;
	if (config.contains("task/id")) {	// id是任务是否配置的唯一标准
		result["id"] = config.value("task/id");
		result["name"] = config.value("task/name");

		QVariantMap categories;
		auto groups = config.childGroups();
		for (int i = 0; i < groups.size(); i++) {
			if (groups[i].startsWith("task.category")) {
				config.beginGroup(groups[i]);
				QString id = config.value("id").toString();
				QString name = config.value("name").toString();
				categories[id] = name;
				config.endGroup();
			}
		}
		result["categories"] = categories;
	}
	
	QVariantMap response;
	response["status"] = "ok";
	response["result"] = result;
	return response;
}

