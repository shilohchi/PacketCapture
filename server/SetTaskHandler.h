#ifndef SET_TASK_HANDLER_H_
#define SET_TASK_HANDLER_H_

#include "RequestHandler.h"

class SetTaskHandler : public RequestHandler {
	QVariantMap handleRequest(QVariantMap request) override;
};

#endif
