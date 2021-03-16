#include <iostream>
#include <stdio.h>
#include <string.h>
class MyStruct {
public:
	char hello[50];
	char name[50];
	MyStruct(char h[], char n[]) {
		strcpy(hello, h);
		strcpy(name, n);
	}
	int myfunction() {
		std::cout << name << "   "<< hello << std::endl;
		printf("%s   %s\n", name, hello);
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
