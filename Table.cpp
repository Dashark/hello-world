#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct element{
	int tag;
	int x;
	double y;
	char s[100];
};
struct rows{
	vector<element> column;
};

class Table{
public:
	Table(){
	}
	Table(int x, int y){
		for (int i = 0; i < x; i++){
			addRow();
		}
		for (int i = 0; i < y; i++){
			addColumn();
		}
	}
	void show(){

		for (int i = 0; i < table.size(); i++){
			for (int j = 0; j < table[0].column.size(); j++){
				if (table[i].column[j].tag == -1){
					if (j != 0){
						cout << "\t" << "NULL";
					}
					else{
						cout <<"NULL";
					}
					
				}else
				if (table[i].column[j].tag == 0){
					if (j != 0){
						cout << "\t" << table[i].column[j].x;
					}
					else{
						cout << table[i].column[j].x;
					}
				}else
				if (table[i].column[j].tag == 1){
					if (j != 0){
						cout << "\t" << table[i].column[j].y;
					}
					else{
						cout << table[i].column[j].y;
					}
				}else
				if (table[i].column[j].tag == 2){
					if (j != 0){
						cout << "\t" << table[i].column[j].s;
					}
					else{
						cout << table[i].column[j].s;
					}
				}
			}
			cout << endl;
		}
	}
	void addRow( ){
		rows tt;
		element tx;
		tx.tag = -1;
		if (table.size() > 0){
			for (int i = 0; i < table[0].column.size(); i++){
				tt.column.push_back(tx);
			}
		}
		table.push_back(tt);
	}
	void addColumn(){
		element ttt;
		ttt.tag = -1;
		for (int i = 0; i < table.size(); i++){
			table[i].column.push_back(ttt);
		}
	}
	void set(int x, int y, double z){
		x--;
		y--;
		table[x].column[y].y = z;
		table[x].column[y].tag = 1;
	}
	void set(int x, int y, int z){
		x--;
		y--;
		table[x].column[y].x = z;
		table[x].column[y].tag = 0;
	}
	void set(int x,int y,char *s){
		x--;
		y--;
		int MAX = 100;
		int len = strlen(s);
		memset(table[x].column[y].s, 0, 100);
		strncpy(table[x].column[y].s, s, min(len, MAX));
		table[x].column[y].tag = 2;
	}
	void delRow(int rr){
		table.erase(table.begin()+rr-1);
	}
	void delColumn(int cc){
		for (int i = 0; i < cc; i++){
			table[i].column.erase(table[i].column.begin() + cc - 1);
		}
	}
private:
	vector <rows> table;
	int row;
	int colume;
};

	int main() {
	Table tb;
	tb.show();
	tb.addRow();
	tb.show();
	tb.addColumn();
	tb.show();
	Table tb1(5, 5);
	tb1.show();
	tb1.set(1, 1, 30);
	tb1.set(2, 2, "hello");
	tb1.show();
	tb1.delRow(1);
	tb1.show();
	tb1.delColumn(1);
	tb1.show();
	return 0;
}
