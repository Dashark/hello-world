#include<iostream>
#include<cstring>
#include<cstdlib>
#include"myqueue.h"
#include"customer.h"
//队列  先进先出 有内存限制
//向前进位    对头指针改变
//普通队列内存浪费  
//改用环形队列 队列头  队列尾
//顺时针  逆时针  指针


using namespace std;


int main() {
	/*myqueue *p = new myqueue(4);
	p->enqueue(12);
	p->enqueue(100);
	p->enqueue(199);
	p->enqueue(122);
	

	p->queuetraverse();
	int e = 0;
	p->dequeue(e);
	cout << e << endl;
	p->dequeue(e);
	cout << e << endl;

	p->queuetraverse();//遍历存在问题
	cout << "clear" << endl;
	p->clearqueue();
	p->queuetraverse();
	p->enqueue(2002);
	p->enqueue(1998);
	p->queuetraverse();
	int i = p->queuelength();
	cout << i << endl;
	delete p;
	p = NULL;*/
	myqueue *p =new myqueue(4);
	customer c1("zhangsan", 20);
	customer c2("zhangsan1", 21);
	customer c3("zhangsan2", 19);

	p->enqueue(c1);
	p->enqueue(c2);
	p->enqueue(c3);
	p->queuetraverse();

	customer c4;
	p->dequeue(c4);
	c4.printinfo();
	

	system("pause");
	return 0;
}