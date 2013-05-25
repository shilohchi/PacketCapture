#ifndef TRAFFIC_COUNTER_H_
#define TRAFFIC_COUNTER_H_

#include <memory>
#include <QObject>
#include <cxxpcap/cxxpcap.h>

class TrafficCounter : public QObject, public cxxpcap::PacketReciever {
Q_OBJECT

private:
	int count = 0;

public:
	void recievePacket(std::shared_ptr<const cxxpcap::Packet> packet);


signals:
	void valueChanged(int);
};

#endif
		
