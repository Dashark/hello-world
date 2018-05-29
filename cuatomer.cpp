#include"customer.h"
#include<iostream>
using namespace std;
customer::customer(string name, int age) {
	m_age = age;
	m_strname = name;

}

void customer::printinfo()const {
	cout << "ÐÕÃû£º" << m_strname << endl;
	cout << "ÄêÁä£º" << m_age << endl;
	cout << endl;
}
