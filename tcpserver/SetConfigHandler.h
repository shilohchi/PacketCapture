#ifndef SET_CONFIG_HANDLER_H_
#define SET_CONFIG_HANDLER_H_

#include "RequestHandler.h"

class SetConfigHandler : public RequestHandler {
public:
	QVariantMap handleRequest(QVariantMap request) override;
};

#endif
