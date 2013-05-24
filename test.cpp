#include <memory>
#include <iostream>
#include <map>
#include <boost/any.hpp>
#include <vector>
#include <QThread>
#include <string>
#include <cxxpcap/cxxpcap.h>

using namespace std;


int main() {
	shared_ptr<PacketReciever> h(new Handler());
	PacketCapture capture;
	capture.open("eth0");
	capture.addHandler([] (shared_ptr<const Packet> a) {
		cout << "fun version" << endl;
	});
	
	capture.addHandler(h);
	capture.start();
	capture.close();
	capture.stop();
}	
