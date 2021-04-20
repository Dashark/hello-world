#include<iostream>
#include<vector>
class  Nature {
	private:
		int prime , sum , num , num_;
	int number , a , b , c ;
		int own_sum , own_p , own_double ;
	public:	
	Nature():num_(0) {
	}int prime_(int pri)
		{
			prime = pri;
			int i = 2 ;
			int k = 0;
			for( ; i < prime ; i++)
			{
				if(prime % i == 0)
				k++;
			}
			if(k == 0)
				return prime;
			else return 0;
		};
		int var_1_sum(int pri , Nature my)
		{
		number = pri;
		a = number % 10 ;
		b = (number / 10) % 10 ;
		c = number / 100 ;
		own_sum = a+b+c;
		if(my.prime_(own_sum) == 0)
			return 0;
		else return 1;
		};
		int var_2_p(int pri , Nature my)
		{
		number = pri;
		a = number % 10 ;
		b = (number / 10) % 10 ;
		c = number / 100 ;
		own_p = a*b*c;\
		if(my.prime_(own_p) == 0)
			return 0;
		else return 1;	
		};	
		int var_3_double(int pri , Nature my)
		{
		number = pri;
		a = number % 10 ;
		b = (number / 10) % 10 ;
		c = number / 100 ;
		own_double = a*a + b*b + c*c;
		if(my.prime_(own_double) == 0)
			return 0;
		else return 1;	
		};
		int superprime(int pri , Nature my)
		{
			prime = pri ;
			if(my.prime_(prime) != 0)
			if(my.var_1_sum(prime , my) == 1)
			if(my.var_2_p(prime , my) == 1)
			if(my.var_3_double(prime , my) == 1)
					return 1;
			else return 0;
		};
		int superprime_num(Nature my)
		{
			num=0 ;
			for(prime = 100 ; prime <= 999 ; prime++)
			{
				if(my.superprime(prime , my) != 0)
				num++;
			};
			return num;
		};
		
		int superprime_sum(Nature my)
		{
			sum=0;
			for(prime = 100 ; prime <= 999 ; prime++)
			{
				if(my.superprime(prime , my) != 0)
				sum += prime;
			};
			return sum;
		};
		
		int superprime_max(Nature my)
		{
			for(prime =999 ; prime >= 100 ; prime--)
			{
			if(my.prime_(prime) != 0)
			if(my.var_1_sum(prime , my) == 1)
			if(my.var_2_p(prime , my) == 1)
			if(my.var_3_double(prime , my) == 1)
				return prime;
			}
		};
};

class SuperPrime 
{
private:
  std::vector<Nature> natures;
  int my_ , num__ , prime_  ;
public:
  SuperPrime(int a, int b) 
  {
  	num__=0 ;
	for(prime_ = 100 ; prime_ <= 999 ; prime_++)
		{
		if(my_ != 0)
		num__++;
		};
  }
  ~SuperPrime(){}
};
int main()
{
	SuperPrime prime(100,999);
	Nature super;
	std::cout << "超级素数的个数："<< super.superprime_num(super)<<std::endl;
	std::cout << "所有超级素数之和："<< super.superprime_sum(super)<<std::endl;
	std::cout << "最大的超级素数："<< super.superprime_max(super)<<std::endl; 
	return 0 ;
}
