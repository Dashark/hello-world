#include<iostream>

using namespace std;

class Complex
{public:
	Complex(){real = 0;imag = 0;}
	Complex(double r){real = r ;imag = 0;
	}
	Complex(double r,double i){
		real = r;
		imag = i;
}
	friend Complex operator + (Complex c1,Complex c2);
	/*operator double()
	{
		return real;
	}*/
	void display();
private:
	double real;
	double imag;
 };
 Complex operator  + (Complex c1, Complex c2)
 {
 	return Complex(c1.real+c2.real,c1.imag+c2.imag);
 }
 void Complex::display()
 {
 	cout << "(" << real <<"," << imag << ")" <<endl;
 }
 int main()
 {
 	Complex c1(3,4),c2(6,6),c3;
 	double d = 2.7;
 	c3 = c1 + d; 
 	c3.display();
 	return 0;
 	
 }
