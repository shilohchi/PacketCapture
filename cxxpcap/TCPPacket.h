#ifndef TCPPACKET_H_
#define TCPPACKET_H_

#include "cxxpcap/IPPacket.h"

namespace cxxpcap {
class TCPPacket : public IPPacket {
protected:
	unsigned char* tcp_header;
	unsigned char* tcp_data;
	
public:
	typedef const unsigned char* const_iterator;
	
	static bool isValid(std::shared_ptr<IPPacket> packet);

	TCPPacket(std::shared_ptr<IPPacket> packet);

	TCPPacket(const TCPPacket&) = delete;

	TCPPacket& operator=(const TCPPacket&) = delete;
	
	TCPPacket::const_iterator tcp_header_begin() const;
	TCPPacket::const_iterator tcp_header_end() const;
	TCPPacket::const_iterator tcp_data_begin();
	TCPPacket::const_iterator tcp_data_end();

	int getTCPHeaderLength();

	int getSourcePort() const;
	int getDestinationPort() const;
};
}

#endif
