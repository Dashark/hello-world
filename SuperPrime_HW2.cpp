#include <iostream>
#include <vector>
class Nature {
private:
  int num;
public:
	Nature():num(0) {}
	Nature(int n):num(n) {}
	Nature(const Nature &nat):num(nat.num){}
	~Nature() {}
	
    Nature show() { 
		std::cout << num << std::endl;
	}
	
	bool Prime(int n) {
	  	int m;
		if(n<=1)
		  return false;
	    for(m=2;m*m<=n;m++)
	      	if(n%m==0) return false;
	    return true;
  	}
  
	bool isSuperPrime() {
	  	int sum, mul, square_sum,b,c,d;
	  	
	  	b = num / 100;
		c =  (num - b*100) / 10;
		d = num % 10;
		sum = d + b + c;
		mul = d * b * c;
		square_sum = d*d + b*b +c*c;
		if(Prime(num)&&Prime(sum)&&Prime(mul)&&Prime(square_sum)) 
		   return true;
		return false;
	}
	int getnum() {
		return num;
	}
};

class SuperPrime {
private:
   std::vector<Nature> natures;
public:
    SuperPrime(int a, int b) {
    	for(int i = a; i < b; i++) {
     		Nature nat(i);
     		if(nat.isSuperPrime()){
     			natures.push_back(nat);
			}
		}
  	}
  	~SuperPrime() {
  	} 
 
  	Nature max() {
	  	std::vector<Nature>::iterator it = natures.begin();
	  	int m = 0;
	  	for(; it != natures.end(); it ++) {
	  		int num = it->getnum();
	  	  	m = num>m?num:m;
		}
	  	return Nature(m);
  	}
  	Nature sum(){
	  	std::vector<Nature>::iterator it = natures.begin();
	  	int sum = 0;
	  	for(; it != natures.end(); it ++) {
	  		int num = it->getnum();
	  	  	sum += num;
		}
		return Nature(sum);
	  }
	Nature number(){
	  	std::vector<Nature>::iterator it = natures.begin();
	  	int number = 0;
	  	for(; it != natures.end(); it ++) {
	  		number++;
		}
		return Nature(number);
	}
};

int main() {
  SuperPrime sp(100,999);
  Nature n = sp.max(); 
  Nature sum = sp.sum();
  Nature number = sp.number(); 
  std::cout << "最大的超级素数为：" << std::endl;
  n.show();  
  std::cout << "超级素数之和为：" << std::endl; 
  sum.show();
  std::cout << "超级素数数量为：" << std::endl;
  number.show(); 
  return 0;
}
