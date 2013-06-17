#include "Server.h"
#include <parser.h>
#include <serializer.h>
#include <iostream>
#include <QSettings>
#include "assert_ex.h"

using namespace std;

Server::Server(shared_ptr<RequestHandler> handler, QObject* parent) {
	this->handler = handler;
	connect(server, SIGNAL(newConnection()), this, SLOT(on_newConnection()));
}

void Server::listen() {
	QSettings config("config/config.ini", QSettings::IniFormat);
	QHostAddress addr;
	bool ret = addr.setAddress(config.value("server/host").toString());
	assert_ex(ret, "需要合法的ip");
	int port = config.value("server/port").toInt();
	server->listen(addr, port);
}

void Server::on_newConnection() {
	socket = server->nextPendingConnection();
	cout << "connected from " << socket->peerAddress().toString().toStdString() << endl;
	connect(socket, SIGNAL(readyRead()), this, SLOT(on_readyRead()));
}

void Server::on_readyRead() {
	QJson::Parser parser;
	QJson::Serializer serializer;
	bool ok;
	while (socket->canReadLine()) {
		// exit命令断开连接
		QByteArray ba = socket->readLine();
		if (ba == "exit\r\n") {
			socket->disconnectFromHost();
			return;
		}
		cout << ba.data();

		QVariantMap request = parser.parse(ba, &ok).toMap();
		if (ok) {		// 请求必须为合法的json格式
			QVariantMap response = handler->handleRequest(request);
			QByteArray data = serializer.serialize(response);
			socket->write(data);
			socket->write("\r\n");
		} else {
			QVariantMap response;
			response["status"] = "error";
			response["msg"] = QString::fromUtf8("请求必须为合法的json格式");
		}
	}
}

void Server::on_disconnected() {
	cout << "disconnected .." << endl;
}

