#include <iostream>
#include <string>

class Table {
 public:
  Table() {};
  Table(int row, int column) {

  }
  ~Table() {};
  void show() {

  }
  int addRow() {

  }
  void delRow(int n) {

  }
  int addColumn() {

  }
  void delColumn(int n) {

  }
 private:
  Cell cells;
};
class Cell {
 public:
  Cell(char con[]) {
    content = con[];
  }
  ~Cell();

  void show() {
    std::cout << content;
  }
 private:
  std::string content;
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
