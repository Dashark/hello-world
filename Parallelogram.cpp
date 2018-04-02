#include <iostream>
using namespace std;

class Parallelogram {
public:
	Parallelogram(double l, double h);
	
	void show();
	double area();
	double height();
	double length();
private:
	double height;
	double length;
};

Parallelogram::Parallelogram(double l, double h) {
	height = h;
	length = l;
}

void Parallelogram::show() {
	cout << "the height is" << height << endl;
	cout << "the length is" << length << endl;
	cout << "the area is" << height * length << endl;
}

double Parallelogram::area() {
	return height * length;
}

double Parallelogram::height() {
	return height;
}

double Parallelogram::length() {
	return length;
}

int main(void) {
	Parallelogram pg(3.5, 4);
	pg.show();
	pg.area();
	pg.height();
	pg.length();
	return 0;
}
