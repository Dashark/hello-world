#include <iostream>
#include <stdio.h>
struct MyStruct {
	char hello[50];
	char name[50];
	int myfunction(struct MyStruct* myinfo) {
		std::cout << myinfo->name << "   "<< myinfo->hello << std::endl;
		printf("%s   %s\n", myinfo->name, myinfo->hello);
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
	return myobj.myfunction(&myobj);
} 
