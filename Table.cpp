#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Table {
  public:
    Table(int _row = 1, int _col = 1);
    ~Table();
    void show();
    void addColumn();
    void addRow();
    void delRow(int _rowNum);
    void delColumn(int _colNum);
    template<class T>
    void set(int _rowNum, int _colNum, T text);

  private:
    int rows, cols;


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

