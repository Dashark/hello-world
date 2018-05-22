#include<iostream>
#include<cstdio>
#include<string>
//string 类型讲解
//string s1 s1为空串；
//string s2("abc") 初始化
//string s3(s2) 初始化为s2的一个副本
//stirng s4(n,"c") 初始化为字符“c”的n个副本；
//s.empty() true or false;
//s.size(); s+s1 ; s=s2; s==s1 ;s!=s1;s[n]从零开始；
//双引号相加不可以

//构造函数 构造函数重载
//
using namespace std;

class TV {
public:
	TV():type(10){};//初始化列表(只用于构造函数)类型：数据{}；；
	TV(const TV& tv1){}//拷贝构造函数 引用
	//拷贝构造函数复制时可用
	//分浅拷贝和深拷贝   区别指针
	char name[20];
	int type;

	void changevol1() {
		cout << type << endl;
	}
	void power1() {
		cout << name << endl;
	}
	
};

//深拷贝实例 
class array1 {
public:
	array1() { m_icount = 5; m_parr = new int[m_icount]; }
	array1(const array1& arr) {
		m_icount = arr.m_icount;
		m_parr = new int[m_icount];//在拷贝函数内部重新申请内存；
		for (int i = 0; i < m_icount; i++) {
			m_parr[i] = arr.m_parr[i];
		}

	}
	~array1();

private:
	int m_icount;
	int *m_parr;

};
//对象成员  sizeof 是所有总和；

//this 指针 参数和数据成员同名 this -> something

int main() {
	TV tv[3];//从栈实例化对象
	TV *p = new TV[20]; //从堆中实例化对象
	tv[0].type = 0;//栈中访问点运算符
	(*p).type = 22;
	p->type = 1;//堆中访问用指针箭头访问
	string na = "zhangsan";
	string hobby("football");
	cout << na << " " << hobby << endl;
	cout << hobby.size() << endl;
	cout << na.empty() << endl;

	cout << tv[0].type << endl;
	cout << p->type << endl;
	delete[]p;
	p = NULL;
	getchar();
	return 0;
}