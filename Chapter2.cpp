#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

class Chapter {
	public:
		Chapter():pages(0),title(""){}
		Chapter(string &title, int pages):pages(pages),title(title) {}
		void show() const {cout<<"title:"<<title<<" pages:"<<pages<<endl;}
	private:
		const string title; //章节标题固定的字符串
		const int pages; //章节页数固定，不能改变
		//复制章节对象没有意义，所以禁止
		Chapter(const Chapter &obj):pages(0),title(""){}
};

class Book{
	public:
		Book(){}
		
		int insert(string &title,int pages)
		{
			book.push_back(new Chapter(title,pages));
			return 0;
		}
		
		int show()
		{
			for(int i=0;i<book.size();i++)
				book[i]->show();
			return 0;
		}
		
	private:
		const string bookname;
		vector<Chapter *> book;
};

int main()
{
	string s="test";
	Book b;
	b.insert(s,3);
	b.show();
	return 0;
}

