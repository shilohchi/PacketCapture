#ifndef IPACKETDETAILDAO_H_
#define IPACKETDETAILDAO_H_

#include "PacketDTO.h"
#include <memory>

class IPacketDAO {
public:
	virtual void open() = 0;
	virtual void close() = 0;
	virtual void insert(std::shared_ptr<PacketDTO> packet) = 0;
};

#endif
