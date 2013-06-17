#include "cxxpcap/TCPPacket.h"
#include "assert_ex.h"

using namespace std;

namespace cxxpcap {
bool TCPPacket::isValid(shared_ptr<IPPacket> packet) {
	bool valid = true;
	try {
		assert_ex(packet->getIPProtocol() == Protocol::TCP, ValidationError(""));
		assert_ex(packet->raw_data_end() >= packet->ip_data_begin() + 20, ValidationError(""));
	} catch (ValidationError& e) {
		valid = false;
	}
	return valid;
}

TCPPacket::TCPPacket(shared_ptr<IPPacket> packet) :
		IPPacket(packet) {
	if (!isValid(packet)) {
		throw PcapError("tcp");
	}
	this->tcp_header = this->ip_data;
	this->tcp_data = this->ip_data + getTCPHeaderLength();
}

TCPPacket::const_iterator TCPPacket::tcp_header_begin() const {
	return tcp_header;
}

TCPPacket::const_iterator TCPPacket::tcp_header_end() const {
	return tcp_data;
}

TCPPacket::const_iterator TCPPacket::tcp_data_begin() {
	return tcp_data;
}

TCPPacket::const_iterator TCPPacket::tcp_data_end() {
	return end;
}

int TCPPacket::getSourcePort() const {
	return (int(*tcp_header) << 8) + *(tcp_header + 1);
}

int TCPPacket::getDestinationPort() const {
	return (int(*tcp_header + 2) << 8) + *(tcp_header + 3);
}

int TCPPacket::getTCPHeaderLength() {
	return 20;
}
}
