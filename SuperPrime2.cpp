#include <iostream>
class SuperPrime {
private:
  const int left, right;
public:
  SuperPrime(int a, int b):left(a), right(b) {
  }













  int max() {
  	return 0;
  }
  int howmany() {
  	return 0;
  }
  int sum() {
  	return 0;
  }
};












int main() 
{
  SuperPrime sp(100, 999);
  std::cout << "最大的超级素数：" << sp.max() << std::endl;
  std::cout << "超级素数个数：" << sp.howmany() << std::endl;
  std::cout << "超级素数的和：" << sp.sum() << std::endl;
  return 0;
} 
