#include "PacketDetailDAOFactory.h"
#include <string>
#include "MysqlPacketDetailDAO.h"
#include "errors.h"
#include "IPacketDetailDAO.h"
using namespace std;

shared_ptr<IPacketDetailDAO> PacketDetailDAOFactory::getPacketDetailDAO(string dbtype) {
	if (dbtype == "mysql") {
		return shared_ptr<IPacketDetailDAO>(new MysqlPacketDetailDAO());
	} else {
		string msg = dbtype + " is not supported.";
		throw UnsupportedDatabaseError(msg.c_str());
	}
}
