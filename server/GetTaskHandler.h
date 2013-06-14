#ifndef GET_TASK_HANDLER_H_
#define GET_TASK_HANDLER_H_

#include "RequestHandler.h"

class GetTaskHandler : public RequestHandler {
public:
	QVariantMap handleRequest(QVariantMap request) override;
};

#endif
