#include <stdexcept>
#include "assert_ex.h"
#include "errors.h"
#include "SetTaskHandler.h"
#include <QSettings>
#include <QStringList>

using namespace std;

QVariantMap SetTaskHandler::handleRequest(QVariantMap request) {
	if (request["target"] != "set_task") {
		return next->handleRequest(request);
	}

	QVariantMap response;

	QSettings config("config/task.ini", QSettings::IniFormat);
	config.setIniCodec("UTF-8");

	QVariantMap task = request["task"].toMap();
	if (!task.contains("id")) {		// 缺少id，认为是要删除任务
		config.remove("task/id");
		config.remove("task/name");
		QStringList groups = config.childGroups();
		for (int i = 0; i < groups.size(); i++) {
			if (groups[i].startsWith("task.category")) {
				config.remove(groups[i]);
			}
		}
	} else {			// 含有id，接下来一一配置之
		
		if (!validate(task)) {
			response["status"] = "error";
			response["msg"] = QString::fromUtf8("数据不合法");
			return response;
		}

		config.setValue("task/id", task["id"]);
		if (task.contains("name")) {
			config.setValue("task/name", task["name"]);
		}

		if (task.contains("categories")) {
			QStringList groups = config.childGroups();
			for (int i = 0; i < groups.size(); i++) {
				if (groups[i].startsWith("task.category")) {
					config.remove(groups[i]);
				}
			}
		}

		int no = 0;
		QVariantMap categories = task["categories"].toMap();
		for (auto it = categories.begin(); it != categories.end(); it++) {
			no++;
			config.beginGroup("task.category" + QString::number(no));
			
			config.setValue("id", it.key());
			config.setValue("name", it.value());
			config.endGroup();
		}
	}

	response["status"] = "ok";
	return response;
}

bool SetTaskHandler::validate(QVariantMap task) {
	bool isValid = true;
	bool ok;
	try {
		if (task.contains("id")) {
			int v = task["id"].toString().toInt(&ok, 16);
			assert_ex(ok && 0 <= v && v <= 255, ValidationError(""));
		}
		if (task.contains("categories")) {
			QVariantMap categories = task["categories"].toMap();
			for (auto it = categories.begin(); it != categories.end(); it++) {
				int v = it.key().toInt(&ok, 16);
				assert_ex(ok && 0 <= v && v <= 255, ValidationError(""));
			}
		}
	} catch (ValidationError& e) {
		isValid = false;
	}
	return isValid;
}
