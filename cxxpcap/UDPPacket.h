#ifndef UDP_PACKET_H_
#define UDP_PACKET_H_

#include "cxxpcap/IPPacket.h"
#include "cxxpcap/cxxpcap_utils.h"

namespace cxxpcap {
class UDPPacket : public IPPacket {
private:
	int sourcePort;
	int destinationPort;

protected:
	unsigned char* udp_header;
	unsigned char* udp_data;

public:
	typedef unsigned char* const_iterator;

	static bool isValid(std::shared_ptr<IPPacket> packet);

	UDPPacket(std::shared_ptr<IPPacket> packet);

	UDPPacket(const UDPPacket&) = delete;

	UDPPacket& operator=(const UDPPacket&) = delete;

	UDPPacket::const_iterator udp_header_begin();
	UDPPacket::const_iterator udp_header_end();
	UDPPacket::const_iterator udp_data_begin();
	UDPPacket::const_iterator udp_data_end();
	
	Protocol getUDPProtocol();
	int getUDPHeaderLength();
	
	int getSourcePort() const;
	int getDestinationPort() const;
};
}

#endif
