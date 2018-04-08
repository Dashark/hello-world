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
}
