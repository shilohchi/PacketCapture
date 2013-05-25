#include "MainWindow.h"
#include <QApplication>
#include <string>
#include <cxxpcap/cxxpcap.h>
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>

using namespace cxxpcap;
using namespace std;

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	if (argc == 2 && string(argv[1]) == "-l") {
		auto interfaces = PacketCapture::findAllDevices();
		for (int i = 0; i < interfaces->size(); i++) {
			cout << interfaces->at(i).name << endl;
		}
		exit(0);
	}
	MainWindow w;
	w.show();
	app.exec();
}
