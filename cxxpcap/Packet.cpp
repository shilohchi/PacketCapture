#include "cxxpcap/Packet.h"
#include <ctime>

using namespace std;

namespace cxxpcap {
Packet::Packet(int length, timeval timestamp, const unsigned char* raw_data, int raw_data_length) {
	this->length = length;
	this->timestamp = timestamp;
	this->start = new unsigned char[raw_data_length];
	this->end = this->start + raw_data_length;
	for (int i = 0; i < raw_data_length; i++) {
		this->start[i] = raw_data[i];
	}
}

Packet::~Packet() {
	delete[] start;
}

int Packet::getLength() const {
	return length;
}

timeval Packet::getTimestamp() const {
	return timestamp;
}

Packet::const_iterator Packet::raw_data_begin() const {
	return this->start;
}

Packet::const_iterator Packet::raw_data_end() const {
	return this->end;
}

int Packet::raw_data_length() const {
	return end - start;
}
}
