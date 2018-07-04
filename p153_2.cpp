#include<iostream>
using namespace std;
class Complex
{public:
	Complex()
	{
		real = 0 ;
		imag = 0 ; 
	}
	Complex(double r,double i)
	{
		real = r ;
		imag = i ;
	}
	Complex operator + (Complex &c2);
	Complex operator * (Complex &c2);
	Complex operator / (Complex &c2);
	Complex operator - (Complex &c2);
	void display();
private:
	double real;
	double imag;
		
};
Complex Complex::operator +(Complex &c2)
{
	return Complex(real+c2.real,imag+c2.imag);
}
Complex Complex::operator -(Complex &c2)
{
	return Complex(real-c2.real,imag-c2.imag);
}
Complex Complex::operator *(Complex &c2)
{
	
	return Complex(real*c2.real,imag*c2.imag);
}
Complex Complex::operator /(Complex &c2)
{
	return Complex(real/c2.real,imag/c2.imag);
}
void Complex::display()
{
	cout << "(" << real << "," << imag << ")" << endl;
}
int main()
{
	Complex c1(45.53,66.23),c2(12.65,13.65),c3,c4,c5,c6;
	c3 = c1 + c2;
	c4 = c1 - c2;
	c5 = c1 * c2;
	c6 = c1 / c2;
	c3.display();
	c4.display();
	c5.display();
	c6.display();
	return 0;
}
