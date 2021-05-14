#include <iostream>
#include <vector> 
class Nature {
protected:
  int num;
public:
  Nature(int n) {
  	num = n;
  }
  virtual bool isPrime() {
  	for(int i = 2; i < num;i++) {
  	  if(num % i == 0)
  	    return false;
	}
  	return true;
  }
  void show() {
  	std::cout << num << std::endl;
  }
};
class SuperPrime:public Nature {
private:
public:
  SuperPrime(int n):Nature(n) {
  }
  bool isPrime() {
  	int tmp = num + 1;
  	int sum = 0, mul = 1, sqr = 0;
  	while(tmp != 0) {
  	  tmp = tmp / 10;
  	  int x = tmp % 10;
  	  sum += x;
  	  mul *= x;
  	  sqr += x*x;
	}
	Nature nat(sum), nat1(mul), nat2(sqr);
  	return Nature::isPrime() && nat.isPrime() && nat1.isPrime()&& nat2.isPrime();
  }
};
int main() {
  //create some objects
  std::vector<Nature*> sps; 
  for (int i = 100; i < 999; i++) {
  	Nature *nat = new SuperPrime(i);
  	if (nat->isPrime())
  	  sps.push_back(nat);
  }
  std::vector<Nature*>::iterator it;
  for(it=sps.begin(); it!=sps.end();it++) {
  	(*it)->show();
  }
  for(it=sps.begin(); it!=sps.end();it++) {
  	delete *it;
  }
  
  //最大的超级素数 
  return 0;
} 
