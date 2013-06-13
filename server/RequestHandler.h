#ifndef REQUEST_HANDLER_H_
#define REQUEST_HANDLER_H_
#include <memory>
#include <QVariant>

class RequestHandler {
protected:
	std::shared_ptr<RequestHandler> next;

public:
	virtual QVariantMap handleRequest(QVariantMap request) = 0;

	virtual void setNext(std::shared_ptr<RequestHandler> handler);
};

#endif
