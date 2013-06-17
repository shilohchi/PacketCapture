#include "PacketDAOFactory.h"
#include <string>
#include "MysqlPacketDAO.h"
#include "errors.h"
#include "IPacketDAO.h"
#include <QSettings>

using namespace std;

shared_ptr<IPacketDAO> PacketDAOFactory::getPacketDAO() {
	QSettings config("config/config.ini", QSettings::IniFormat);
	string dbtype = config.value("database/dbtype").toString().toStdString();
	if (dbtype == "mysql") {
		return shared_ptr<IPacketDAO>(new MysqlPacketDAO());
	} else {
		string msg = dbtype + " is not supported.";
		throw UnsupportedDatabaseError(msg.c_str());
	}
}
