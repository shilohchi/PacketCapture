#include "NullFilter.h"
#include "errors.h"

using namespace std;
using namespace cxxpcap;

void NullFilter::setNext(shared_ptr<Filter> filter) {
	throw UnsupportedOperationError("");
}

shared_ptr<PacketDTO> NullFilter::intercept(shared_ptr<Packet> packet) {
	return shared_ptr<PacketDTO>();
}
