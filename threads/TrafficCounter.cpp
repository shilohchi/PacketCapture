#include "TrafficCounter.h"
#include <stdexcept>
#include <climits>

using namespace cxxpcap;
using namespace std;

void TrafficCounter::recievePacket(std::shared_ptr<const cxxpcap::Packet> packet) {
	count++;
	if (count == INT_MAX) {
		throw std::out_of_range("too many packets captured.");
	}
	emit valueChanged(count);
}

