#include "cxxpcap/UDPPacket.h"
#include "assert_ex.h"

using namespace std;

namespace cxxpcap {
bool UDPPacket::isValid(shared_ptr<IPPacket> packet) {
	bool valid = true;
	try {
		assert_ex(packet->getIPProtocol() == Protocol::UDP, ValidationError(""));
		assert_ex(packet->raw_data_end() >= packet->ip_data_begin() + 8, ValidationError(""));
	} catch (ValidationError& e) {
		valid = false;
	}
	return valid;
}

UDPPacket::UDPPacket(shared_ptr<IPPacket> packet) :
		IPPacket(packet) {
	if (!isValid(packet)) {
		throw PacketError("udp");
	}
	this->udp_header = this->ip_data;
	this->udp_data = this->ip_data + getUDPHeaderLength();
}

UDPPacket::const_iterator UDPPacket::udp_header_begin() {
	return udp_header;
}

UDPPacket::const_iterator UDPPacket::udp_header_end() {
	return udp_data;
}

UDPPacket::const_iterator UDPPacket::udp_data_begin() {
	return udp_data;
}

UDPPacket::const_iterator UDPPacket::udp_data_end() {
	return end;
}

int UDPPacket::getUDPHeaderLength() {
	return 8;
}

int UDPPacket::getSourcePort() const {
	return (int(*udp_header) << 8) + *(udp_header + 1);
}

int UDPPacket::getDestinationPort() const {
	return (int(*udp_header + 2) << 8) + *(udp_header + 3);
}
}
