#include <iostream>
#include <vector>
class Nature {
private: 
  const int num;  //数 
public:
  Nature(int n):num(n) {
  }
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
  std::vector<Nature> range;  //超级素数的容器 
public:
  SuperPrime(int a, int b) {
  	for(int i = a; i < b; i++) {
  	  Nature nat(i);
  	  if(nat.isSuperPrime()) //过滤器 
  	    range.push_back(nat);
    }
  }
  int max() {
  	for(std::vector<Nature>::iterate it = range.begin();
	      it != range.end(); it++) {
	  if(it->compare())
	} 
  	return 0;
  }
 
  int howmany() {
  	return range.size();
  }
  int sum() {
  	for(std::vector<Nature>::iterate it = range.begin();
	      it != range.end(); it++) {
    }
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
