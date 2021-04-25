#include <iostream>
#include <vector>
#include<cmath>
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
  bool isPrime(int sum) {
    if(num == 1 || num == 0)
    return false;
    for(int i = 2; i <= (int)sqrt(num); i++)
    {
      if(num % i == 0)
      return 0;
    }
    return 1;
  }
  bool isSuperPrime(int sum){
  	    int a, b, c;
		a = num % 10;
		b = (num / 10) % 10;
		c = num / 100;
		int m , n , t ;
		m = a + b + c;
		n = a * b * c;
		t = a * a + b * b +c * c;
		if(isPrime(m) && isPrime(n) && isPrime(t)){
			return 1;
		}
		return 0;
  }
  int compare(Nature &nat) {
  	if (num > nat.num)
  	  return 1;
  	else if(num == nat.num)
  	  return 0;
  	
  	return -1;
  }
  class SuperPrime;
};
class SuperPrime : public Nature

{
private:
  std::vector<Nature> natures;
public:

  SuperPrime(int a, int b)
  {
    // cout << "Create SuperPrime from " << a << " to " << b << endl;
    for (int i = a; i < b; i++)

    {

      Nature nat(i);
      if (nat.isSuperPrime(i))
        {natures.push_back(nat);
          std::cout << "SuperPrime£º"  << nat.num << endl;
        }
    }
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
  Nature count(){
  	std::vector<SuperPrime>::iterator it = natures.begin();
  	Nature count(0);
  	for(;it != natures.end(); it++){
  		count++;
	  }
	  return count;
  }
  Nature sum(){
  	std::vector<SuperPrime>::iterator it = natures.begin();
  	Nature sum(0);
  	for(;it != natures.end(); it++){
  		sum += it;
	  }
	  return sum;
  }
};

int main() {
  SuperPrime sp(10, 13);
  Nature n = sp.max(); 
  std::cout << "ï¿½ï¿½ó³¬¼ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½" ;
  n.show();
  
  return 0;
} 
