#ifndef GET_DEVICES_HANDLER_H_
#define GET_DEVICES_HANDLER_H_

#include "RequestHandler.h"

class GetDevicesHandler : public RequestHandler {
public:
	QVariantMap handleRequest(QVariantMap request);
};

#endif

