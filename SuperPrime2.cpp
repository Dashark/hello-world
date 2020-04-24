//作业：面向对象设计以下框架的代码细节，程序能编译运行得到正确结果 
#include <iostream>
class Prime {
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
	}
	~Prime() {
	}
  	bool isPrime() { 
  	  //2到number-1的因子 
  	  return false;
	}
  private:
  	const int number;
}; 
class SuperPrime : public Prime {
  public:
  	SuperPrime():Prime(0), pset(3) {  //为什么必须有？ 
  	}
  	SuperPrime(int n):Prime(n), pset(3) {
	  // number split into N
	  int temp = n;
	  while(temp > 0) {
	  	int t = temp % 10;
	  	temp /= 10;
	  	pset.add(t);  //作业：单个数字为对象？还是和/积/平方和为对象？ 
	  } 
	}
  	~SuperPrime() {
	}
  	bool isSuperPrime() {
	  if (Prime::isPrime() && pset.isAllPrime())
	    return true; 
  	  return false;
	}
  private:
  	PrimeSet pset;
	int sum() {
	  return 0;
	}
	int multi() {
	  return 0;
	}
	int squareSum() {
	  return 0;
	}
};
class PrimeSet {
  public:
  	PrimeSet(int size) {
  	  //集合的构造什么？ 
  	  N = new Prime*[size];
  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	  for (int i = 0; i < index; ++i)  //销毁对象 
		delete N[i]; 
	  delete[] N;
	}
 	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i]->isSuperPrime())
  	      count += 1;
	  return count; 
	}

	bool add(int n) {
	  if(index == size)  return false;
	  Prime *p = new Prime(n);
	  N[index] = p;
	  index += 1;
	  return true;
	}
	bool isAllPrime() {
	  for(int i = 0; i < index; i++)
	    if (!N[i]->isPrime())
	      return false;
	  return true;
	} 
  private:
  	Prime **set;
	int size, index;
};
class SuperPrimeSet {
  public:
  	SuperPrimeSet(int from, int to) {
  	  size = to - from;
  	  for (int i = from; i < to; i++)
  	    set[i-from] = new SuperPrime(i);
	}
  	~SuperPrimeSet() {
  	  for(int i = 0; i < size; i++)
  	    delete set[i];
	}
  	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i]->isSuperPrime())
  	      count += 1;
	  return count; 
	}
  	int sum() {
  	  int sum = 0;
  	  /*
  	  for (int i = 0; i < size; i++)
  	    if(set[i].isSuperPrime())
  	      sum += set[i];
  	      */ 
	  return sum; 
	}
  private:
  	SuperPrime **set;
  	int size, index;
};
int main() {
  SuperPrime sp(113);
  if (sp.isSuperPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  return 0;
}
