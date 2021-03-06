#include "cxxpcap/PacketCapture.h"
#include <pcap.h>
#include <vector>
#include <string>
#include "cxxpcap/cxxpcap_utils.h"
#include "cxxpcap/PacketFactory.h"

using namespace std;

namespace cxxpcap {


char PacketCapture::errbuf[PCAP_ERRBUF_SIZE];

PacketCapture::PacketCapture() {
	capture = NULL;
}

shared_ptr<vector<NetworkInterface> > PacketCapture::findAllDevices() {
	shared_ptr<vector<NetworkInterface> > pv(new vector<NetworkInterface>());

	pcap_if_t* alldevs;
	if (pcap_findalldevs(&alldevs, errbuf) == -1) {
		throw PcapError(errbuf);
	}
	for(pcap_if_t* d = alldevs; d != NULL; d = d->next) {
		NetworkInterface netinterface = {
			d->name ? d->name : "",
			d->description ? d->description : ""
		};
		string s = netinterface.name;
		pv->push_back(netinterface);
	}
	pcap_freealldevs(alldevs);
	return pv;
}

void PacketCapture::setFilter(string filter) {
	bpf_u_int32 net, mask;

	if (pcap_lookupnet(this->device.c_str(), &net, &mask, errbuf) == -1) {
		throw PcapError(errbuf);
	}
	
	if (pcap_compile(this->capture, &this->fcode, filter.c_str(), 1, mask) == -1) {
		throw PcapError(errbuf);
	}

	if (pcap_setfilter(this->capture, &this->fcode) == -1) {
		throw PcapError(errbuf);
	}
}

void PacketCapture::open(string device, bool promiscuous, int snaplen, int timeout) {
	if ((this->capture = pcap_open_live(device.c_str(), snaplen, promiscuous, timeout, NULL)) == NULL) {
		throw PcapError(errbuf);
	}
	this->device = device;
}

void PacketCapture::close() {
	if (this->capture) {
		pcap_close(this->capture);
	}
	this->capture = NULL;
}

void PacketCapture::addHandler(shared_ptr<PacketReciever> reciever) {
	recievers.push_back(reciever);
}

void PacketCapture::fireEvent(shared_ptr<Packet> packet) {
	if (!recievers.empty()) {
		for (auto reciever: recievers) {
			reciever->recievePacket(packet);
		}
	}
}

void PacketCapture::removeAllHandlers() {
	recievers.clear();
}

Protocol PacketCapture::getDatalinkType() {
	Protocol protocol = Protocol::Unknown;

	switch (pcap_datalink(this->capture)) {
	case DLT_EN10MB:
		protocol = Protocol::Ethernet;
		break;
	default:
		protocol = Protocol::Unknown;
	}

	return protocol;
}

void PacketCapture::start(int count) {
	auto callback = [] (uint8_t* params, const struct pcap_pkthdr* header, const uint8_t* raw_data) {
		PacketCapture* pktcap = (PacketCapture*) params;
		shared_ptr<Packet> packet = PacketFactory::createPacket(header->len, header->ts,
				raw_data, header->caplen, pktcap->getDatalinkType());
		pktcap->fireEvent(packet);	
	};

	if (pcap_loop(this->capture, count, callback, (uint8_t*) this) == -1) {
		throw PcapError("Failed to start capturing.");
	}
}

void PacketCapture::stop() {
	if (this->capture) {
		pcap_breakloop(this->capture);
	}
}

}
