#include <iostream>
#include <vector>
#include <math.h>
class Nature {
public:
  int num;
  int k=0,sum=0;
public:
  Nature():num(0){
  }
  Nature(int n):num(n) {;}
  Nature(const Nature &nat):num(nat.num){ ; }
  
  ~Nature() { ; }
  bool IsPrime(int num) {
    if(num == 1 || num == 0)
    return false;
    for(int i=2;i<=(int)sqrt(num);i++)
    {
      if(num % i == 0)
      return false;
    }
    return true;
  }
  bool isSuperPrime(int num) {
  	int a=num/100;
  	int b=(num/10)%10;
  	int c=num%10;
  	int n1=a+b+c,n2=a*b*c,n3=a*a+b*b+c*c;
  	if(IsPrime(num)&&IsPrime(n1)&&IsPrime(n2)&&IsPrime(n3))
  	{
  		return true;
    }
  	return false;
  } 
  int compare(const Nature &nat) {
  	if (num > nat.num)
  	  return 1;
  	else if(num == nat.num)
  	  return 0;
  }
};
class SuperPrime {  
private:
  int num;
  int k=0;
  int sum=0;
  std::vector<Nature> natures;
public:
  SuperPrime(int a, int b) {
    for(int i = a;  i< b; i++) {
    	Nature nat(i);//把数字转化为对象 
    	if(nat.IsPrime(i))
    		natures.push_back(nat);
	}
  }
  ~SuperPrime() {;}
    int compare(const SuperPrime &nat) {
  	if (num >nat.num)
  	  return 1;
  	else if(num == nat.num)
  	  return 0;
  }
  Nature max() {
    std::vector<Nature>::iterator it = natures.begin();
  	Nature max(0);
  	for(; it != natures.end(); it ++) {
      if(it->isSuperPrime(it->num))
      {
      	if (max.compare(*it)) {
  	  	  max = *it;
      }
      k++;
      sum+=it->num;
	  }
	}
  	return max;
  }
  void show()
  {
  	std::cout<<"超级素数的个数为："<<k<<std::endl;
	std::cout<<"超级素数的和为：" <<sum<<std::endl;
  }
};

int main() {
    SuperPrime sp(100,1000);
    Nature n=sp.max();
    std :: cout << "最大的超级素数是" << n.num<< std :: endl;
    sp.show();
  return 0;
} 
