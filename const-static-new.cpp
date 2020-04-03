#include <iostream>
class AnyThing {
  private:
  	static int count;  //对象计数器 
  	const int things;
  	AnyThing() : things(0) {       //私有化构造函数 
  	  count += 1;
	}
  public:
	~AnyThing() {
	  count -= 1;
	}
	static void show() {
	  std::cout << "How many Object: " << count << std::endl;
	}
	void show(int i) const {
	  std::cout << "How many Object: " << count << std::endl;
	  //things += i;
	}
	static AnyThing * create() {    //工厂方法设计模式 
	  return new AnyThing();
	}
	static AnyThing * createGroup(int n) {    //工厂方法设计模式 
	  return new AnyThing[n];
	}
};
int AnyThing::count = 0;
int main() {
   const AnyThing *p = AnyThing::create();
   AnyThing *pp = AnyThing::createGroup(10);
   p->show();
   delete p;
   AnyThing::show();
   delete[] pp;
   AnyThing::show(); 
   return 0; 
}
