#ifndef MYSQL_PACKET_DETAIL_DAO_H_
#define MYSQL_PACKET_DETAIL_DAO_H_

#include "IPacketDetailDAO.h"
#include <string>
#include <QSqlDatabase>

class MysqlPacketDetailDAO : public IPacketDetailDAO {
private:
	QSqlDatabase db;

public:
	void open() override;

	void close() override;

	void insert(const PacketDetail& packet) override;
};

#endif
