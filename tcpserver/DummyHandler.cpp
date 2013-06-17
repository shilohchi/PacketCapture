#include "DummyHandler.h"
#include <stdexcept>
using namespace std;
QVariantMap DummyHandler::handleRequest(QVariantMap request) {
	QVariantMap response;
	response["status"] = "error";
	response["msg"] = QString::fromUtf8("未知请求");
	return response;
}

void DummyHandler::setNext(shared_ptr<RequestHandler> handler) {
	throw logic_error("unsupported operation.");
}
