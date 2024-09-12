#include <iostream>
#include <vector>
#include<stdio.h>
class Nature {
private:
  int num;
public:
  Nature():num(0){
    //std::cout << "Default Create Nature as " << num << std::endl;
  }
  Nature(int n):num(n) {
    //std::cout << "Create Nature as " << num << std::endl;
  }
  Nature(const Nature &nat):num(nat.num){
    //std::cout << "Copy Create Nature as " << num << std::endl;
  }
  ~Nature() {
    //std::cout << "Destroy Nature as " << num << std::endl;
  }
  bool isSuperPrime(){
  	int p[1000] = {0};
	int pp[1000] = {0};
	int i = 2; 
	for(;i < 1000;i++){//筛数法 
		p[i] = i;
	}
	
	int j = 0;
	i = 2;
	for(; i < 1000;i++){//生成一个纯净的素数数组 
		if(p[i] == 0){
			continue;
		}
		pp[j] = p[i];
	
		//printf("A%d %d\n",pp[j],j);
	
		j++;
		int k = 2;
		for(;(i * k) < 1000;k++){
			p[i * k] = 0;
		}
	}
	
	int ppn = j;
	int countsp = 0;
	int sumsp = 0;
	int max = 0;
	int judge = 0;
	int t;
    for(t = 25; t < ppn;t++){
        num = pp[t];
		int g = num % 10;
		int s = (num - g) % 100 / 10;
		int b = (num - 10 * s - g) / 100;
		int sum = g + s + b;
		int mul = g * s * b;
		int mul2 = g * g + s * s + b * b;
		
		//printf("E%d %d %d %d \n",sp,g,s,b);
		
		judge = 0;
		for(j = 0;j < ppn;j++){
			if(pp[j] == sum){
				judge++;
				
				//printf("Q1\n");
				
				break;
			}
		}
		
		//printf("go\n");
		
		for(j = 0;j < ppn;j++){
			if(pp[j] == mul){
				judge++;
				
				//printf("Q2\n");
				
				break;
			}
		}
		;
		for(j = 0;j < ppn;j++){
			if(pp[j] == mul2){
				judge++;
				
				//printf("Q3\n");
				
				break;
			}
		}
		
		if(judge == 3){
			return true;
		}
  return false;
  }
}  
  bool compare(Nature a){
  	if(num < a.num){
  		return true;
	  }
  	return false;
  }
  int show(){
  	std::cout<< "max:"<< num <<std::endl;
  }
};
class SuperPrime {
private:
  std::vector<Nature> natures;
public:
  SuperPrime(int a, int b) {
    //std::cout << "Create SuperPrime from " << a << " to " << b << std::endl;
    for(int i = a; i < b; i++) {
      Nature nat(i);
      //std::cout << "HAHA" << std::endl;
      natures.push_back(nat);
      //std::cout << "DDDDD" << std::endl;
	}
  }
  ~SuperPrime() {
    //std::cout << "Destroy SuperPrime " << std::endl;
  }
  
  Nature max() {
  	std::vector<Nature>::iterator it = natures.begin();
  	Nature max(0);
  	for(; it != natures.end(); it++) {
  	  if(it->isSuperPrime()) {
  	  	
  	  	if (max.compare(*it)) {
  	  	  max = *it;
		}
	  }
	}
  	return max;
  }
  
};
int main(){
  SuperPrime sp(100, 999);
  Nature n = sp.max(); 
  //std::cout << "max:"<<   ;
  //the three numbers,howmany are they,the max of them.
  n.show();//the max of them
 
  return 0;
}
