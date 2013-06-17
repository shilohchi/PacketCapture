#ifndef TASK_FILTER_H_
#define TASK_FILTER_H_

#include "Filter.h"
#include "PacketDTO.h"
#include <cxxpcap/Packet.h>

class TaskFilter : public Filter {
protected:
	bool validate(std::shared_ptr<cxxpcap::Packet> packet);

public:
	std::shared_ptr<PacketDTO> intercept(std::shared_ptr<cxxpcap::Packet> packet) override;
};

#endif
