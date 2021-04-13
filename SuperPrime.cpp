#include <iostream>
#include <vector>
class Nature {
private:
  int num;
public:
  Nature(int n):num(n) {
  }
};
class SuperPrime {
private:
  std::vector<Nature> natures;
public:
  SuperPrime(int a, int b) {
    //std::cout << "Create SuperPrime from " << a << " to " << b << std::endl;
    for(int i = a; i < b; i++) {
      Nature nat(i);
	  natures.push_back(nat);  
	}
  }
};
int main() {
  SuperPrime sp(100, 999);
  return 0;
} 
