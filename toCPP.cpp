#include <iostream>
#include <stdio.h>
struct MyStruct {
	char hello[50];
	char name[50];
	int myfunction() {
		std::cout << name << "   "<< hello << std::endl;
		printf("%s   %s\n", name, hello);
		return 10;
	}
}; 
int main()
{
	struct MyStruct myobj = {
    	"Hello World!",
	    "DaShark"
	};
	// call my function
	return myobj.myfunction();
} 
