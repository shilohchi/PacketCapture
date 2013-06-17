#ifndef NULL_FILTER_H_
#define NULL_FILTER_H_

#include "Filter.h"

class NullFilter : public Filter {
public:
	std::shared_ptr<PacketDTO> intercept(std::shared_ptr<cxxpcap::Packet> packet) override;

	void setNext(std::shared_ptr<Filter> filter) override;
};

#endif
