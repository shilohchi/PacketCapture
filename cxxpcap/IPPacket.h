#ifndef IP_PACKET_H_
#define IP_PACKET_H_

#include "cxxpcap/InetPacket.h"
#include <string>
#include "cxxpcap/cxxpcap_utils.h"

namespace cxxpcap {
class IPPacket : public InetPacket {
private:
	std::string sourceIP;
	std::string destinationIP;

protected:
	std::uint8_t* ip_header;
	std::uint8_t* ip_data;

public:
	typedef const uint8_t* const_iterator;
	
	static bool isValid(std::shared_ptr<InetPacket> packet);

	IPPacket(std::shared_ptr<InetPacket> packet);

	IPPacket(const IPPacket&) = delete;

	IPPacket& operator=(const IPPacket&) = delete;

	IPPacket::const_iterator ip_header_begin();
	IPPacket::const_iterator ip_header_end();
	IPPacket::const_iterator ip_data_begin();
	IPPacket::const_iterator ip_data_end();

	Protocol getIPProtocol() const;
	int getIPHeaderLength() const;

	std::string getSourceIP() const;
	std::string getDestinationIP() const;

	int getIPVersion() const;
};
}
#endif
