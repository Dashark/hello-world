#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
class Vector {
public:
	enum Mode { RECT, POL };
	//rectangular mode polar mode
private:
	double x;
	double y;
	double mag;//magnitude of Vector
	double ang;//direction of Vector in degrees
	Mode mode;//RECT or POL
	void set_mag();
	void set_ang();
	void set_x();
	void set_y();
public:
	Vector();
	Vector(double n1, double n2, Mode form = RECT);
	void reset(double n1, double n2, Mode form = RECT);
	~Vector();
	double xval()const { return x; }
	double yval()const { return y; }
	double magval()const{ return mag; }
	double angval()const { return ang; }
	void polar_mode();
	void rect_mode();
	//operator overloading
	Vector operator+(const Vector & b)const;
	Vector operator-(const Vector & b)const;
	Vector operator-()const;//reverse sign of Vector
	Vector operator*(double n)const;

	//friends
	friend Vector operator*(double n, const Vector & a);
	friend std::ostream &operator<<(std::ostream & os, const Vector & v);
}
#endif