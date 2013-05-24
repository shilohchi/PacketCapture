#include <boost/thread.hpp>
#include <iostream>
#include <cstdlib>
#include <boost/chrono.hpp>

using namespace std;

void disp() {
	while (true) {
		cout << "fuck" << endl;
		boost::this_thread::sleep_for(boost::chrono::seconds(1));
	}
}

void cnt(boost::thread* thrd) {
	for (int i = 0; i < 100; i++) {
		cout << i << endl;
		if (i == 5) {
			thrd->interrupt();
			break;
		}
		boost::this_thread::sleep_for(boost::chrono::seconds(1));

	}
}

int main() {
	boost::thread printer(disp);

	boost::thread counter(cnt, &printer);
	printer.join();
	counter.join();
}
