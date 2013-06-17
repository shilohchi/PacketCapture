#ifndef ERRORS_H_
#define ERRORS_H_

#include <stdexcept>

class SqlError : public std::runtime_error {
public:
	SqlError(const char* msg) :
			std::runtime_error(msg) {
	};
};

class UnsupportedDatabaseError : public std::logic_error {
public:
	UnsupportedDatabaseError(const char* msg) :
			std::logic_error(msg) {
	};
};

class UnsupportedOperationError : public std::logic_error {
public:
	UnsupportedOperationError(const char* msg) :
			std::logic_error(msg) {
	}
};

class ValidationError : public std::logic_error {
public:
	ValidationError(const char* msg) :
			std::logic_error(msg) {
	}
};

#endif
