#ifndef PC_FILTER_H_
#define PC_FILTER_H_

#include <memory>
#include "PacketDTO.h"
#include "cxxpcap/cxxpcap.h"

class Filter {
protected:
	std::shared_ptr<Filter> next;

protected:
	static std::shared_ptr<PacketDTO> IPPacketToPacketDTO(std::shared_ptr<cxxpcap::IPPacket> packet);

public:
	virtual void setNext(std::shared_ptr<Filter> filter);

	virtual std::shared_ptr<PacketDTO> intercept(std::shared_ptr<cxxpcap::Packet> packet) = 0;
};

#endif
