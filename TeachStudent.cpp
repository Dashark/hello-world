#include <iostream>
using namespace std;
int main() {
	std::cout << "Hello World!" << std::endl;
	for(int i = 0; i < 100; i++)
	  sum += i;
}
class Human {
public:
	virtual void learn() = 0;
	virtual void teach() = 0;
};
class Student:public Human {
public:
	Student() {
	}
	~Student() {
	}
	virtual void learn() {
		//do something
	}
	virtual void teach() {
		//do nothing
	}
};
class Teacher:public Human {
	Human *students[54];
public:
	Teacher() {
		students[0] = new Student();
		students[1] = new Student();
	}
	~Teacher() {
		delete[] students;
	}
	virtual void teach() {
		//do something
	}
	virtual void learn() {
		//do nothing
	}
};
template<class Type1, class Type2>   //General Programming
class Room {    //ÈÝÆ÷ container 
	Type1 *ts1[];
	Type2 *ts2[]
};
int main() {
	Room<Human, Furniture>  classroom;
	Room<Boss, Commidy>   supermarket;
}



