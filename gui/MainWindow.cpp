#include "MainWindow.h"
#include <iostream>
#include "CaptureThread.h"

using namespace std;

MainWindow::MainWindow() {
	this->setupUi(this);
	connect(btnStart, SIGNAL(clicked()), this, SLOT(showinfo()));	
}

void MainWindow::showinfo() {
	if (capture) {
		capture = new CaptureThread();
		capture->start();
	}
}

void MainWindow::closeEvent(QCloseEvent* event) {
	delete capture;
}
