#ifndef PACKET_DAOFACTORY_H_
#define PACKET_DAOFACTORY_H_

#include "IPacketDAO.h"
#include "MysqlPacketDAO.h"
#include <memory>

class PacketDAOFactory {
public:
	static std::shared_ptr<IPacketDAO> getPacketDAO();
};

#endif
