#include <string>
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
}