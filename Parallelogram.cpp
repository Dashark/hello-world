#include <iostream> 
 using namespace std; 
 

 class Parallelogram { 
 public: 
 	Parallelogram(); 
 	Parallelogram(double, double); 
 	~Parallelogram() { }; 
 
 	void setsize(double, double); 
 	void show(); 
 	double area(); 
 	double height(); 
 	double length(); 
 

 private: 
 	double pheight; 
 	double plength; 
 }; 
 
 Parallelogram::Parallelogram() { 
 	pheight = 0; 
 	plength = 0; 
 } 
 
 Parallelogram::Parallelogram(double h, double l) { 
 	pheight = h; 
 	plength = l; 
 } 
 
 
 void Parallelogram::show() { 
 	cout << "the height is " << height() << endl; 
 	cout << "the length is " << length() << endl; 
 	cout << "the area is " << area() << endl; 
 } 
 
 
void Parallelogram::setsize(double h, double l) { 
 	pheight = h; 
 	plength = l; 
 } 
 
 
 double Parallelogram::area() { 
 	return pheight * plength; 
 } 
 
 double Parallelogram::height() { 
 	return pheight; 
 } 
 
 
 double Parallelogram::length() { 
 	return plength; 
 } 
 
 
 int main() { 
 	Parallelogram *pg = new Parallelogram(3.5, 4); 
 	pg->show(); 
 	pg->area(); 
 	pg->height(); 
 	pg->length(); 
 	return 0; 
 }
