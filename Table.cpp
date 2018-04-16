#include<iostream>

#include<string>

using namespace std;

class Table {

public:

	void show();

	void addRow();

	void show();

	void addColumn();

	Table(int a, int b);

	~Table();

	void set(int a, int b, int c);

	void set(int a, int b, string c);

	void delRow(int r);

	void delColumn(int c);

private:

	int Row;

	int Column;

	string str;

};

Table::Table(int a=0,int b=0):Row(a),Column(b){}

Table::~Table(){}

void Table::show() {

	cout << Row << " " << Column << endl;

}

void Table::addRow() {

	Row++;

}

void Table::addColumn() {

	Column++;

}

void Table::set(int a, int b, int c) {

	Row = a;

	Column = b;

	str.push_back((char)c);

}

void Table::set(int a, int b, string c) {

	Row = a;

	Column = b;

	str = c;

}

void Table::delRow(int a) {

	Row--;

}

void Table::delColumn(int b) {

	Column++;

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
