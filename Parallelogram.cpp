#include<iostream>
using namespace std;
class Parallelogram {
	public:
		Parallelogram(){
			hei=1;
			leng=1;
		}
		void show();
		int area();
		int height();
		int length();
	private:
		int hei;
		int leng;
		
};
int  Parallelogram::height(){
	return hei;
}
int Parallelogram::length(){
	return leng;
}
int Parallelogram::area(){
	return leng*hei;
}
void Parallelogram::show(){
	cout<<leng*hei;
}

int main() {
  Parallelogram pg;
  pg.show();
  pg.area();
  pg.height();
  pg.length();
  return 0;
}
