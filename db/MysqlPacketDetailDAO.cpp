#include <iostream>
#include <string>
#include "MysqlPacketDetailDAO.h"
#include <QtSql>
#include "errors.h"
#include "PacketDetail.h"
#include <QString>
#include "ConfigParser.h"

using namespace std;

void MysqlPacketDetailDAO::open() {

	shared_ptr<ConfigParser> parser = ConfigParser::getConfigParser();
	db = QSqlDatabase::addDatabase("QMYSQL");
	string host = boost::any_cast<string>(parser->get("database.host"));
	db.setHostName(host.c_str());
	string user = boost::any_cast<string>(parser->get("database.user"));
	db.setUserName(user.c_str());
	string password = boost::any_cast<string>(parser->get("database.password"));
	db.setPassword(password.c_str());
	string dbname = boost::any_cast<string>(parser->get("database.dbname"));
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
			"application_protocol, task_name) values (:caplen, :len, "
			":timestamp, :data, :src_port, :dst_ip, :src_port, "
			":dst_port, :transport_protocol, :application_protocol, :task_name)";
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
	query.bindValue(":task_name", packet.task_name);
	if (!query.exec()) {
		throw SqlError("failed to insert!");
	}
}
