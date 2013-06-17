#include "GetDevicesHandler.h"
#include <cxxpcap/cxxpcap.h>

using namespace cxxpcap;
using namespace std;
QVariantMap GetDevicesHandler::handleRequest(QVariantMap request) {
	if (request["target"] != "get_devices") {
		return next->handleRequest(request);
	}
	
	QVariantList result;
	shared_ptr<vector<NetworkInterface>> devices = PacketCapture::findAllDevices();
	for (int i = 0; i < devices->size(); i++) {
		result.append(devices->at(i).name.c_str());
	}

	QVariantMap response;
	request["status"] = "ok";
	request["devices"] = result;
	return request;
}
