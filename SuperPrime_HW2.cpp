#include <iostream>
#include <vector>
using namespace std;
class Nature {
private:
	int num;
public:
	Nature():num(0){;}
	Nature(int n):num(n) {;}
	Nature(const Nature &nat):num(nat.num){;}
	~Nature() {;}
	int change()
	{
		return num;
	}
	void show()
	{
		cout<<num<<endl;
	}
	bool isPrime(int x)
	{
		int m=0;
		for(int i=2;i<x;i++)
		{
			if(x%i!=0)
				m++;
		} 
		if(m==x-2) 
			return(true);
		else 
			return(false);
	} 
	bool isSuperPrime(int x){
  	int a,sum=0,mult=1,sqrsum=0;
	int X=x;
	while(x!=0)
	{
		a=x%10;
		sum=sum+a;
		mult=mult*a;
		sqrsum=sqrsum+a*a;
		x=x/10;
	}
	if(isPrime(X)&&isPrime(sum)&&isPrime(mult)&&isPrime(sqrsum))
	return(true);
  }
};
class SuperPrime {
private:
	vector<Nature>natures;
public:
	SuperPrime(int a,int b)
    {
    	for(int i = a; i < b; i++)
		{
    		Nature nat(i); 
    		if(nat.isSuperPrime(i))
        	natures.push_back(nat);
		}
	}
	Nature max()
	{
		vector<Nature>::iterator it=natures.begin();
		int m;
		for(;it!=natures.end();it++)
		{
			int n=it->change();
			if(n>m)
			{
				m=n;
			}
		}
		return Nature(m);
	}
	Nature howmany()
	{
		vector<Nature>::iterator it=natures.begin();
		int H=0;
		for(;it!=natures.end();it++)
		{
			H++;
		}
		return Nature(H);
	}
	Nature sum()
	{
		vector<Nature>::iterator it=natures.begin();
		int s=0;
		for(;it!=natures.end();it++)
		{
			int n=it->change();
			s=s+n;
		}
		return Nature(s);
	}
};
int main()
{
	SuperPrime sp(100,999); 
	cout<<"最大的超级素数为:";
	Nature max=sp.max();
  	max.show();
  	Nature howmany=sp.howmany();
  	cout<<"超级素数个数为:";
  	howmany.show();
  	Nature sum=sp.sum();
  	cout<<"超级素数的和为:";
  	sum.show();
	return 0;
}
