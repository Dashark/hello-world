#include <iostream>
class Nature {
private: 
  int num;  //数 
public:
  Nature();
  ~Nature();
  Nature add(Nature sp);    //求和 
  bool compare(Nature sp) {  //比大小 
     if(num > sp.num)
       return true;
    return false;
  }
	
};
class SuperPrime {
private: 
  const unsigned int num;  //数 
public:
  SuperPrime(int n):num(n) {
  }
  ~SuperPrime() {
  }
  Nature add(SuperPrime sp) {    //求和 
     return Nature(num + sp.num);
 }
  bool compare(SuperPrime sp) {  //比大小 
     if(num > sp.num)
       return true;
    return false;
  }
};
int main() {
  Nature sum(0);
  for(int i = 100; i < 999; i++) {
    Nature sp1(i);
    if ( sp1.isPrime() )
      sum = sum.add(sp1);
  }
  return 0;
} 
