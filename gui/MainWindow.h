#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_
#include "ui_MainWindow.h"
#include <QCloseEvent>
#include "CaptureThread.h"
class MainWindow : public QWidget, private Ui_MainWindow {
Q_OBJECT

private:
	shared_ptr<PacketProducerThread> 
public:
	MainWindow();

public slots:

	void closeEvent(QCloseEvent* event) override;
};

#endif
