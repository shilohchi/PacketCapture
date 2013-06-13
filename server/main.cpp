#include "Server.h"
#include <QApplication>
#include "RequestHandler.h"
#include "DummyHandler.h"
#include "GetConfigHandler.h"

using namespace std;

shared_ptr<RequestHandler> createChain() {
	shared_ptr<RequestHandler> head(new GetConfigHandler());
	head->setNext(shared_ptr<RequestHandler>(new DummyHandler()));
}

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	shared_ptr<RequestHandler> chain = createChain();
	Server* server = new Server(chain);
	server->listen();
	return app.exec();
}
