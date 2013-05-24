#ifndef PACKETDETAILDAOFACTORY_H_
#define PACKETDETAILDAOFACTORY_H_

#include "IPacketDetailDAO.h"
#include "MysqlPacketDetailDAO.h"
#include <memory>

class PacketDetailDAOFactory {
public:
	static std::shared<IPacketDetailDAO> getPacketDetailDAO(string dbtype);
};

#endif
