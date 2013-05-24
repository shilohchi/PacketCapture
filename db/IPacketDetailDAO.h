#ifndef IPACKETDETAILDAO_H_
#define IPACKETDETAILDAO_H_

#include "PacketDetail.h"

class IPacketDetailDAO {
public:
	virtual void open(string host, string user, string password) = 0;
	virtual void close() = 0;
	virtual void insert(const PacketDetail& packet) = 0;
};

#endif
