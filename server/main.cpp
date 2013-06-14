#include <QSettings>
#include "Server.h"
#include <QApplication>
#include "RequestHandler.h"
#include "DummyHandler.h"
#include "GetConfigHandler.h"
#include "SetConfigHandler.h"
#include <iostream>
#include "GetTaskHandler.h"

using namespace std;

shared_ptr<RequestHandler> createChain() {
	shared_ptr<RequestHandler> head, tail, p;
	head = shared_ptr<RequestHandler>(new GetConfigHandler());
	tail = head;
	
	p = shared_ptr<RequestHandler>(new SetConfigHandler());
	tail->setNext(p);
	tail = p;

	p = shared_ptr<RequestHandler>(new GetTaskHandler());
	tail->setNext(p);
	tail = p;

	p = shared_ptr<RequestHandler>(new DummyHandler());
	tail->setNext(p);
	tail = p;

	return head;
}

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	shared_ptr<RequestHandler> chain = createChain();
	Server* server = new Server(chain);
	server->listen();
	return app.exec();
}
