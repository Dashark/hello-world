#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<map>
#include<list>
#include<deque>
#include<stack> 
//顺序容器 ：vector list deque ;
//关联容器 ：map set multimap multiset;
//容器适配： stack queue priority_queue;
 
using namespace std;
int main()
{
	//.....vector.....//导入头文件#include<vector>
	vector<int> vec_test1;//初始化 空向量
	vector<int> vec_test2(vec_test1);//初始化方式 用已有vector初始
	vector<int> vec_test3(108);//108个值为0的向量 还可为（108，4）这样初始
	//<>内部同样可以是其他数据类型；
		 
	bool isempty=vec_test1.empty();
	int lenth=vec_test1.size();
	vec_test1.push_back(1998);//插入1998 
	lenth=vec_test1.size();
	cout<<vec_test1[0]<<" "<<lenth<<" "<<isempty<<endl;

	vec_test1.push_back(1007);//插入1007 
	lenth=vec_test1.size();
	cout<<vec_test1[0]<<" "<<lenth<<" "<<isempty<<endl;

	vec_test1.push_back(108);//插入108 
	lenth=vec_test1.size();
	cout<<vec_test1[0]<<" "<<lenth<<" "<<isempty<<endl;

	vec_test1.pop_back();//删除末尾元素
	lenth=vec_test1.size();
	cout<<vec_test1[0]<<" "<<lenth<<" "<<isempty<<endl;

	vec_test1.insert(vec_test1.end(),5,3);//在最后插入5个3； 
	lenth=vec_test1.size();
	//迭代器学习日后补充；

	cout<<vec_test1[0]<<" "<<lenth<<" "<<isempty<<endl;
	vec_test1.clear();
	//没有sort； 
	
	//遍历方法 通过取长度访问下标或者迭代器遍历
	
	//.....list.....//导入头文件#include<list>
 	list<int> list1;
 	list<int> list2(3);//含有三个元素；
	list<int> list3(4,2);//含有四个值为二的元素；
	list<int> list4(list2);
//	 
	list1.push_back(1);
//	list1.clear();
	list1.pop_back();
	int lenth1=list3.size();
	cout<<" "<<lenth1<<endl;
	//remove(int) 相同元素全部删除；
	//reverse() 同vector 反转
	//sort 提供排序操作
	 
	//遍历通过迭代器
	
	//.....deque.....//需导入头文件#include<deque>
	//除了从头插入数据别的与vector类似
	
	//.....priorty_queue....//优先队列
	priority_queue<int> big;
	priority_queue<int,vector<int>,greater<int> > small;//最后要有空格 
	small.push(4);
	small.push(34);
	small.push(2);
	small.push(32);
	cout<<small.top()<<endl;
	small.pop();//弹出顶元素；优先级按照以上big 和small 定义
	cout<<small.empty()<<endl;
	
	cout<<small.top()<<endl;
	//不能随机访问任意顺序的值；
	//自定义优先级
	//	struct node
	//{
	//int x, y;
	//friend booloperator< (node a, node b)
	//{
	//return a.x > b.x; //结构体中，x小的优先级高
	//}
	//};
	//priority_queue<node>q;//定义方法
	//在该结构中，y为值, x为优先级。
	//通过自定义operator<操作符来比较元素中的优先级。
	//在重载”<”时，最好不要重载”>”，可能会发生编译错误
	queue<int> test_queue1;
	test_queue1.push(1);
	test_queue1.push(32);
	
//	push(x) 将x压入队列的末端
//	
//	pop() 弹出队列的第一个元素(队顶元素)，注意此函数并不返回任何值
//
//	front() 返回第一个元素(队顶元素)
//
//	back() 返回最后被压入的元素(队尾元素)
//
//	empty() 当队列为空时，返回true
//
//	size() 返回队列的长度
	
	cout<<small.size()<<endl;

	 
	
		
		return 0; 

} 
