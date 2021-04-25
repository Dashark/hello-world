#include <iostream>
#include <vector>
#include <cmath>
class Nature {
	public:
		int num,m,s=0;
	Nature() :num(0) {
	}
	Nature(int n) :num(n) {
	}
	Nature(const Nature& nat) :num(nat.num) {
	}
	~Nature() {
	}
    bool isSuperprime() {
		int  c[3], n[3], sum[2], p;
			c[0]=(num%100)%10;//个位
			c[1]=(num%100)/10;//十位
			c[2]=num/100;//百位 
			n[0]=c[0]*c[0];
			n[1]=c[1]*c[1];
			n[2]=c[2]*c[2];
			sum[0]=c[0]+c[1]+c[2]; //各位数的和 
			sum[1]=n[0]+n[1]+n[2]; //各位数平方的和 
			p=c[0]*c[1]*c[2]; //所有数字之积 
		if (prime(num) && prime(sum[1]) && prime(sum[0]) && prime(p))
		{
			return true;
		}
		else return false;
	}//判断超级素数 
    int prime(int a){
    	if(a == 1 || a == 0)
    return false;
    for(int i = 2; i <= (int)sqrt(a); i++)
    {
      if(a % i == 0)
      return false;
    }
    return true;
  }
	//判断一个数是不是素数 
    int compare(const Nature &nat) {
  	if (num > nat.num)
  	  return 1;
  	else if(num == nat.num)
  	return 0;

  }
};
class Superprime {
private:
	int num,m,s=0;
    std::vector<Nature> natures;
public:
	Superprime(int a, int b)
  {
    // std::cout << "Create SuperPrime from " << a << " to " << b << std::endl;
    for (int i = a; i < b; i++)
    {
      Nature nat(i);
      // std::cout << "HAHA" << std::endl;
      natures.push_back(nat);
      // std::cout << "DDDDD" << std::endl;
    }
  }
  ~Superprime()
  {
    // std::cout << "Destroy SuperPrime " << std::endl;
  }
    Nature max() {
    std::vector<Nature>::iterator it = natures.begin();
    Nature max(0);
		 for (; it != natures.end(); it++)
    {
      if (it->isSuperprime())
      {
        if (max.compare(*it))
        {
          max = *it;
        }
      }
      if (it->isSuperprime())
      {
      	m++;
	  }
	  if(it->isSuperprime())
	  {
	  	s+=it->num;
	  }
    }
    std::cout<<"超级素数的和为："<<s<<std::endl;
    std::cout<<"超级素数的个数为："<<m<<std::endl;
    return max;
	}//最大超级素数 

};
int main() {
    Superprime sp(100, 999);
    Nature n = sp.max();
    std::cout<<"最大的超级素数："<<n.num;
    return 0;
}
