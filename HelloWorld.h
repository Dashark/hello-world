#ifndef _HELLO_WORLD_
#define _HELLO_WORLD_
#include<iostream>
using namespace std;
class HelloWorld {
 public:
  void hello(); 
};
HelloWorld::hello(){
 cout<<"HelloWorld"<<endl;
}
int main(){
HelloWorld hw;
 hw.hello();
 return 0;
}
#endif
