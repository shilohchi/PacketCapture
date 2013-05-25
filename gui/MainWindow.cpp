#include "MainWindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow() {
	this->setupUi(this);
}

void MainWindow::startPacketProducerThread() {
	if (producer) {
		producer->stop();
	}
	producer = new PacketProducerThread(pool, this);
	connect(&producer->getCounter(), SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));
	connect(&producer->getCounter(), SIGNAL(valueChanged(int)), progressBar, SLOT(setMaximum(int)));
	producer->setInterface(parser.get("interface"));
	producer->setFilter(parser.get("low_level_filter"));
	producer->start();
}

void MainWindow::startPacketConsumerThread() {
	if (consumer) {
		consumer->stop();
	}
	consumer = new PacketConsumerThread(pool, this);
	connect(consumer, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));
	consumer->setDbtype(parser.get("database.dbtype"));
	consumer->setHost(parser.get("database.host"));
	consumer->setUser(parser.get("database.user"));
	consumer->setPassword(parser.get("database.password"));
	consumer->setDbname(parser.get("database.dbname"));
	consumer->start();
}

void MainWindow::on_btnStart_clicked() {
	pool = shared_ptr<PacketPool>(new PacketPool(SIZE));
	startPacketProducerThread();
	startPacketConsumerThread();
}

void MainWindow::on_btnStop_clicked() {
	if (producer) {
		producer->stop();
	}
	if (consumer) {
//		consumer->stop();
	}
}

void MainWindow::closeEvent(QCloseEvent* event) {
	
}
