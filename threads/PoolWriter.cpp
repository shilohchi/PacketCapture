#include "PoolWriter.h"
	
void PoolWriter::setPool(std::shared_ptr<PacketPool> pool) {
	this->pool = pool;
}

PoolWriter::PoolWriter(std::shared_ptr<PacketPool> pool) {
	this->pool = pool;
}

void PoolWriter::recievePacket(std::shared_ptr<cxxpcap::Packet> packet) {
	this->pool->put(packet);
}
