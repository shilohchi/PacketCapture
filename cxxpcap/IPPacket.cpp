#include "cxxpcap/IPPacket.h"
#include <string>
#include "assert_ex.h"

using namespace std;

namespace cxxpcap {
bool IPPacket::isValid(shared_ptr<InetPacket> packet) {
	bool valid = true;
	try {
		assert_ex(packet->getDatalinkProtocol() == Protocol::IP, ValidationError(""));
		assert_ex(packet->datalink_data_end() >= packet->datalink_data_begin() + 20, ValidationError(""));
		int len = int(*packet->datalink_data_begin() & 0xf) * 4;
		assert_ex(packet->datalink_data_end() >= packet->datalink_data_begin() + len, ValidationError(""));
	} catch (ValidationError& e) {
		valid = false;
	}
	return valid;
}

IPPacket::IPPacket(shared_ptr<InetPacket> packet) :
		InetPacket(packet, packet->getDatalinkType()) {
	if (!isValid(packet)) {
		throw PcapError("ip");
	}
	this->ip_header = this->datalink_data;
	this->ip_data = this->datalink_data + getIPHeaderLength();
}	


Protocol IPPacket::getIPProtocol() const {
	Protocol protocol;
	switch (*(ip_header + 9)) {
	case 0x11:
		protocol = Protocol::UDP;
		break;
	case 0x06:
		protocol = Protocol::TCP;
		break;
	default:
		protocol = Protocol::Unknown;
	}

	return protocol;
}

	
IPPacket::const_iterator IPPacket::ip_header_begin() {
	return ip_header;
}

IPPacket::const_iterator IPPacket::ip_header_end() {
	return ip_data;
}

IPPacket::const_iterator IPPacket::ip_data_begin() {
	return ip_data;
}

IPPacket::const_iterator IPPacket::ip_data_end() {
	return end;
}

int IPPacket::getIPHeaderLength() const {
	return ((*ip_header) & 0xf) * 4;
}

int IPPacket::getIPVersion() const {
	return (*ip_header >> 4) & 0xf;
}

string IPPacket::getSourceIP() const {
	string ip_str = "";
	uint32_t ip_int = *((uint32_t*) (ip_header + 12));
	for (int i = 0; i < 4; i++) {
		int t = (ip_int >> i * 8) & 0xff;
		ip_str += to_string(t);
		if (i + 1 != 4) {
			ip_str += ".";
		}
	}
	return ip_str;
}

string IPPacket::getDestinationIP() const {
	string ip_str = "";
	uint32_t ip_int = *((uint32_t*) (ip_header + 16));
	for (int i = 0; i < 4; i++) {
		int t = (ip_int >> i * 8) & 0xff;
		ip_str += to_string(t);
		if (i + 1 != 4) {
			ip_str += ".";
		}
	}
	return ip_str;
}
}
