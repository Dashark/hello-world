#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
#include"myqueue.h"


myqueue::myqueue(int queuecapacity) {
	m_queuecapacity = queuecapacity;
	m_ihead = 0;
	m_pqueue = new customer[m_queuecapacity];
	 m_tail = 0;
	 m_queuelen = 0;
}


void myqueue::clearqueue() {
	m_ihead = 0;
	m_tail = 0;
	m_queuelen = 0;
}

bool myqueue::queueempty()const {
	if (m_queuelen == 0) {
		return true;
	}
	else {
		return false;
	}
}
int myqueue::queuelength()const {
	return m_queuelen;
}

bool myqueue::queuefull() const {
	if (m_queuelen == m_queuecapacity) {
		return true;
	}
	else {
		return false;
	}
}

bool myqueue::enqueue(customer  element) {
	if (queuefull()) {
		return false;

	}
	else {
		m_pqueue[m_tail] = element;
		m_tail++;
		m_tail = m_tail % m_queuecapacity;
		m_queuelen++;
		return true;
	}
}
bool myqueue::dequeue(customer &element) {
	if (queueempty()) {
		return false;
	}
	else {
		element = m_pqueue[m_ihead];
		m_ihead++;
		m_ihead = m_ihead % m_queuecapacity;
		m_queuelen--;
		return true;
	}
}
void myqueue::queuetraverse() {
	
	for (int i = m_ihead; i < m_queuelen+m_ihead; i++) {
		 m_pqueue[i%m_queuecapacity].printinfo();
		 cout << (i - m_ihead) << "    person waiting..." << endl;

	}
}

myqueue::~myqueue(){
	delete[]m_pqueue;
m_pqueue = NULL;
}