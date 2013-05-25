#include "PacketConsumerThread.h"
#include "PacketDetailDAOFactory.h"
#include <cxxpcap/cxxpcap.h>

using namespace std;
using namespace cxxpcap;

PacketConsumerThread::PacketConsumerThread(shared_ptr<PacketPool>  pool, QObject* parent) : 
		QThread(parent) {
	this->pool = pool;	
}

void PacketConsumerThread::setDbtype(string dbtype) {
	this->dbtype = dbtype;
}

void PacketConsumerThread::setHost(string host) {
	this->host = host;
}

void PacketConsumerThread::setPassword(string password) {
	this->password = password;
}


void PacketConsumerThread::setUser(string user) {
	this->user = user;
}

void PacketConsumerThread::setDbname(string dbname) {
	this->dbname = dbname;
}

void PacketConsumerThread::stop() {
	this->stopping = true;
}

void PacketConsumerThread::run() {
	shared_ptr<IPacketDetailDAO> dao = PacketDetailDAOFactory::getPacketDetailDAO(dbtype);
	dao->open(host, user, password, dbname);

	while (!stopping) {
		shared_ptr<const Packet> packet = pool->take();
		
		PacketDetail detail;
		if (shared_ptr<const IPPacket> inetpkt = dynamic_pointer_cast<const IPPacket>(packet)) {
			detail.caplen = inetpkt->getLength();
			detail.len = inetpkt->raw_data_length();
			detail.src_ip = inetpkt->getSourceIP().c_str();
			detail.dst_ip = inetpkt->getDestinationIP().c_str();

			long long sec = inetpkt->getTimestamp().tv_sec;
			long long usec = inetpkt->getTimestamp().tv_usec;
			long long msecs = sec * 1000 + usec / 1000;
			detail.timestamp = QDateTime::fromMSecsSinceEpoch(msecs);

			for (int i = 0; i < inetpkt->raw_data_length(); i++) {
				detail.data[i] = inetpkt->raw_data_begin()[i];
			}

			if (shared_ptr<const TCPPacket> tcppkt = dynamic_pointer_cast<const TCPPacket>(packet)) {
				detail.transport_protocol = "tcp";
				detail.src_port = tcppkt->getSourcePort();
				detail.dst_port = tcppkt->getDestinationPort();
			} else if (shared_ptr<const UDPPacket> udppkt = dynamic_pointer_cast<const UDPPacket>(packet)) {
				detail.transport_protocol = "udp";
				detail.src_port = udppkt->getSourcePort();
				detail.dst_port = udppkt->getDestinationPort();
			} else {
			}
		}
		dao->insert(detail);

		count++;		
		emit valueChanged(count);
	}

	dao->close();
}
