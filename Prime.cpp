<<<<<<< HEAD
#include<iostream>
#include<cmath>
using namespace std;
class Prime {
public:
  Prime(int num);
  ~Prime();

  bool isPrime();
  void print() const;
  Prime sumBit();
  Prime multiBit();
  Prime sqaureSumBit();
private:
  const int mNum;
};
Prime::Prime(int num):mNum(num){}
Prime::~Prime(){}
bool Prime::isPrime() {
	if (mNum == 1) {
		return false;
	}
	for (int j = 2; j <= sqrt(double(number)); j++)
	{
		if (mNum%j == 0)return false;
	}
	return true;
}
Prime Prime::sumBit() {
	if (mNum >= 1000) {
		int a[4]
		for (int i = 0; i < 4; i++) {
			a[i] = mNum % 10;
			mNum /= 10;
		}
		Prime a(a[0] + a[1] + a[2] + a[3]);
		return a;
	}
}
Prime Prime::multiBit() {
	if (mNum >= 1000) {
		int a[4]
			for (int i = 0; i < 4; i++) {
				a[i] = mNum % 10;
				mNum /= 10;
			}
		Prime b(a[0] * a[1] * a[2] * a[3]);
		return b;
	}
}
Prime Prime::sqaureSumBit() {
	if (mNum >= 1000) {
		int a[4]
			for (int i = 0; i < 4; i++) {
				a[i] = mNum % 10;
				mNum /= 10;
			}
		Prime c(a[0] * a[0] + a[1] * a[1] + a[2] * a[2] + a[3] * a[3]);
		return c;
	}
}
void Prime::print()const {
	cout << mNum << endl;
}
int main() {
  Prime pm(113);
  Prime sb = pm.sumBit();
  Prime mb = pm.multiBit();
  Prime ssb = pm.sqaureSumBit();
  if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime())
    pm.print(); //to do sth
  return 0;
=======
#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Prime
{
	public:
		Prime(int num );
		~Prime();
		bool isPrime();
		Prime sum_bit();
		Prime multi_bit();
		Prime square_bit();
	private:
		const int Num;
}
Prime::Prime(int num):Num(num){
}
bool Prime::isPrime()
{
	int i;
	for(i=2;i<Num;i++)
	{
		if(Num%i==0)
		{
			return false;break;
		}
	}
	return true;
}
Prime Prime::square_bit()
{
	int a,b,c,d;
	a=Num%10;
	b=(Num-a)/10%10;
	c=(Num-a-b*10)/10;
	d=Num/1000;
	return a*a+b*b+c*c+d*d;
}
Prime Prime::multi_bit()
{
	int a,b,c,d; 


 
	a=Num%10; 
	b=(Num-a)/10%10;
    c=(Num-a-b*10)/10/10%10;
    d=Num/1000;
    if(d!=0) 
    return a*b*c*d; 
    else 
    return a*b*c;
}
Prime Prime::sum_bit()
{
	int a,b,c,d;
	a=Num%10; 
	b=(Num-a)/10%10;
    c=(Num-a-b*10)/10/10%10;
    d=Num/1000;
    return a+b+c+d;
}
int main(int argc, char** argv) 
{
	int n[9999];
	int k=0,Sum=0;
	for(int i=100;i<=9999;i++)
	{
		Prime m(i);
		Prime sum=m.sum_bit();
		Prime multi=m.multi_bit();
		Prime square=m.square_bit();
		if(m.isPrime() && sum.isPrime() && multi.isPrime() && square.isPrime()) 
       { 


 	n[k]=i; 


 	k++; 


 		} 
	}
	for(int j=0;j<k;j++)
	Sum=Sum+n[k];
	cout<<"最大的素数是"<<n[k-1]<<endl;
	cout<<"共有超级素数"<<k<<"个"<<endl;
	cout<<"和为"<<Sum<<endl;
	
	return 0;
>>>>>>> pr/6
}
