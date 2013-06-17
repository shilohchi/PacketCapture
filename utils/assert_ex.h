#ifndef SC_ASSERT_EX_H_ 
#define SC_ASSERT_EX_H_

#include <stdexcept>

class AssertError : public std::logic_error {
public:
	AssertError(const char* msg) :
			std::logic_error(msg) {
	}
};

inline void assert_ex(bool expression, const char* msg = "") {
	if (!expression) {
		throw AssertError(msg);
	}
}

template <class E> void assert_ex(bool expression, E e) {
	if (!expression) {
		throw e;
	}
}
#endif
