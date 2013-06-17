#ifndef PC_SERVER_H_
#define PC_SERVER_H_

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "RequestHandler.h"
#include "memory"

class Server : public QObject {
Q_OBJECT

private:
	QTcpServer* server = new QTcpServer(this);

	QTcpSocket* socket;

	std::shared_ptr<RequestHandler> handler;

public:
	Server(std::shared_ptr<RequestHandler> handler, QObject* parent = 0);

	void listen();

public slots:
	void on_newConnection();	

	void on_readyRead();

	void on_disconnected();
};

#endif
