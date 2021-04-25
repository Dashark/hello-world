#include <iostream>
#include <vector>
class Nature 
{
private:
  	int num;
public:
<<<<<<< HEAD:SuperPrime_HW2.cpp
  Nature():num(0){
    std::cout << "Default Create Nature as " << num << std::endl;
  }
  Nature(int n):num(n) {
    std::cout << "Create Nature as " << num << std::endl;
  }
  Nature(const Nature &nat):num(nat.num){
    std::cout << "Copy Create Nature as " << num << std::endl;
  }
  ~Nature() {
    std::cout << "Destroy Nature as " << num << std::endl;
  }
  bool isPrime() {
    if(num == 1 || num == 0)
    return false;
    for(int i = 2; i <= (int)sqrt(num); i++)
    {
      if(num % i == 0)
      return false;
    }
    return true;
  }
  int compare(const Nature &nat) {
  	if (num > nat.num)
  	  return 1;
  	else if(num == nat.num)
  	  return 0;
  	
  	return -1;
  }
private:
};
class SuperPrime : public Nature {
private:
  int num;
public:
  SuperPrime(int n):num(n) {
  } 
  bool isPrime() {
  	Nature nat(num);
  	return nat.isPrime();
  } 
  int compare(const SuperPrime &nat) {
  	if (num > nat.num)
  	  return 1;
  	else if(num == nat.num)
  	  return 0;
  	
  	return -1;
  }
};
class Container {
private:
  std::vector<SuperPrime> natures;
public:
  Container(int a, int b) {
    std::cout << "Create SuperPrime from " << a << " to " << b << std::endl;
    for(int i = a; i < b; i++) {
      SuperPrime nat(i);
      std::cout << "HAHA" << std::endl;
      if(nat.isSuperPrime())
        natures.push_back(nat);
      std::cout << "DDDDD" << std::endl;
	}
  }
  ~Container() {
    std::cout << "Destroy SuperPrime " << std::endl;
  }
  
  SuperPrime max() {
  	std::vector<SuperPrime>::iterate it = natures.begin();
  	Nature max(0);
  	for(; it != natures.end(); it ++) {
      if (max.compare(*it)) {
  	  	  max = *it;
      }
=======
  	/*Nature():num(0)
	{
   		std::cout << "Default Create Nature as " << num << std::endl;
  	}*/
  	Nature(int n):num(n) 
	{
		//std::cout << "Create Nature as " << num << std::endl;
  	}
 	/*Nature(const Nature &nat):num(nat.num)
	{
    	std::cout << "Copy Create Nature as " << num << std::endl;
  	}*/
  	~Nature() 
	{
    	//std::cout << "Destroy Nature as " << num << std::endl;
  	}
  	bool isPrime()
	{
		for (int i = 2; i * i <= num; i++)
		{
			if (num % i == 0)
				return false;
		}
		return true;
	}
  	bool isSuperPrime()
	{
		int xx = num, a, sum = 0, mul = 1, sqrsum = 0;
		while (xx != 0)
		{
			a = xx % 10;
			sum += a;
			mul *= a;
			sqrsum += (a * a);
			xx /= 10;
		}
		Nature mul1(mul), sum1(sum), sqrsum1(sqrsum);
		if (mul == 0)
			return false;
		else if (this->isPrime() && mul1.isPrime() && sum1.isPrime() && sqrsum1.isPrime())
			return true;
		return false;
	}
	int show()
	{
		return num ;
	}
	int compare(const Nature &nat) 
	{
		if (num > nat.num)
			return 1 ;
		else if (num == nat.num)
			return 0 ;
		return -1 ;
	}
	
};
class SuperPrime 
{
private:
  	std::vector<Nature> natures; 
  	int num_of_SP , sum_of_SP , maxn ;
public:
  	SuperPrime(int a, int b) 
	{
    	num_of_SP = 0 ; 
		for(int i = a; i < b; i++) 
		{
      		Nature nat(i);
      		if (nat.isSuperPrime())
			{
				natures.push_back(nat);
				num_of_SP ++ ;
      			std::cout << "num_of_SP ++" << std::endl;
				sum_of_SP += nat.show() ;
				std::cout << "sum_of_SP=" << sum_of_SP << std::endl;
				maxn = nat.show() ;
			}
			    
		}
  	}
	~SuperPrime() 
	{
    	std::cout << "Destroy SuperPrime " << std::endl;
  	}
  
  	int max() 
	{
  		return maxn ;
  	}
  	int number()
  	{
  		return num_of_SP ;
	}
	int sum()
	{
		return sum_of_SP ;
>>>>>>> d2ccf5ff31e58708a3d65150e06c0d259d503ab4:SuperPrime-HW2.cpp
	}
};
int main() 
{
  	SuperPrime sp(100, 999);
  	std::cout << "最大的超级素数：" << sp.max() << std::endl ;
  	std::cout << "超级素数的个数：" << sp.number() << std::endl ;
  	std::cout << "超级素数的和：" << sp.sum()<< std::endl ;

  	
  	return 0;
} 
