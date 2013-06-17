#include "cxxpcap/InetPacket.h"
#include "cxxpcap/cxxpcap_utils.h"
#include "assert_ex.h"

using namespace std;

namespace cxxpcap {
bool InetPacket::isValid(shared_ptr<Packet> packet, Protocol datalink_protocol) {
	bool valid = true;
	try {
		assert_ex(datalink_protocol == Protocol::Ethernet, ValidationError("")); 
		assert_ex(packet->raw_data_end() >= packet->raw_data_begin() + 14, ValidationError(""));
	} catch (ValidationError& e) {
		valid = false;
	}
	return valid;
}

InetPacket::InetPacket(shared_ptr<Packet> packet, Protocol datalink_protocol) :
		Packet(packet->getLength(), packet->getTimestamp(), packet->raw_data_begin(),
				packet->raw_data_length()) {
	if (!isValid(packet, datalink_protocol)) {
		throw PacketError("inet");
	}
	this->datalinkInfo = shared_ptr<DatalinkInfo>(new EthernetInfo(this->raw_data_begin()));
	this->datalink_header = this->start;
	this->datalink_data = this->start + this->datalinkInfo->getLength();
}

shared_ptr<DatalinkInfo> InetPacket::getDatalinkInfo() const {
	return datalinkInfo;
}

Protocol InetPacket::getDatalinkProtocol() const {
	return datalinkInfo->getProtocol();
}

Protocol InetPacket::getDatalinkType() {
	return datalinkInfo->getType();
}

InetPacket::const_iterator InetPacket::datalink_header_begin() const {
	return datalink_header;
}

InetPacket::const_iterator InetPacket::datalink_header_end() const {
	return datalink_data;
}

InetPacket::const_iterator InetPacket::datalink_data_begin() const {
	return datalink_data;
}

InetPacket::const_iterator InetPacket::datalink_data_end() const {
	return end;
}

}
