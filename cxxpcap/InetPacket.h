#ifndef INETPACKET_H_
#define INETPACKET_H_

#include "cxxpcap/cxxpcap_utils.h"
#include "cxxpcap/Packet.h"
#include "cxxpcap/DatalinkInfo.h"
#include <memory>

namespace cxxpcap {
class InetPacket : public Packet {
private:
	std::shared_ptr<DatalinkInfo> datalinkInfo;

protected:
	unsigned char* datalink_header;
	unsigned char* datalink_data;

public:
	typedef const unsigned char* const_iterator;

	static bool isValid(std::shared_ptr<Packet> packet, Protocol datalink_protocol);

	InetPacket(std::shared_ptr<Packet> packet, Protocol datalink_protocol);

	InetPacket(const InetPacket&) = delete;

	InetPacket& operator=(const InetPacket&) = delete;

	std::shared_ptr<DatalinkInfo> getDatalinkInfo() const;

	Protocol getDatalinkProtocol() const;
	Protocol getDatalinkType();

	InetPacket::const_iterator datalink_header_begin() const;
	InetPacket::const_iterator datalink_header_end() const;

	InetPacket::const_iterator datalink_data_begin() const;
	InetPacket::const_iterator datalink_data_end() const;
};
}

#endif
