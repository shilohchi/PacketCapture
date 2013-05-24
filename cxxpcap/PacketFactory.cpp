#include "cxxpcap/PacketFactory.h"
#include "cxxpcap/Packet.h"
#include "cxxpcap/InetPacket.h"
#include "cxxpcap/IPPacket.h"
#include "cxxpcap/UDPPacket.h"
#include "cxxpcap/TCPPacket.h"
#include "cxxpcap/utils.h"
#include <cstdint>
#include <ctime>
#include <memory>

using namespace std;

namespace cxxpcap {
shared_ptr<const Packet> PacketFactory::createPacket(int length, timeval timestamp, 
		const uint8_t* raw_data, int raw_data_length, Protocol datalink_protocol) {
	Protocol protocol = Protocol::Unknown;

	if (InetPacket::isValid(raw_data, raw_data_length, datalink_protocol)) {
		protocol = Protocol::INET;
		if (IPPacket::isValid(raw_data, raw_data_length, datalink_protocol)) {
			protocol = Protocol::IP;
			if (UDPPacket::isValid(raw_data, raw_data_length, datalink_protocol)) {
				protocol = Protocol::UDP;
			} else if (TCPPacket::isValid(raw_data, raw_data_length, datalink_protocol)) {
				protocol = Protocol::TCP;
			}
		}
	}
	
	shared_ptr<const Packet> packet;
	switch (protocol) {
	case Protocol::Unknown:
		packet = shared_ptr<const Packet>(new Packet(length, timestamp, raw_data, raw_data_length));
		break;
	case Protocol::INET:
		packet = shared_ptr<const Packet>(new InetPacket(length, timestamp, raw_data, raw_data_length, datalink_protocol));
		break;
	case Protocol::IP:
		packet = shared_ptr<const Packet>(new IPPacket(length, timestamp, raw_data, raw_data_length, datalink_protocol));	
		break;
	case Protocol::UDP:
		packet = shared_ptr<const Packet>(new UDPPacket(length, timestamp, raw_data, raw_data_length, datalink_protocol));	
		break;
	case Protocol::TCP:
		packet = shared_ptr<const Packet>(new TCPPacket(length, timestamp, raw_data, raw_data_length, datalink_protocol));	
		break;
	}

	return packet;
}
}