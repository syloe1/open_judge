#include "Proxy.h"
#include <iostream>
Proxy::Proxy() {
	subject = new RealSubject();
}

void
Proxy::request() {
	std::cout<<"function proxy"<<std::endl;
	subject->request();
}

Proxy::~Proxy() {
	delete subject;
}