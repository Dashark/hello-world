#include <iostream>
using namespace std;
class Parent {
public:
  virtual void show() const {   //∂‡Ã¨ 
  	cout << "Parent!!!" << endl;
  }
};
class Child:public Parent {
public:
  virtual void show() const {
  	cout << "Child!!!" << endl;
  }
};
void show(const Parent &p) {
	p.show();
} 
int main() {
	Child c;
	show(c);
	Parent p;
	show(p)
	return 0;
}
