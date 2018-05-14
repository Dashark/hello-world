#include<iostream>
#include<string>
using namespace std;

//初始化列表 初始化const常对象成员；
//常成员函数 void changex() const;不能修改数据成员的值
//和正常函数互为重载 
//const 对象 实例   然后调用函数是常成员函数
//
class line {
public:
	line(int x1, int y1, int x2, int y2);
	~line();
	void setA(int x1, int y1);
	void setB(int x2, int y2);
	void printinfo();
private:
//	const coordinate m_coora;
//	coordinate m_coorb;

};
class coordinate {
public:
	coordinate(int x, int y);
	int getx();
	int gety();
	void printinfo() const;
private:
	int m_ix;
	int m_iy;
};
coordinate::coordinate(int x, int y) {
	m_ix = x;
	m_iy = y;

}
int coordinate::getx(){
	return m_ix;
}
int coordinate::gety() {
	return m_iy;
}
void coordinate::printinfo()const {
	cout << m_ix << " " << m_iy << endl;
}
int main() {
	coordinate coor1(3, 5);
	const coordinate &coor2 = coor1;//常成员函数
	const coordinate *pcoor = &coor1;
	coor1.printinfo();
	coor2.printinfo();//只能调用常成员函数
	pcoor->printinfo();
	getchar();
	return 0;

}