#include<iostream>

using namespace std;
class Shape
{public:
	virtual float area() const {return 0.0;}
	virtual float volume() const {return 0.0;}
	virtual void shapeName() const = 0;
};
class Point:public Shape 
{public:
	Point (float = 0,float = 0);
	void setPoint(float,float);
	float getX() const{return x;}
	float getY() const{return y;}
	virtual void shapeName() const {cout << "Point: ";}
	friend ostream & operator << (ostream & ,const Point &);
protected:
	float x,y;
};
Point::Point(float a,float b)
{
	x = a ;
	y = b ;
 } 
 void Point::setPoint(float a,float b)
 {
 	x = a ;
 	y = b ;
 }
 ostream & operator << (ostream &output,const Point &p)
 {
 	output << "[" << p.x << "," << p.y <<"]";
	 return output; 
 }
 class Circle : public Point 
 {public:
 	Circle(float x = 0,float y = 0,float r = 0);
 	void setRadius(float);
 	float getRadius() const ;
 	virtual float area () const;
 	virtual void shapeName() const {cout << "Circle:";}
 	friend ostream & operator << (ostream &,const Circle &);
protected:
	float radius;
 };
 Circle::Circle(float a,float b,float r) :Point (a,b),radius(r){}
 void Circle::setRadius(float r){
 	radius = r;
 }
 float Circle::getRadius() const{return radius;}
 float Circle::area() const {return 3.14159*radius*radius;}
 ostream &operator << (ostream &output,const Circle &c)
 {
 	output << "[" << c.x << "," << c.y <<"],r=" << c.radius;
 	return output;
  }
  class Cylinder:public Circle
{public:
	Cylinder(float x = 0,float y = 0,float r = 0, float h = 0);
	void setHight(float);
	virtual float area() const;
	virtual float volume() const;
	virtual void shapeName() const {cout << "Cylinder:";}
	friend ostream & operator << (ostream&,const Cylinder&);
protected:
	float height;
 };
 Cylinder::Cylinder(float a,float b,float r,float h):Circle(a,b,r),height(h){
 }
 void Cylinder::setHight(float h){
 	height = h;
 }
  float Cylinder::area() const
  {
  	return 2*Circle::area()+2*3.14159*radius*height;  }
 float Cylinder::volume()const
 {
 	return Circle::area()*height;
 }
 ostream &operator << (ostream &output,const Cylinder&cy)
 {
 	output << "["<< cy.x << "," << cy.y << "],r=" << cy.radius <<",h= " << cy.height;
 	return output;
 }
 int main()
 {
 	Point point(3.2,4.5);
 	Circle circle(2.4,1.2,5.6);
 	Cylinder cylinder(3.5,6.4,5.2,10.5);
 	point.shapeName();
 	cout << point <<endl;
 	circle.shapeName();
 	cout << circle << endl;
 	cylinder.shapeName();
 	cout << cylinder << endl;
 	Shape*pt;
 	pt=&point;
 	pt->shapeName();
 	cout << "x=" << point.getX() << ",y=" << point.getY() << "\narea="<< pt->area()<<"\nvolume ="<<pt->volume()<<"\n\n";
 	pt = &circle;
 	pt -> shapeName();
 	cout << "x=" <<circle.getX() <<",y=" <<circle.getY() << "\narea = "<<pt->area()
 	     << "\nvolume="<<pt->volume()<<"\n\n";
    pt = &cylinder;
    pt ->shapeName();
    cout << "x=" <<cylinder.getX()<<",y="<<cylinder.getY()<<"\narea="<<pt->area()
    	 <<"\nvolume =" <<pt->volume()<<"\n\n";
    return 0;
 }
