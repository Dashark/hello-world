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
void show(const Parent &p) {  //πÊ‘Ú 
	p.show();
} 

int main() {
	Parent p;
	show(p);
	Child c;
	show(c);
	//GrandChild gc;
	//show(gc);
	return 0;
}
