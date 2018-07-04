#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	void get_value()
	{
		cin >> num >> name >> sex;
	}
	void display()
	{
		cout << "num: " << num << endl;
		cout << "name: " << name << endl;
		cout << "sex: " << sex << endl; 
	}
private:
		int num;
		string name;
		char sex;
};

class Student1:public Student
{
public:
	void get_value_1()
	{
		cin >> age >> addr;
	}
	void display1()
	{
		//cout << " num: " << num << endl;
		//cout << " name: " << name << endl;
		//cout << " sex: " << sex << endl;
		cout << " age: " << age << endl;
		cout << " address: " << addr << endl;
	}
	private:
		int age;
		string addr;
};
/*int main ()
{
	Student1 stud;
	stud.get_value();
	stud.get_value_1();
	stud.display();
	stud.display1();
	return 0;
 }*/ 
#include"p198_1.cpp"
class Student2:private Student
{public:
	void get_value_2()
	{
		get_value();
		cin >> age1 >> addr1; 
	}
	void display_2()
	{
		display();
		cout << "age: " << age1 << endl;
		cout << "address: " << addr1 << endl;
	}
 private:
 	int age1;
 	string addr1;
		
};
int main()
{
	Student2 stud1;
	stud1.get_value_2();
	//stud1.display();
	stud1.display_2();
	//stud1.age1=18;
	return 0;
}
