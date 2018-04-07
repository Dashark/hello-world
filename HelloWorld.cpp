#include "HelloWorld.h"
#include <iostream>

void HelloWorld::hello() {
  std::cout << "Hello World!" << std::endl;
}


int main(){
	HelloWorld w;
	w.hello();
	return 0;
}
