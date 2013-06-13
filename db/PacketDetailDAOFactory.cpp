#include "PacketDetailDAOFactory.h"
#include <string>
#include "MysqlPacketDetailDAO.h"
#include "errors.h"
#include "IPacketDetailDAO.h"
#include "ConfigParser.h"
#include <boost/any.hpp>

using namespace std;

shared_ptr<IPacketDetailDAO> PacketDetailDAOFactory::getPacketDetailDAO() {
	shared_ptr<ConfigParser> parser = ConfigParser::getConfigParser();
	string dbtype = boost::any_cast<string>(parser->get("database.dbtype"));
	if (dbtype == "mysql") {
		return shared_ptr<IPacketDetailDAO>(new MysqlPacketDetailDAO());
	} else {
		string msg = dbtype + " is not supported.";
		throw UnsupportedDatabaseError(msg.c_str());
	}
}
