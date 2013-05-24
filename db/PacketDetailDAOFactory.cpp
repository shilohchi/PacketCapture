#include "PacketDetailDAOFactory.h"
#include <string>
#include "MysqlPacketDetailDAO.h"
#include "errors.h"
#include "IPacketDetailDAO.h"
using namespace std;

shared_ptr<IPacketDetailDAO> PacketDetailDAOFactory::getPacketDetailDAO(string dbtype) {
	if (dbtype == "mysql") {
		return shared<IPacketDetailDAO>(new MysqlPacketDetailDAO());
	} else {
		throw UnsupportedDatabaseError("");
	}
}
