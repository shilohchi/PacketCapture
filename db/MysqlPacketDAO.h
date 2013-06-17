#ifndef MYSQL_PACKET_DAO_H_
#define MYSQL_PACKET_DAO_H_

#include "IPacketDAO.h"
#include <string>
#include <QSqlDatabase>

class MysqlPacketDAO : public IPacketDAO {
private:
	QSqlDatabase db;

public:
	void open() override;

	void close() override;

	void insert(std::shared_ptr<PacketDTO> packet) override;
};

#endif
