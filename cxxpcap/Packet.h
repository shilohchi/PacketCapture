#ifndef PACKET_H_
#define PACKET_H_

#include <pcap.h>

namespace cxxpcap {
class Packet {
private:
	int length;
	timeval timestamp;
	
protected:
	unsigned char* start = NULL;
	unsigned char* end = NULL;

public:
	typedef const unsigned char* const_iterator;
	
	Packet(int length, timeval timestamp, const unsigned char* raw_data, int raw_data_length);

	Packet(const Packet&) = delete;

	Packet& operator=(const Packet&) = delete;

	virtual ~Packet();

	int getLength() const;
	timeval getTimestamp() const;

	Packet::const_iterator raw_data_begin() const;
	Packet::const_iterator raw_data_end() const;

	int raw_data_length() const;
};
}
#endif
