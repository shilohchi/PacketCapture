#ifndef POOL_WRITER_H_
#define POOL_WRITER_H_

#include "PacketPool.h"
#include <cxxpcap/PacketCapture.h>
#include <memory>

class PoolWriter : public cxxpcap::PacketReciever {
private:
	std::shared_ptr<PacketPool> pool;

public:
	PoolWriter() = default;
	
	void setPool(std::shared_ptr<PacketPool> pool); 

	PoolWriter(std::shared_ptr<PacketPool> pool); 

	void recievePacket(std::shared_ptr<const cxxpcap::Packet> packet) override; 
};
#endif
