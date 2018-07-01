#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Cell {
public:
  template<class T>
  Cell(T con);
  Cell();
  template<class V>
  Cell(Cell& obj) {
    this->content = obj.content;
  }
  ~Cell();
  void show();
  void clear();
private:
  string content;
};

class Table {
public:
  Table(int _row = 1, int _col = 1);
  template<class T>  
  void set(int _row, int _col, T text);
  void show();
  void addRow();
  void delRow(int n);
  void addColumn();
  void delColumn(int n);
private:
  int rows, cols;
  Cell cells[101][101];
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

template<class T>
Cell::Cell(T con) {
  stringstream ss;
  ss << con;
  ss >> content;
}

Cell::Cell() {
  content = "null";
}

void Cell::show() {
  cout << content;
}

void Cell::clear() {
  content = "null";
}

Table::Table(int _row, int _col) :rows(_row),cols(_col){
  for(int i = 1; i <= _row; i++) {
    for(int j = 1; j <= _col; j++) {
      cells[i][j].clear();
    }
  }
}

void Table::show() {
  for(int i = 1; i <= rows; i++) {
    for(int j = 1; j <= cols; j++) {
      cells[i][j].show();
      cout << '|';
    }
    cout << endl;
  }
  cout << "This is the table" << endl << endl;
}

void Table::addColumn() {
  if(cols == 100) {
    cout << "Columns are Max" << endl;
  }
  else {
    cols++;
    for(int i = 1; i <= rows; i++) {
      cells[i][cols].clear();
    }
  }
  return;
}

void Table::addRow() {
  if(rows == 100) {
    cout << "Rows are Max" << endl;
  }
  else {
    rows++;
    for(int j = 1; j <= cols; j++) {
      cells[rows][j].clear();
    }
  }
}

void Table::delColumn(int _col) {
 for(int i = _col; i < cols; i++) {
   for(int j = 1; j <= rows; j++) {
     cells[j][i] = cells[j][i+1];
   }
 }
  cols--;
}

void Table::delRow(int _row){
 for(int i = _row; i < rows; i++) {
   for(int j = 1; j <= cols; j++) {
     cells[i][j] = cells[i+1][j];
   }
 }
  rows--;
}

template<class T>
void Table::set(int _row, int _col, T text) {
  string temp;
  stringstream ss;
  ss << text;
  ss >> temp;
  cells[_row][_col] = temp;
}