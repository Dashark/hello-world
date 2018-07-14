#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Parallelogram {
  public:
  Parallelogram(double height = 1, double length = 1, double acuteang = 90) : h(height), l(length), acuteang(acuteang) {}
  ~Parallelogram(){}
  void show();
  double area();
  double height();
  double length();

  private:
  double h ,l,acuteang;

};
int main() {
  Parallelogram pg;
  pg.show();
  pg.area();
  pg.height();
  pg.length();
  return 0;
}

void Parallelogram::show() {
  this->area();
  this->height();
  this->length();
  cout << "The acute angle is " << acuteang << endl;
}

double Parallelogram::height() {
  cout << "The height is " << h << endl;
  return h;
}

double Parallelogram::length() {
  cout << "The length is " << l << endl;
  return l;
}

double Parallelogram::area() {
  cout << "The area is " << sin(acuteang) * h * l << endl;
  return sin(acuteang) * h * l;
}