#include "CliServer.h"
#include "GetConfigHandler.h"
#include "SetConfigHandler.h"
#include "GetDevicesHandler.h"
#include "GetStatsHandler.h"
#include "GetTaskHandler.h"
#include "SetTaskHandler.h"
#include "StartCaptureHandler.h"
#include "StopCaptureHandler.h"
#include "DummyHandler.h"

using namespace std;

CliServer::CliServer() {
	shared_ptr<RequestHandler> handler = createHandlerChain();
	server = new Server(handler, this);
}

void CliServer::start() {
	if (server) {
		server->listen();
	}
}

shared_ptr<RequestHandler> CliServer::createHandlerChain() {
	shared_ptr<RequestHandler> head, tail, p;

	// 获取配置
	p = shared_ptr<RequestHandler>(new GetConfigHandler());
	head = p;
	tail = p;

	// 设置配置
	p = shared_ptr<RequestHandler>(new SetConfigHandler());
	tail->setNext(p);
	tail = p;
	
	// 获取网卡
	p = shared_ptr<RequestHandler>(new GetDevicesHandler());
	tail->setNext(p);
	tail = p;

	// 获取统计数据
	p = shared_ptr<RequestHandler>(new GetStatsHandler(&this->producer, &this->consumer));
	tail->setNext(p);
	tail = p;

	// 获取任务配置
	p = shared_ptr<RequestHandler>(new GetTaskHandler());
	tail->setNext(p);
	tail = p;

	// 设置任务
	p = shared_ptr<RequestHandler>(new SetTaskHandler());
	tail->setNext(p);
	tail = p;

	// 开始抓包
	p = shared_ptr<RequestHandler>(new StartCaptureHandler(&this->producer, &this->consumer));
	tail->setNext(p);
	tail = p;

	// 停止抓包
	p = shared_ptr<RequestHandler>(new StopCaptureHandler(&this->producer));
	tail->setNext(p);
	tail = p;

	// 错误请求处理
	p = shared_ptr<RequestHandler>(new DummyHandler());
	tail->setNext(p);
	tail = p;

	return head;
}
