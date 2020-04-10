//作业：完成以下框架的代码细节，程序能编译运行得到正确结果 
#include <iostream>
class SuperPrime {
  public:
  	SuperPrime():number(0) {
	}
  	~SuperPrime() {
	}
  	bool isSuperPrime() {
  	  split();
  	  int a = sum();
	  int b = multi();
	  int c = squareSum();
	  if (isPrime(number) && isPrime(a) && isPrime(b) && isPrime(c))
	    return true; 
  	  return false;
	}
	int number;
  private:
  	int N[100], size,i;
  	bool isPrime(int n) { 
	  	int flag=1;
		for(i=2;i<n;i++){
			if(n%i==0){
				flag=0;
				break;	
			}		
		}
		if(flag)
		return 1;
		else	
  		return false;
	}
	void split() {
		int n=0;
		do{
			N[n]=number%10;
			number=number/10;
			n++;
		}while(0!=number);
	  // number split into N
	}
	int sum() {
		int sum=0;
		for(i=0;i<4;i++)
			sum+=*(N+i);
	  return sum;
	}
	int multi() {
		int mul=1;
		for(i=0;i<4;i++)
			mul*=N[i];	
	  return mul;
	}
	int squareSum() {
		int sqsum=0;
		for(i=0;i<4;i++)
			sqsum+=N[i]*N[i];
	  return sqsum;
	}
};
class Set {
  public:
  	Set(int from, int to) {
  	  size = to-from;
  	  for(int i = from; i < to; ++i)
  	  set[i] = NULL;
	}
  	~Set() {
	  	for(int i = 0; i < size; ++i)
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
  	  for (int i = 0; i < size; i++)
  	    if(set[i]->isSuperPrime())
  	      sum += set[i]->number;
	  return sum; 
	}
  private:
  	SuperPrime *set[1000];
  	int size;
};
int main() {
  Set ss(100, 999);
  std::cout << "How Many: " << ss.count() << std::endl;
  std::cout << "Sum is " << ss.sum() << std::endl;
  return 0;
}
