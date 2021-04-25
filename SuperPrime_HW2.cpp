#include <iostream>
#include <vector>
class Nature {
private:
  int num;
public:
  Nature():num(0){
    std::cout << "Default Create Nature as " << num << std::endl;
  }
  Nature(int n):num(n) {
    std::cout << "Create Nature as " << num << std::endl;
  }
  Nature(const Nature &nat):num(nat.num){
    std::cout << "Copy Create Nature as " << num << std::endl;
  }
  ~Nature() {
    std::cout << "Destroy Nature as " << num << std::endl;
  }
  bool isPrime() {
    if(num == 1 || num == 0)
    return false;
    for(int i = 2; i <= (int)num; i++)
    {
      if(num % i == 0)
      return false;
    }
    return true;
  }
  int compare(const Nature &nat) {
  	if (num > nat.num)
  	  return 1;
  	else if(num == nat.num)
  	  return 0;
  	
  	return -1;
  }
  show()
  {
  	std::cout<<num;
  }
};
class SuperPrime : public Nature {
private:
  int num;
public:
  SuperPrime(int n):num(n) {
  } 
  bool isPrime() {
  	Nature nat(num);
  	return nat.isPrime();
  } 
  bool isSuperPrime()
  {
  	Nature nat1(num);
  	Nature nat2((num/100)+((num%100)/10)+(num%10));
  	Nature nat3((num/100)*((num%100)/10)*(num%10));
  	Nature nat4((num/100)*(num/100)+((num%100)/10)*((num%100)/10)+(num%10)*(num%10));
  	if(nat1.isPrime()&&nat2.isPrime()&&nat3.isPrime()&&nat4.isPrime())
  	return true;
  	else return false;
  }
  int compare(const SuperPrime &nat) {
  	if (num > nat.num)
  	  return 1;
  	else if(num == nat.num)
  	  return 0;
  	
  	return -1;
  }
};
class Container {
private:
  std::vector<SuperPrime> natures;
public:
  Container(int a, int b) {
    std::cout << "Create SuperPrime from " << a << " to " << b << std::endl;
    for(int i = a; i < b; i++) {
      SuperPrime nat(i);
      std::cout << "HAHA" << std::endl;
      if(nat.isSuperPrime())
        natures.push_back(nat);
      std::cout << "DDDDD" << std::endl;
	}
  }
  ~Container() {
    std::cout << "Destroy SuperPrime " << std::endl;
  }
  
  Nature max() {
  	std::vector<SuperPrime>::iterator it = natures.begin();
  	Nature max(0);
  	for(; it != natures.end(); it ++) {
      if (max.compare(*it)) {
  	  	  max = *it;
      }
	}
  	return max;
  }
};
int main() {
  Container sp(100,999);
  Nature n = sp.max(); 
  std::cout<<"最大：";
  n.show();
  
  return 0;
} 
