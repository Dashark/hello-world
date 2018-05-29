#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

//引用做函数参数
void fun(int *a, int *b) {
	int c = 0;
	 c = *a;
	*a = *b;
	*b = c;


}
void fun1(int &a, int &b) {
	int c = 0;
	c = a;
	a = b;
	b = c;

}//引用可以直接替换；
using namespace std;
//指针类型应用：类型 *&指针引用名 =指针：


//创建结构体
typedef struct {
	int x;
	int y;

}Coor;


const int x = 3;//不可被改变值；
const int *pp = NULL;
int const *pp1 = NULL;//与上面等价；
int * const pp2 = NULL;//not equvilant;
//const he yinyong
//指针指向const 修饰的变量 应该是const int a=3  const int const *p=&a;
//函数默认值 实参会覆盖默认值 默认值必须放在最后面  关于函数重载；在相同作用域下（同名 参数个数或类型不同）
//int getmax(int x,int y,int z);  
//int getmax(double x,double y);
//内联函数 编译时就替代函数调用语句 递归不可使用 inline int ...

//内存管理：资源 操作系统 申请 归还

//申请new 释放delete 
//int *p=new int[10] ;
//if (NULL==p){
// //内存分配失败了；
//}
//delete []p;
//c  void *malloc(size_t size);
//c  void free(void *malloc);配套使用

int main() {




	int a = 3;
	int *p = &a;
	int *&q = p; //指针类型引用；*&q=p   *q赋值；
	*q = 20;
	cout << a << endl;
	int &b = a;//引用必须初始化
	b = 10;
	Coor c1;
	Coor &c = c1;//结构体的应用类型 别名的操作
	c.x = 10;
	c.y = 20;
	cout << c1.x << " " << c1.y << endl;
	a = 20;
	int cc = 30;
	cout << a << endl;
	cout << b << endl;
	fun1(a, cc);
	cout << a << endl;
	cout << cc << endl;
	
	
	
	
	
	getchar();
	return 0;
}