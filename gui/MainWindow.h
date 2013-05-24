#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_
#include "ui_MainWindow.h"
#include <QCloseEvent>
#include "PacketProducerThread.h"
#include "PacketConsumerThread.h"
#include "PacketPool.h"
#include <memory>

class MainWindow : public QWidget, private Ui_MainWindow {
Q_OBJECT

private:
	const static int SIZE = 2000;

	std::shared_ptr<PacketPool> pool;

	PacketProducerThread* producer = NULL;

	PacketConsumerThread* consumer = NULL;

public:
	MainWindow();

protected:
	void startPacketProducerThread();

	void startPacketConsumerThread();

public slots:
	void on_btnStart_clicked();

	void on_btnStop_clicked();

	void closeEvent(QCloseEvent* event) override;
};

#endif
