#include <iostream>
#include <string>
#include "MysqlPacketDetailDAO.h"
#include <QtSql>
#include "errors.h"
#include "PacketDetail.h"
#include <QString>

using namespace std;

void MysqlPacketDetailDAO::open(string host, string user, string password, string dbname) {

	this->db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(host.c_str());
	db.setUserName(user.c_str());
	db.setPassword(password.c_str());
	db.setDatabaseName(dbname.c_str());

	if (!db.open()) {
		throw SqlError("Cannot open the database!");	
	}
}

void MysqlPacketDetailDAO::close() {
	this->db.close();
}

void MysqlPacketDetailDAO::insert(const PacketDetail& packet) {
	QString sql = "insert into packets_details ("
			"caplen, len, timestamp, data, src_ip, dst_ip, "
			"src_port, dst_port, transport_protocol, "
			"application_protocol) values (:caplen, :len, "
			":timestamp, :data, :src_port, :dst_ip, :src_port, "
			":dst_port, :transport_protocol, :application_protocol)";
	QSqlQuery query;
	query.prepare(sql);
	query.bindValue(":caplen", packet.caplen);
	query.bindValue(":len", packet.len);
	query.bindValue(":timestamp", packet.timestamp);
	query.bindValue(":data", packet.data);
	query.bindValue(":src_ip", packet.src_ip);
	query.bindValue(":dst_ip", packet.dst_ip);
	query.bindValue(":src_port", packet.src_port);
	query.bindValue(":dst_port", packet.dst_port);
	query.bindValue(":transport_protocol", packet.transport_protocol);
	query.bindValue(":application_protocol", packet.application_protocol);
	if (!query.exec()) {
		throw SqlError("failed to insert!");
	}
}
