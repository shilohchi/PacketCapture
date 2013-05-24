#include "PacketPool.h"
#include <iostream>

using namespace std;

int main() {
	shared_ptr<PacketPool> pool(new PacketPool(1000));

	PacketProducerThread p(pool);
	p.setInterface("eth0");
	p.start();

	PacketConsumerThread c(pool);
	c.setDbtype("mysql");
	c.setHost("172.20.52.173");
	c.setUser("qi");
	c.setPassword("qi");
	c.start();

	p.wait();
	c.wait();
}
