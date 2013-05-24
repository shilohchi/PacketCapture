#ifndef TRAFFIC_COUNTER_H_
#define TRAFFIC_COUNTER_H_

#include <memory>
#include <cxxpcap/cxxpcap.h>
#include <QObject>
#include <climits>
#include <stdexcept>

class TrafficCounter : public QObject, public cxxpcap::PacketReciever {
Q_OBJECT

private:
	int count = 0;

public:
	void recievePacket(std::shared_ptr<const cxxpcap::Packet> packet) {
		count++;
		if (count == INT_MAX) {
			throw std::out_of_range("too many packets captured.");
		}
		emit valueChanged(count);
	}

signals:
	void valueChanged(int);
};

#endif
		
