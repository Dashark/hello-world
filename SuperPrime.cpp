#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int NMAX=10000;
int is_prime[NMAX];

void init_prime()
{
	is_prime[1]=0;
	for(int i=2;i<NMAX;i++)
	{
		is_prime[i]=!is_prime[i];
		if(is_prime[i])
			for(int j=i+i;j<NMAX;j+=i)
				is_prime[j]=1;
	}
	return;
}

class Prime {
	public:
		Prime(int num):mNum(num){}
		~Prime(){}

		bool isPrime()
		{
			return is_prime[mNum];
		}
	private:
		const int mNum;
};

class SuperPrime : public Prime {
	public:
		SuperPrime(int _num):Prime(_num),num(_num){}
		~SuperPrime(){}

		//bool isPrime(){}

		Prime sumBit()
		{
			int sum=0,tmp_mNum=num;
			while(tmp_mNum!=0)
			{
				sum+=tmp_mNum%10;
				tmp_mNum/=10;
			}
			return Prime(sum);
		}
		
		Prime multiBit()
		{
			int product=1,tmp_mNum=num;
			while(tmp_mNum!=0)
			{
				product*=tmp_mNum%10;
				tmp_mNum/=10;
			}
			return Prime(product);
		}
		
		Prime squareSumBit()
		{
			int sum=0,tmp_mNum=num;
			while(tmp_mNum!=0)
			{
				sum+=(tmp_mNum%10)*(tmp_mNum%10);
				tmp_mNum/=10;
			}
			return Prime(sum);
		}
	private:
		const int num;
};

int main()
{
	init_prime();
	SuperPrime sp(113);
	if(sp.isPrime()) {
		printf("sp is a prime\n");
	}
	if(sp.sumBit().isPrime()) {
		printf("sp'sumbit is a prime\n");
	}
	if(sp.multiBit().isPrime()) {
		printf("sp'multibit is a prime\n");
	}
	if(sp.squareSumBit().isPrime()) {
		printf("sp'squareSumBit is a prime\n");
	}
}
