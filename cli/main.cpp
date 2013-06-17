#include "CliServer.h"
#include "QApplication"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	CliServer server;
	server.start();
	return app.exec();
}
