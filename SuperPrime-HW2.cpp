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
};
class SuperPrime {
private:
  std::vector<Nature> natures;
public:
  SuperPrime(int a, int b) {
    std::cout << "Create SuperPrime from " << a << " to " << b << std::endl;
    for(int i = a; i < b; i++) {
      Nature nat(i);
      std::cout << "HAHA" << std::endl;
      natures.push_back(nat);
      std::cout << "DDDDD" << std::endl;
	}
  }
  ~SuperPrime() {
    std::cout << "Destroy SuperPrime " << std::endl;
  }
  
  Nature max() {
  	std::vector<Nature>::iterate it = natures.begin();
  	Nature max(0);
  	for(; it != natures.end(); it ++) {
  	  if(it->isSuperPrime()) {
  	  	if (max.compare(*it)) {
  	  	  max = *it;
		}
	  }
	}
  	return max;
  }
};
int main() {
  SuperPrime sp(10, 13);
  Nature n = sp.max(); 
  std::cout << "��󳬼�������" ;
  n.show();
  
  return 0;
} 
