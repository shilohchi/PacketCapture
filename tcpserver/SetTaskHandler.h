#ifndef SET_TASK_HANDLER_H_
#define SET_TASK_HANDLER_H_

#include "RequestHandler.h"

class SetTaskHandler : public RequestHandler {
protected:
	bool validate(QVariantMap task);

public:
	QVariantMap handleRequest(QVariantMap request) override;
};

#endif
