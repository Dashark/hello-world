#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

/**
 * 定义人类: Person
 */
class Person
{
public:
    Person()
	{
		cout << "Person" << endl;
	}
	~Person()
	{
		cout << "~Person" << endl;
	}
	void eat()
	{
		cout << "eat" << endl;
	}

};

/**
 * 定义工人类: Worker
 * 虚继承人类
 */
class Worker : virtual public Person
{
public:
	Worker(string name)
	{
		m_strName = name;
		cout << "Worker" << endl;
	}
	~Worker()
	{
		cout << "~Worker" << endl;
	}
	void work()
	{
		cout << m_strName << endl;
		cout << "work" << endl;
	}
protected:
	string m_strName;
};

/**
 * 定义儿童类:Children
 * 虚继承人类
 */
class Children : virtual public Person
{
public:
	Children(int age)
	{
		m_iAge = age;
		cout << "Children" << endl;
	}	
	~Children()
	{
		cout << "~Children" << endl;
	}	
	void play()
	{
		cout << m_iAge << endl;
		cout << "play" << endl;
	}
protected:
	int m_iAge;
};

/**
 * 定义童工类：ChildLabourer
 * 公有继承工人类和儿童类
 */
class ChildLabourer:public Worker, public Children
{
public:
	ChildLabourer(string name, int age):Worker(name),Children(age)
	{
		cout << "ChildLabourer" << endl;
	}

	~ChildLabourer()
	{
		cout << "~ChildLabourer" << endl;
	}	
};

int main(void)
{
    // 用new关键字实例化童工类对象
	ChildLabourer *p=new ChildLabourer("fasd",12);
    // 调用童工类对象各方法。
	p->eat();
	p->work();
	p->play();
	delete p;
	p = NULL;

	return 0;
}
