#ifndef IPACKETDETAILDAO_H_
#define IPACKETDETAILDAO_H_

#include "PacketDetail.h"

class IPacketDetailDAO {
public:
	virtual void open(std::string host, std::string user, std::string password, std::string dbname) = 0;
	virtual void close() = 0;
	virtual void insert(const PacketDetail& packet) = 0;
};

#endif
