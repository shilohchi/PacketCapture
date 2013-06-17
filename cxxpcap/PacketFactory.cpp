#include "cxxpcap/PacketFactory.h"
#include "cxxpcap/Packet.h"
#include "cxxpcap/InetPacket.h"
#include "cxxpcap/IPPacket.h"
#include "cxxpcap/UDPPacket.h"
#include "cxxpcap/TCPPacket.h"
#include "cxxpcap/cxxpcap_utils.h"
#include <ctime>
#include <memory>

using namespace std;

namespace cxxpcap {
shared_ptr<Packet> PacketFactory::createPacket(int length, timeval timestamp, 
		const unsigned char* raw_data, int raw_data_length, Protocol datalink_protocol) {
	shared_ptr<Packet> packet(new Packet(length, timestamp, raw_data, raw_data_length));	
	if (InetPacket::isValid(packet, datalink_protocol)) {
		shared_ptr<InetPacket> inetpkt = shared_ptr<InetPacket>(new InetPacket(packet, datalink_protocol));
		packet = inetpkt;
		if (IPPacket::isValid(inetpkt)) {
			shared_ptr<IPPacket> ippkt = shared_ptr<IPPacket>(new IPPacket(inetpkt));
			packet = ippkt;
			if (UDPPacket::isValid(ippkt)) {
				shared_ptr<UDPPacket> udppkt = shared_ptr<UDPPacket>(new UDPPacket(ippkt));
				packet = udppkt;
			} else if (TCPPacket::isValid(ippkt)) {
				shared_ptr<TCPPacket> tcppkt = shared_ptr<TCPPacket>(new TCPPacket(ippkt));
				packet = tcppkt;
			}
		}
	}
	return packet;
}
}
