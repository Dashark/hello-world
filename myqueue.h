#ifndef MYQUEUE_H
#define MYQUEUE_H

#include"customer.h"
class myqueue {
public:
	myqueue(int queuecapacity); //创建队列
	virtual ~myqueue();//销毁队列
	void clearqueue();//清空队列
	bool queueempty() const;//判断是否为空
	bool queuefull() const;
	int queuelength() const;//队列长度
	bool enqueue(customer element);//新元素队尾
	bool dequeue(customer &element);//首元素出列
	void queuetraverse();//遍历队列visit function
private:
	customer *m_pqueue;//队列数组指针
	int m_queuelen;//元素个数
	int m_queuecapacity;//数组容量
	int m_ihead;
	int m_tail;

};	


#endif

