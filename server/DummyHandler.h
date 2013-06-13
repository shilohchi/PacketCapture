#ifndef DUMMY_HANDLER_H_
#define DUMMY_HANDLER_H_

#include "RequestHandler.h"

class DummyHandler : public RequestHandler {
public:
	QVariantMap handleRequest(QVariantMap request) override;

	void setNext(std::shared_ptr<RequestHandler> handler) override;
};

#endif
