#include <iostream>
#include <vector>
class Nature {
private:
  int num;
public:
  Nature():num(0){
  }
  Nature(int n):num(n) {
  }
  Nature(const Nature &nat):num(nat.num){
  }
  ~Nature() {
  }
  bool isSuperPrime() const
  {
    for(int i=100;i<=999;i++)
      {
        int j;
        for(j=2;j<i;j++)
        {
          if(i%j==0)
            {
              return false;
            }
        }
        if(j==i)
        {
          int number[3],k=i;
          for(int ni=0;ni<3;ni++)
          {
            number[ni]=k%10;
            k=k/10;
          }
          int NumberSum=number[0]+number[1]+number[2];
          for(int ni=2;ni<NumberSum;ni++)
          {
            if(NumberSum%ni==0)
            {
                return false;
            }
          }
          int NumberMult=number[0]*number[1]*number[2];
          for(int ni=2;ni<NumberMult;ni++)
          {
            if(NumberMult%ni==0)
            {
                return false;
            }
          }    
          int NumberSqrt=number[0]*number[0]+number[1]*number[1]+number[2]*number[2];
          for(int ni=2;ni<NumberSqrt;ni++)
          {
            if(NumberSqrt%ni==0)
            {
                return false;
            }
          }
          return true;
        }
      }
  }
  bool compare(Nature p){
    
  }
  void show(){

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
<<<<<<< HEAD:SuperPrime-HW2.cpp
  int LowLimit,HighLimit;
  std::vector<Nature> natures;
public:
  SuperPrime(int a, int b):LowLimit(a),HighLimit(b){
    for(int i = a; i < b; i++) {
      Nature nat(i);
      natures.push_back(nat);
	}
  }
  ~SuperPrime() {
  }
  
  Nature max() {
  	std::vector<Nature>::iterator it = natures.begin();
=======
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
>>>>>>> upstream/master:SuperPrime_HW2.cpp
  	Nature max(0);
  	for(; it != natures.end(); it ++) {
      if (max.compare(*it)) {
  	  	  max = *it;
      }
	}
  	return max;
  }
};
int main() {
  SuperPrime sp(100,999);
  Nature n = sp.max(); 
  n.show();  
  return 0;
} 
