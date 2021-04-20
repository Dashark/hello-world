#include<iostream>
class SuperPrime
{
	public:
		int IsPrime(int i)
		{
			if(i<3)
			return 0;
			for(int j=2;j<i;j++)
			{
				if(i%j==0)
				return 0;
				if(i%j!=0)
				continue;
			}
			return 1;
		}
		void NumberSP()
		{
			k++;
		}
		void SumSP(int a)
		{
			sum+=a;
		}
		void MaxSP(int b)
		{
			if(b>max)
			max=b;
		}
		void getnum()
		{
			std::cout << "Number=" << k << std::endl;
		}
		void getsum()
		{
			std::cout << "Sum=" << sum << std::endl;
		}
		void getmax()
		{
			std::cout <<"Max=" << max << std::endl;
		}
	private:
		int i,k=0,sum=0,max=2;
};
int main()
{
	SuperPrime sp;
	for(int i=100;i<=999;i++)
	{
		int a=i/100;
        int b=(i/10)%10;
        int c=i%10;
        int n1=a+b+c,n2=a*b*c,n3=a*a+b*b+c*c;
        if(sp.IsPrime(i)&&sp.IsPrime(n1)&&sp.IsPrime(n2)&&sp.IsPrime(n3))
        {
        	sp.NumberSP();
        	sp.SumSP(i);
        	sp.MaxSP(i);
		}
	}
	sp.getnum();
	sp.getsum();
	sp.getmax();
	return 0;
}
