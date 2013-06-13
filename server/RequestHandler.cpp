#include "RequestHandler.h"
using namespace std;

void RequestHandler::setNext(shared_ptr<RequestHandler> next) {
	this->next = next;
}
