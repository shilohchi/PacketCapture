#ifndef PACKET_DTO_H_
#define PACKET_DTO_H_

#include <QDateTime>
#include <QByteArray>
#include <QString>

using namespace std;

struct PacketDTO {
	int caplen;
	int len;

	QDateTime timestamp;
	QByteArray data;
	QString src_ip;
	QString dst_ip;

	int src_port;
	int dst_port;
	
	QString transport_protocol;
	
	QString task_id;
	QString task_name;

	QString category_id;
	QString category_name;
};

#endif
