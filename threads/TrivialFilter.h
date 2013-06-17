#ifndef TRIVIAL_FILTER_H
#define TRIVIAL_FILTER_H

#include "Filter.h"

class TrivialFilter : public Filter {
public:
	std::shared_ptr<PacketDTO> intercept(std::shared_ptr<cxxpcap::Packet> packet) override;
};

#endif
