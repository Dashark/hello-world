#include <iostream>
#include <string.h>
  class Table {
public:

  void show();
  int addttt();
  void delttt(int n);
  int addmmmumn();
  void delmmmumn(int n);
private:
	public:
  	  Table() {
	  	ttt = 20;
	  	mmm = 20;
	  	for(int i = 0; i < ttt; i++) {
	  		for (int j = 0; j < mmm; j++) {
	  		  atable[i][j] = '0';
			}
		}
	  };
	  Table(int ttt, int mmm) {
	  	this->ttt = ttt;
	  	this->mmm = mmm;
	  	for(int i = 0; i < ttt; i++) {
	  		for (int j = 0; j < mmm; j++) {
	  		  atable[i][j] = '0';
			}
		}
	  }	  
	  void show() {
	  	for(int i = 0; i < 20; i++) {
	  		for (int j = 0; j < 20; j++) {
	  		  cout << atable[i][j] << " ";
			}
	  		cout << endl;
		}
	  };
	  void addttt() {
	  	ttt++;
	  };
  void addmmmumn() {
	  	mmm++;
  };
	  void set(int ttt, int mmm, char data) {
	  	atable[ttt-1][mmm-1] = data;
	  };
	  void delttt(int r) {
	  	for(int i = r-1; i < ttt; i++) {
	  		for (int j = 0; j < mmm; j++) {
	  		  atable[i][j] = atable[i+1][j];
			}
		}
	  };
	  void delmmmumn(int c) {
	  	for(int i = 0; i < ttt; i++) {
	  		for (int j = c-1; j < mmm; j++) {
	  		  atable[i][j] = atable[i][j+1];
			}
		}
	  };
	  
	private:
	  char atable[50][50];
	  int ttt, mmm;
  	  Cell cells;
};
class Cell {
  public:
  Cell(char con[]);
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
    tb.addttt();
    tb.show();
    tb.addmmmumn();
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
