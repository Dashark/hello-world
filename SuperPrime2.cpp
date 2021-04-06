#include <iostream>
class SuperPrime {
private:
  const int left, right;
public:
  SuperPrime(int a, int b):left(a), right(b) {
  }
  int max() {
  	//哪个对象做？ 
    for(int x1 = left; x1 < right; x1++) {
      split(x1);
	  //判断素数 
	}
	
  	return 0;
  }
  int howmany() {
  	return 0;
  }
  int sum() {
  	return 0;
  }
private:
  void split(int x) {
    int a, sum, mult, sqrsum;
    while(x != 0) {
      a = x % 10;
	  sum += a;
	  mult *= a;
	  sqrsum += a*a;
	  x = x / 10;
	}
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
