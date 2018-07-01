#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Table {
  public:
    Table(int _row = 1, int _col = 1);
    ~Table(){};
    void show();
    void addColumn();
    void addRow();
    void delRow(int _rowNum);
    void delColumn(int _colNum);
    template<class T>
    void set(int _rowNum, int _colNum, T text);

  private:
    int rows, cols;
    string table[101][101];
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

Table::Table(int _row, int _col) :rows(_row),cols(_col){
  for(int i = 1; i <= _row; i++) {
    for(int j = 1; j <= _col; j++) {
      table[i][j] = "null";
    }
  }
}
void Table::show() {
  for(int i = 1; i <= rows; i++) {
    for(int j = 1; j <= cols; j++) {
      cout << table[i][j] << '|';
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
      table[i][cols] = "null";
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
      table[rows][j] = "null";
    }
  }
}

void Table::delColumn(int _col) {
 for(int i = _col; i < cols; i++) {
   for(int j = 1; j <= rows; j++) {
     table[j][i] = table[j][i+1];
   }
 }
  cols--;
}

void Table::delRow(int _row) {
 for(int i = _row; i < rows; i++) {
   for(int j = 1; j <= cols; j++) {
     table[i][j] = table[i+1][j];
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
  table[_row][_col] = temp;
}