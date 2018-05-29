#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<string>
using namespace std;

class customer {
public:
	customer(string name="", int age=0);
	void printinfo()const;
private:
	string m_strname;
	int m_age;

};




#endif
