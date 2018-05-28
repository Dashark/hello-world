#include<iostream>
#include<string>
#include<math.h>
#include<stdio.h>
using namespace std;
class Cell;
class Table {
public:
  Table(int i,int j);
  ~Table();
  void show();
  int addRow();
  void delRow(int n);
  int addColumn();
  void delColumn(int n);
private:
  Cell cells;
};

class Cell {
public:
  Cell(char con[]);
  ~Cell();

  void show();
private:
  string content;
};

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
Table::Table(int i,int j){
	
}

void Table::show(){
 	
}
int Table::addRow(){
}
  
void Table::delRow(int n){
  	
}
int Table::addColumn(){
  	
}
void Table::delColumn(int n){
}
  
  
Cell::Cell(char con[]){
  	content = *con;
}
void Cell::show(){
	cout<<content<<endl;
}
