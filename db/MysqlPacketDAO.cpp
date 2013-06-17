#include <iostream>
#include <string>
#include "MysqlPacketDAO.h"
#include <QtSql>
#include "errors.h"
#include "PacketDTO.h"
#include <QString>
#include <QSettings>

using namespace std;

void MysqlPacketDAO::open() {
	QSettings settings("config/config.ini", QSettings::IniFormat);
	settings.setIniCodec("UTF-8");

	db = QSqlDatabase::addDatabase("QMYSQL");
	string host = settings.value("database/host").toString().toStdString();
	db.setHostName(host.c_str());
	string user = settings.value("database/user").toString().toStdString();
	db.setUserName(user.c_str());
	string password = settings.value("database/password").toString().toStdString();
	db.setPassword(password.c_str());
	string dbname = settings.value("database/dbname").toString().toStdString();
	db.setDatabaseName(dbname.c_str());

	if (!db.open()) {
		throw SqlError("Cannot open the database!");	
	}
}

void MysqlPacketDAO::close() {
	this->db.close();
}

void MysqlPacketDAO::insert(shared_ptr<PacketDTO> packet) {
	QString sql = "insert into packets_details ("
			"caplen, len, timestamp, data, src_ip, dst_ip, "
			"src_port, dst_port, transport_protocol, "
			"task_id, task_name, category_id, category_name) values (:caplen, :len, "
			":timestamp, :data, :src_ip, :dst_ip, :src_port, :dst_port, "
			":transport_protocol, :task_id, :task_name, :category_id, :category_name)";
	QSqlQuery query;
	query.prepare(sql);
	query.bindValue(":caplen", packet->caplen);
	query.bindValue(":len", packet->len);
	query.bindValue(":timestamp", packet->timestamp);
	query.bindValue(":data", packet->data);
	query.bindValue(":src_ip", packet->src_ip);
	query.bindValue(":dst_ip", packet->dst_ip);
	query.bindValue(":src_port", packet->src_port);
	query.bindValue(":dst_port", packet->dst_port);
	query.bindValue(":transport_protocol", packet->transport_protocol);
	query.bindValue(":task_id", packet->task_id);
	query.bindValue(":task_name", packet->task_name);
	query.bindValue(":category_id", packet->category_id);
	query.bindValue(":category_name", packet->category_name);
	if (!query.exec()) {
		throw SqlError("failed to insert!");
	}
	cout << packet->src_ip.toStdString() << " -> " << packet->dst_ip.toStdString() <<
			": " << packet->transport_protocol.toStdString() << endl;
}
