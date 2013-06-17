#ifndef GET_CONFIG_HANDLER_H_
#define GET_CONFIG_HANDLER_H_

#include "RequestHandler.h"

class GetConfigHandler : public RequestHandler {
public:
	QVariantMap handleRequest(QVariantMap request) override;
};

#endif
