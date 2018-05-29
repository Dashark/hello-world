#ifndef TIMEFOR_H
#define TIMEFOR_H
#include<iostream>
using namespace std;
class time {
	friend void printtime(time &t);
public:
	time(int hour, int min, int sec);
private:
	int m_hour;
	int m_min;
	int m_sec;

};


#endif