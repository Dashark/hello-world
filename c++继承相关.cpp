#include<string>
#include<iostream>
#include<cstdlib>
//公有继承public
//保护继承protected
//私有继承private

using namespace std;
class person {
public:
	person();
	~person();

	void eat();
protected:

	string m_strname;
private:

	int m_iage;

};
class worker :public person {
public:
	worker();
	~worker();
	void work();
	int m_salary;

};

person::person() {
	cout << "person()" << endl;
}
person::~person(){
	cout << "~person()" << endl;
}
void person::eat() {
	m_strname = "jin";
		m_iage = 2;
	cout << "eat()" << endl;
	cout << m_strname << endl;
}
worker::worker() {
	cout << "worker()" << endl;

}
worker::~worker() {
	cout << "~worker()" << endl;
}
void worker::work() {
	cout << "work()" << endl;
}
int main() {
	worker *p = new worker();
	delete p;
	p = NULL;
	person per;
	per.eat();
	

	getchar();
	return 0;

}
//隐藏 继承中同名函数访问机制区别

//soldier.play()
//soldier.person::play();
//参数不同 只有函数名相同不构成隐藏
//父子类同名函数访问同名数据成员 则在各自区域内访问需要类名：：数据成员


//is a  概念
//虚析构函数  virtual  防止内存泄漏
//当父类指针指向堆中子类对象并用父类指针销毁归还内存
//void test1(person p)类在函数传参会初始化临时对象 void test2(person &p) 引用不会产生临时对象 用*p传参也跟引用一样
//class mm:public worker,public person 不写继承方式则默认private
//构造函数 mm::mm(parameter):worker(参数)，person（参数）

