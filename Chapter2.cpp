/*#include <string>
class Chapter2 {
public:
  Chapter2(){}
  Chapter2(std::string &title, int pages):pages(pages),title(title) {}
  void show() const {}
private:
  const string title; //章节标题固定的字符串
  const int pages; //章节页数固定，不能改变
  //复制章节对象没有意义，所以禁止
  Chapter2(const Chapter2 &obj) {}
}*/
#include<iostream>
using namespace std;
class Box
{public:
	Box(int,int,int);
	int volume();
private:
	int height;
	int width;
	int length;
 };
 Box::Box(int h,int w,int len)
 {
 	height=h;
 	width=w;
 	length=len;
 }
 int Box::volume()
 {
 	return (height*width*length);
 }
 int main()
 {
 	Box box1(12,12,12);
 	cout<<"The volume of box1 is"<<box1.volume()<<endl;
 	Box box2(13,13,13);
 	cout<<"The volume of box2 is"<<box2.volume()<<endl;
 	return 0;
 }
