#include "TrivialFilter.h"
#include <memory>

using namespace std;
using namespace cxxpcap;

shared_ptr<PacketDTO> TrivialFilter::intercept(shared_ptr<Packet> packet) {
	if (shared_ptr<UDPPacket> udppkt = dynamic_pointer_cast<UDPPacket>(packet)) {
		shared_ptr<PacketDTO> dto = IPPacketToPacketDTO(udppkt);
		dto->transport_protocol = "udp";
		dto->src_port = udppkt->getSourcePort();
		dto->dst_port = udppkt->getDestinationPort();
		return dto;
	} else if (shared_ptr<TCPPacket> tcppkt = dynamic_pointer_cast<TCPPacket>(packet)) {
		shared_ptr<PacketDTO> dto = IPPacketToPacketDTO(tcppkt);
		dto->transport_protocol = "tcp";
		dto->src_port = tcppkt->getSourcePort();
		dto->dst_port = tcppkt->getDestinationPort();
		return dto;
	} else {
		return next->intercept(packet);
	}
}	
