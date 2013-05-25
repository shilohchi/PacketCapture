#include "patch.h"

using namespace std;

namespace patch {
string to_string(int num) {
	string r = "";
	while (num != 0) {
		r.push_back(num % 10 + '0');
		num /= 10;
	}
	string t = "";
	for (int i = r.length() - 1; i >=0; i--) {
		t.push_back(r[i]);
	}
	return t;
}
}
