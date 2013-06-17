#include "Filter.h"

using namespace std;
using namespace cxxpcap;

void Filter::setNext(shared_ptr<Filter> filter) {
	this->next = filter;
}

shared_ptr<PacketDTO> Filter::IPPacketToPacketDTO(shared_ptr<IPPacket> packet) {
	shared_ptr<PacketDTO> dto(new PacketDTO());
	dto->len = packet->getLength();
	dto->caplen = packet->raw_data_length();
	dto->src_ip = packet->getSourceIP().c_str();
	dto->dst_ip = packet->getDestinationIP().c_str();

	long long sec = packet->getTimestamp().tv_sec;
	long long usec = packet->getTimestamp().tv_usec;
	long long msecs = sec * 1000 + usec / 1000;
	dto->timestamp = QDateTime::fromMSecsSinceEpoch(msecs);

	for (int i = 0; i < packet->raw_data_length(); i++) {
		dto->data[i] = packet->raw_data_begin()[i];
	}
	return dto;
}
