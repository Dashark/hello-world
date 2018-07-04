#include<bits/stdc++.h>
using namespace std;

class Parallelogram 
{
	public:
		Parallelogram(){angle=1.047;lena=3;lenb=2.9;}
//		~Parallelogram();
		void show();
		void area();
		void height();
		void length();
	private:
		float angle,lena,lenb;
};

void Parallelogram::area()
{
	cout<<lena*lenb*sin(angle)<<endl;
}

void Parallelogram::height()
{
	cout<<lena*sin(angle)<<"或者"<<lenb*sin(angle)<<endl;
}

void Parallelogram::length()
{
	cout<<2*(lena+lenb)<<endl;
}

void Parallelogram::show()
{
	int i,j,k;
	for(i=0;i<round(lenb);i++)
	{
		for(k=0;k<i;k++)
		cout<<' ';
		for(j=0;j<round(lena);j++)
		cout<<'*'<<' ';
		cout<<endl;
	}
}

int main() {
  Parallelogram pg;
  pg.show();
  pg.area();
  pg.height();
  pg.length();
  return 0;
}
