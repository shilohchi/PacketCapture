#ifndef CXXPCAP_UTILS_H_
#define CXXPCAP_UTILS_H_

#include <string>
#include <stdexcept>

namespace cxxpcap {
enum class Protocol {
	Unknown,
	ARP,
	Ethernet,
	RARP,
	INET,
	IP,
	TCP,
	UDP,
	HTTP
};

class PcapError : public std::runtime_error {
public:
	PcapError(const char* msg) :
			std::runtime_error(msg) {
	}
};

class ValidationError : public std::logic_error {
public:
	ValidationError(const char* msg) :
			std::logic_error(msg) {
	}
};

class PacketError : public std::logic_error {
public:
	PacketError(const char* msg) :
			std::logic_error(msg) {
	}
};

struct NetworkInterface {
	std::string name;
	std::string description;
};
}

#endif
