#include "Server.h"
#include <parser.h>
#include <serializer.h>
#include <iostream>

using namespace std;

Server::Server(shared_ptr<RequestHandler> handler, QObject* parent) {
	this->handler = handler;
	connect(server, SIGNAL(newConnection()), this, SLOT(on_newConnection()));
}

void Server::listen() {
	server->listen(QHostAddress::LocalHost, 1234);
}

void Server::on_newConnection() {
	socket = server->nextPendingConnection();
	cout << "connected .." << endl;
	DLOG(INFO) << "kdjf FUCK";
	connect(socket, SIGNAL(readyRead()), this, SLOT(on_readyRead()));
	DLOG(INFO) << "FUCK";
}

void Server::on_readyRead() {
/*
	QJson::Parser parser;
	QJson::Serializer serializer;
	bool ok = false;
	while (socket->canReadLine()) {
		QByteArray ba = socket->readLine();
		if (ba == "exit\r\n") {
			socket->disconnectFromHost();
			return;
		}
		cout << ba.data() << endl;

		QVariantMap request = parser.parse(ba, &ok).toMap();
		if (ok) {
			QVariantMap response = handler->handleRequest(request);
			QByteArray data = serializer.serialize(response);
			socket->write(data);
			socket->write("\r\n");
		} else {
			cout << "error json format!!!";
		}
	}
	*/
}

void Server::on_disconnected() {
	cout << "disconnected .." << endl;
}
