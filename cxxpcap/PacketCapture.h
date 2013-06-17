#ifndef PACKET_CAPTURE_H_
#define PACKET_CAPTURE_H_
#include "cxxpcap/cxxpcap_utils.h"
#include <pcap.h>
#include <string>
#include <vector>
#include <memory>
#include "cxxpcap/Packet.h"

namespace cxxpcap {

class PacketReciever {
public:
	virtual void recievePacket(std::shared_ptr<Packet> packet) = 0;
};

class PacketCapture {
private:
	const static int DEFAULT_SNAPLEN = 96;

	const static int DEFAULT_TIMEOUT = 1000;
	
	static char errbuf[PCAP_ERRBUF_SIZE];
	
	struct bpf_program fcode;

	std::string device;
	
	pcap_t* capture = NULL;

	std::vector<std::shared_ptr<PacketReciever>> recievers;

public:
	static std::shared_ptr<std::vector<NetworkInterface> > findAllDevices();
	
	PacketCapture();
	
	PacketCapture(const PacketCapture&) = delete;
	
	PacketCapture& operator=(const PacketCapture&) = delete;
	
	Protocol getDatalinkType();
	
	void setFilter(std::string filter);
	
	void addHandler(std::shared_ptr<PacketReciever> reciever);

	void fireEvent(std::shared_ptr<Packet> packet);

	void removeAllHandlers();

	void open(std::string device, bool promisc = 1, int snaplen = DEFAULT_SNAPLEN, int timeout = DEFAULT_TIMEOUT);
	
	void start(int count = -1);

	void stop();

	void close();
};
}

#endif
