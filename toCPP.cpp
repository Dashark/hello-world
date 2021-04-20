#include <iostream>
#include <string>
class MyStruct {
public:
	std::string hello;
	std::string name;
	MyStruct(char h[], char n[]):name(n), hello(h) {
	}
	int myfunction() {
		std::cout << name << "   "<< hello << std::endl;
		return 10;
	}
}; 
int main()
{
	MyStruct myobj("Hello World!", "DaShark");
	MyStruct myobj1("HAHAHAHA!", "DaShark");
	// call my object's method
	myobj.myfunction();
	myobj1.myfunction();
	return 0;
} 
