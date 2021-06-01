#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Nature {
private:
  int num;
public:
  Nature():num(0){
    //std::cout << "Default Create Nature as " << num << std::endl;
  }
  Nature(int n):num(n) {
    //std::cout << "Create Nature as " << num << std::endl;
  }
  Nature(const Nature &nat):num(nat.num){
    //std::cout << "Copy Create Nature as " << num << std::endl;
  }
  ~Nature() {
    //std::cout << "Destroy Nature as " << num << std::endl;
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
  int sum(const Nature &nat){
    return num+=nat.num;
  }
};

class SuperPrime : public Nature { //继承
private:
  int num;
public:
  SuperPrime(int n):num(n) {
  } 
  bool isSuperPrime() {
  	Nature nat(num),nat1(0),nat2(0),nat3(0);
    operation(nat1,nat2,nat3);
    if(nat.isPrime()&&nat1.isPrime()&&nat2.isPrime()&&nat3.isPrime())
    {
      return true;
    }
  	else
    {
      return false;
    }
  }
  /*int compare(const SuperPrime &nat) {
  	if (num > nat.num)
  	  return 1;
  	else if(num == nat.num)
  	  return 0;
  	
  	return -1;
  }*/
  void operation(Nature nat1,Nature nat2,Nature nat3)
    {
      int number[3];
      for(int ni=0;ni<3;ni++)
      {
        number[ni]=num%10;
        num=num/10;
      }
      int NumberSum=number[0]+number[1]+number[2];
      nat1=NumberSum;
      int NumberMult=number[0]*number[1]*number[2];
      nat2=NumberMult;
      int NumberSqrt=number[0]*number[0]+number[1]*number[1]+number[2]*number[2];
      nat3=NumberSqrt;
    }
  void out()
  {
    cout<<num<<endl;
  }
};

class Container {
private:
  std::vector<SuperPrime> natures;
public:
  Container(int a, int b) {
    //std::cout << "Create SuperPrime from " << a << " to " << b << std::endl;
    for(int i = a; i < b; i++) {
      SuperPrime nat(i);
      //std::cout << "HAHA" << std::endl;
      if(nat.isSuperPrime())
        natures.push_back(nat);
      //std::cout << "DDDDD" << std::endl;
	  }
  }
  ~Container() {
    std::cout << "Destroy SuperPrime " << std::endl;
  }
  
  SuperPrime max() {
  	std::vector<SuperPrime>::iterator it = natures.begin();
  	SuperPrime max(0);
  	for(; it != natures.end(); it ++) {
      if (max.compare(*it)) {
  	  	  max = *it;
      }
	  }
  	return max;
  }
  SuperPrime sum()
  {
    std::vector<SuperPrime>::iterator it = natures.begin();
  	SuperPrime sum(0);
    for(; it != natures.end(); it ++) {
      sum.sum(*it);
	  }
    return sum;
  }
  SuperPrime total()
  {
    return natures.size();
  }
};
int main() {
  Container sp(100,999);
  SuperPrime max=sp.max(),sum=sp.sum(),total=sp.total();
  std::cout <<"The Total Of Super Prime:";
  total.out();
  cout<<endl;
  std::cout <<"The Sum Of Super Prime:";
  sum.out();
  cout<<endl;
  std::cout <<"The Max Of Super Prime:";
  max.out();
  cout<<endl;
  return 0;
}