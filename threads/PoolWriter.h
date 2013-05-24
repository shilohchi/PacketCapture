#ifndef POOL_WRITER_H_
#define POOL_WRITER_H_

#include <cxxpcap/PacketCapture.h>
#include <memory>

class PoolWriter : public cxxpcap::PacketReciever {
private:
	std::shared_ptr<PacketPool> pool;

public:
	PoolWriter() = default;
	
	void setPool(std::shared_ptr<PacketPool> pool) {
		this->pool = pool;
	}

	PoolWriter(std::shared_ptr<PacketPool> pool) {
		this->pool = pool;
	}

	void recievePacket(std::shared_ptr<const cxxpcap::Packet> packet) override {
		pool->put(packet);
	}
};

#endif
