#include <iostream>
#include <vector>
class Nature {
private:
  int num;
public:
  Nature():num(0){
  } 
  Nature(int n):num(n) {
    
  }
  Nature(const Nature &nat):num(nat.num){
    
  }
  ~Nature() {
    
  }
  bool isPrime(int x)
  {
  	int i;
	for(i=2;i<=x;i++)
	{
		if(x%i==0&&i!=x)
		break;
		if(x%i==0&&i==x)
		return true;
	}
	return false;
  }
  bool isSuperPrime()
  {
  	    int t=num;
		int b;
		int a1=1,a2=0,a3=0;
		do
		{
			b=t%10;
			a1*=b;
			a2+=b;
			a3+=b*b;
			t/=10;
		}while(t>0);
		if(isPrime(a1)==1&&isPrime(a2)==1&&isPrime(a3)==1&&isPrime(num)==1){
         return true;
	    }
	    else
		return false;
  }
  bool compare(const Nature(&nat))
  {
    if(nat.num > num)
    {
      return true;
    }
    else
    return false;
  }
  int show(){
  	return num;
  }
  friend class SuperPrime;
};
class SuperPrime {
private:
  std::vector<Nature> natures;
public:
  SuperPrime(int a, int b)
   {
  
    for(int i = a; i < b; i++) {
      Nature nat(i);
      natures.push_back(nat);
	}
   }
  ~SuperPrime() {
  	
   }
  
   Nature max() {
  	std::vector<Nature>::iterator it = natures.begin();
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
    Nature cnt()
	{
  	std::vector<Nature>::iterator it = natures.begin() ;
  	Nature cnt(0);
  	for(;it!=natures.end();it++){
  		if(it->isSuperPrime()){
  			cnt.num++;
		  }
	  }
	return cnt;
	}
	Nature sum(){
	std::vector<Nature>::iterator it = natures.begin() ;
	Nature sum(0);
	for(;it!=natures.end();it++){
		if(it->isSuperPrime()){
			sum.num+=it->num;
		}
	}
	return sum;	
	} 
	
};
int main() {
  SuperPrime sp(100, 999);
  Nature n = sp.max();
  Nature m = sp.cnt();
  Nature o = sp.sum();
  std::cout << "超级素数最大值为" << n.show()<<std::endl;
  std::cout <<"超级素数的个数为"<<m.show()<<std::endl;
  std::cout <<"超级素数的和为"<<o.show()<<std::endl; 
  return 0;
}
