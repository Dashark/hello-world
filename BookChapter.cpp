#include <string>
#include <vector>
#include <iostream>
class Chapter2 {
public:
  Chapter2():title("N/A"),pages(0){ std::cout<<"Chapter2"<<std::endl;}
  Chapter2(std::string &title, int pages):pages(pages),title(title) {}
  Chapter2(char title[], int pages):pages(pages),title(title) {}
  void show() const {
  	std::cout << title << "(" << pages << ")"<<std::endl;
  }
private:
  const std::string title; //章节标题固定的字符串
  const int pages; //章节页数固定，不能改变
  //复制章节对象没有意义，所以禁止
  Chapter2(const Chapter2 &obj):title("N/A"),pages(0) {}
};
class Book {
public:
	Book() {
		index = 0;
		for(int i=0;i<10;i++)
		  chaps[i] = 0;
	}
	~Book() {
		for(int i=0;i<index;i++)
		  delete chaps[i];
	}
	Chapter2 * addChapter(char title[], int pages) {
		Chapter2* obj = new Chapter2(title,pages);
		chaps[index++] = obj;
		return obj;
	}
	void show() {
	  for(int i=0;i<10;i++)
	    if(chaps[i]!=0)
	      chaps[i]->show();
	}
private:
  Chapter2 *chaps[10];
  int index;
};
int main() {
	Book book;  //new book
	Chapter2 *obj = book.addChapter("Hello",1);
	book.show();
}
