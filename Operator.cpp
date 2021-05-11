#include <iostream>
class Parent {
public:
  Parent(int n) {
  	flag = n;
  	std::cout << "Parent()" << flag << std::endl;
  }
  virtual ~Parent(){
  	std::cout << "~~~Parent()" << flag << std::endl;
  }
  //other methods????
  void show();
private:
  //attributes??
  int flag;
};
class Child : public Parent {
public:
  Child(int n):Parent(n) {
  	flag = n;
  	std::cout << "Child()" << n << std::endl;
  }
  virtual ~Child(){
  	std::cout << "~~~Child()" << flag << std::endl;
  }
  //other methods????
  //function object 
  void operator() (int n) {
  }
private:
  //attributes??
  int flag;
  void operator= (const Child &c) {
  	std::cout << "operator = " << flag << std::endl;
  }
};
int main() {
  Parent *p;
  p = new Child(1);
  Child c(2);
  //c = Child(3);
  //p->?????();
  delete p;
  return 0;
}
