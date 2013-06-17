#ifndef DATALINK_INFO_H_
#define DATALINK_INFO_H_

#include "cxxpcap/cxxpcap_utils.h"

namespace cxxpcap {
class DatalinkInfo {
public:
	virtual Protocol getType() = 0;
	virtual Protocol getProtocol() = 0;
	virtual int getLength() = 0;
};

class EthernetInfo : public DatalinkInfo {
private:
	unsigned char* header;

public:
	static const int LENGTH = 14;
	
	EthernetInfo(const unsigned char* header);
	virtual Protocol getType() override;
	virtual ~EthernetInfo();
	virtual Protocol getProtocol();
	virtual int getLength();
};
}
#endif

