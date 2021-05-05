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
  	if(num < 2)
	  return false; 
  	for(int i = 2; i < num;i++) {
  	  if(num % i == 0)
  	    return false;
	}
  	return true;
  }
 int compare(const Nature* nat) {
  	if (num > nat->num)
  	  return 1;
  	else if(num == nat->num)
  	  return 0;
  	
  	return -1;
  }
  void show() {
  	std::cout << num << std::endl;
  }
  void add(int x){
  	this->num += x;
  }
  int getNum(){
  	return this->num;
  }
};

class SuperPrime:public Nature {
private:
public:
  SuperPrime(int n):Nature(n) {
  }
  bool isPrime() {
  	int tmp = num;
  	int sum = 0, mul = 1, sqr = 0;
  	while(tmp != 0) {
  	  int x = tmp % 10;
  	  tmp = tmp / 10;
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
  Nature max(0);
	Nature sum = 0;
  Nature number(0);
 
  for(it=sps.begin(); it!=sps.end();it++) {
  	sum.add((*it)->getNum());
	 number.add(1);
	if(max.compare(*it)){
  		max = **it;
	  }
  }
  max.show();
  sum.show();
  number.show();
  for(it=sps.begin(); it!=sps.end();it++) {
  	delete *it;
  }
  
  //最大的超级素数 
  return 0;
}
