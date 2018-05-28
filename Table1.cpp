#include <iostream>
#include <string.h>
class Table {
	public:
  	  Table() {
	  	row = 20;
	  	col = 20;
	  	for(int i = 0; i < row; i++) {
	  		for (int j = 0; j < col; j++) {
	  		  atable[i][j] = '0';
			}
		}
	  };
	  Table(int row, int col) {
	  	this->row = row;
	  	this->col = col;
	  	for(int i = 0; i < row; i++) {
	  		for (int j = 0; j < col; j++) {
	  		  atable[i][j] = '0';
			}
		}
	  }
	  ~Table() {};
	  
	  void show() {
	  	for(int i = 0; i < 20; i++) {
	  		for (int j = 0; j < 20; j++) {
	  		  cout << atable[i][j] << " ";
			}
	  		cout << endl;
		}
	  };
	  void addRow() {
	  	row++;
	  };
	  void addColumn() {
	  	col++;
	  };
	  void set(int row, int col, char data) {
	  	atable[row-1][col-1] = data;
	  };
	  void delRow(int r) {
	  	for(int i = r-1; i < row; i++) {
	  		for (int j = 0; j < col; j++) {
	  		  atable[i][j] = atable[i+1][j];
			}
		}
	  };
	  void delColumn(int c) {
	  	for(int i = 0; i < row; i++) {
	  		for (int j = c-1; j < col; j++) {
	  		  atable[i][j] = atable[i][j+1];
			}
		}
	  };
	  
	private:
	  char atable[50][50];
	  int row, col;
  	  Cell cells;
};
class Cell {
public:
  Cell(char con[]) {
  	con = "0";
  };
  ~Cell();
  void show();
  
private:
  string content;
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
