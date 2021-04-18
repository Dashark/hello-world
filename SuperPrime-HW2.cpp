#include<iostream>
#include<vector>
using namespace std;
int isPrime(int a)
{
	
	int i,judge=1;
	for(i=2;i<a;i++)
	{
		if(a%i==0)
		judge=0;
	}
	return judge;
}
class SuperPrime
{
	private:
	int w1,w2,w3,judge1,judge2,judge3,judge4;
	public:
		int count=0,total=0,max,a[900];
		int isSuperPrime(int a)
		{
			judge1=0;judge2=0;judge3=0;judge4=0;
		if(isPrime(a))
		judge1=1;
		w1=a%10;
		w2=(a%100)/10;
		w3=a/100;
		if(isPrime(w1+w2+w3))
		judge2=1;
		if(isPrime(w1*w2*w3))
		judge3=1;
		if(isPrime(w1*w1+w2*w2+w3*w3))
		judge4=1;
		if(judge1&&judge2&&judge3&&judge4)
		return 1;
		else
		return 0;
		}
		void caozuo(int left,int right)
		{
			total=0;count=0;
	for(int i=left;i<=right;i++)
	{
		
		if(isSuperPrime(i))
		{
		a[count]=i;
		total+=i;
		count++;
	    }
	    max=a[count-1];
	}
	}
};
int main()
{
	SuperPrime a;
	a.caozuo(100,999);
	cout<<endl;
	cout<<"和："<<a.total<<endl<<"个数："<<a.count<<endl<<"最大："<<a.max;

}
