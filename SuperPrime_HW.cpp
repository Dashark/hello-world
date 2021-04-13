#include<iostream>
class SuperPrime
{
private:
	const int left,right; 
public:
	SuperPrime(int a,int b):left(a),right(b)
	{
		; 
	}
	int Max()
	{
		int M;
		for(int x1=left;x1<right;x1++)
		{
			int a,x=x1;
			if(isSuperPrime(x)==true)
			M=x1;
		}
		return M;
	}
	int Howmany()
	{
		int H=0;
		for(int x1=left;x1<right;x1++)
		{
			int x=x1;
			if(isSuperPrime(x)==true)
			H++;
		}
		return H;
	}
	int Sum()
	{
		int S=0;
		for(int x1=left;x1<right;x1++)
		{
			int a,x=x1;
			if(isSuperPrime(x)==true)
			S+=x1;
		}
		return S;
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
	bool isSuperPrime(int x)
	{
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
		if(isPrime(X)==true&&isPrime(sum)==true&&isPrime(mult)==true&&isPrime(sqrsum)==true)
		return(true);	
	}	
};
 
int main()
{
	SuperPrime sp(100,999);
	std::cout << "最大的超级素数:" << sp.Max() << std::endl;
	std::cout << "超级素数个数:" << sp.Howmany() << std::endl;
	std::cout << "超级素数的和:" << sp.Sum() << std::endl;
	return 0;
}
