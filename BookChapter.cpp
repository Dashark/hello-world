#include <string>
#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


//splay-start
struct tree{
	int val;
	tree *father,*lson,*rson;
	tree(){
		father=lson=rson=NULL;
	}
};

tree *root=NULL;

int splay(tree *pos);

int insert(int val)
{
	tree *current=root;
	tree *father=NULL;
	while(current!=NULL)
	{
		father=current;
		if(val < current->val)
			current=current->lson;
		else
			current=current->rson;
	}
	current=new tree;
	current->val=val;
	current->father=father;
	if(current->father == NULL)
	{
		root=current;
		return 0;
	}
	if(current->val < father->val)
		father->lson=current;
	else
		father->rson=current;
	return 0;
}

tree *search(int val)
{
	tree *current=root;
	while(true)
	{
		if(current == NULL)
			break;
		if(current->val == val)
			break;
		if(val < current->val)
			current=current->lson;
		else
			current=current->rson;
	}
	splay(current);
	return current;
}

int remove(int val)
{
	tree *current=root;
	while(current->val != val)
	{
		if(val < current->val)
			current=current->lson;
		else
			current=current->rson;
	}
	if(current->lson == NULL && current->rson == NULL)
	{
		if(current->father != NULL)
		{
			if(current->val < current->father->val)
				current->father->lson = NULL;
			else
				current->father->rson = NULL;
			delete current;
		}
	}
	if(current->lson != NULL)
	{
		tree *left_max = current->lson;
		while(true)
		{
			if(left_max->rson != NULL)
			{
				left_max = left_max->rson;
			}
			else if(left_max->lson != NULL)
			{
				left_max = left_max->lson;
			}
			else
			{
				current->val = left_max->val;
				if(left_max->val < left_max->father->val)
					left_max->father->lson = NULL;
				else
					left_max->father->rson = NULL;
				delete left_max;
				break;
			}
		}
	}
	else
	{
		tree *right_min = current->rson;
		while(true)
		{
			if(right_min->lson != NULL)
			{
				right_min = right_min->rson;
			}
			else if(right_min->lson != NULL)
			{
				right_min = right_min->lson;
			}
			else
			{
				current->val = right_min->val;
				if(right_min->val < right_min->father->val)
					right_min->father->lson = NULL;
				else
					right_min->father->rson = NULL;
				delete right_min;
				break;
			}
		}
	}
	return 0;
}

int rotate(tree *pos,int dir)
{
	tree *father=pos->father;
	tree *grandfather=pos->father->father;
	father->father=pos;
	if(grandfather != NULL)
	{
		int i=(grandfather->lson==father?1:-1);
		if(i==1)
			grandfather->lson=pos;
		else if(i==-1)
			grandfather->rson=pos;
	}
	if(dir==0)
	{
		father->rson=pos->lson;
		if(pos->lson != NULL)
			pos->lson->father=father;
		pos->lson=father;
		pos->father=grandfather;//
	}
	else if(dir==1)
	{
		father->lson=pos->rson;
		if(pos->rson != NULL)
			pos->rson->father=father;
		pos->rson=father;
		pos->father=grandfather;//
	}
	if(father==root)
		root=pos;
	return 0;
}

int splay(tree *pos)
{
	tree *current=pos;
	while(current!=root && current->father!=root)
	{
		int i=(current==current->father->lson?1:-1);
		int j=(current->father==current->father->father->lson?1:-1);
		if(i==1 && j==1)
		{
			rotate(current->father,1);
			rotate(current,1);
		}
		else if(i==-1 && j==-1)
		{
			rotate(current->father,0);
			rotate(current,0);
		}
		else if(i==-1 && j==1)
		{
			rotate(current,0);
			rotate(current,1);
		}
		else if(i==1 && j==-1)
		{
			rotate(current,1);
			rotate(current,0);
		}
	}
	if(current->father == root)
	{
		int i=(current==current->father->lson?1:-1);
		if(i==1)
		{
			rotate(current,1);
		}
		else if(i==-1)
		{
			rotate(current,0);
		}
	}
	return 0;
}

int splay_sample()
{
	insert(11);  
    insert(7);  
    insert(18);  
    insert(3);  
    insert(9);  
    insert(16);  
    insert(26);  
    insert(14);  
    insert(15);  
    search(14);
	return 0;
}
//splay-end




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
