#ifndef PACKETFACTORY_H_
#define PACKETFACTORY_H_

#include <ctime>
#include "cxxpcap_utils.h"
#include "cxxpcap/Packet.h"
#include <memory>

namespace cxxpcap {
class PacketFactory {
public:
	static std::shared_ptr<Packet> createPacket(int length, timeval timestamp, 
			const unsigned char* raw_data, int raw_data_length, Protocol protocol);
};
}

#endif
