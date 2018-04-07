#include <iostream>
#include <string>
using namespace std;

class Table{
public:
	Table();
	Table(int,int);
	void show();
	void addRow(){h++;}
	void addColumn(){l++;}
	void set(int,int,int);
	void set(int,int,char*);
	void delRow(int);
	void delColumn(int);
private:
	string mytable[20][20];
	int h;
	int l;
};

Table::Table(){
	h=l=0;
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++)
			mytable[i][j]="null";
	}
}
Table::Table(int a,int b){
	h=a;
	l=b;
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++)
			mytable[i][j]="null";
	}
}

void Table::show(){
	int i=0,j=0;
	for(i=0;i<h;i++){
		for(j=0;j<l;j++)
			cout<<mytable[i][j]<<'\t';
		printf("\n");
	}
	printf("\n");
}

void Table::set(int hs,int ls,char* c){
	mytable[hs][ls]=c;
}
void Table::set(int hs,int ls,int c){
	char a[20];
	mytable[hs][ls]=itoa(c,a,10);
}

void Table::delColumn(int a){
	a = a-1;
	for(int i=a;i<l;i++){
		for(int j=0;j<h;j++)
			mytable[i][j] = mytable[i][j+1];
	}
	l--;
}

void Table::delRow(int a){
	a = a-1;
	for(int i=a;i<h;i++){
		for(int j=0;j<l;j++)
			mytable[i][j] = mytable[i+1][j];
	}
	h--;
}


int main() {
  Table tb;

  tb.show();
  tb.addRow();
  tb.show();
  tb.addColumn();
  tb.show();
  Table tb1(5,5);
  tb1.show();
  tb1.set(1,1,30);
  tb1.set(2,2,"hello");
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(1);
  tb1.show();
  return 0;
}
