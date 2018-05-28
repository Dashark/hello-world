#include<iostream>
#include<string>
#include<math.h>
using namespace std; 
class Prime {
public:
  Prime(int num);
  ~Prime();

  bool isPrime();
private:
  const int mNum;
};
class SuperPrime : public Prime {
public:
  SuperPrime(int num);
  ~SuperPrime();

  bool isPrime();

  Prime sumBit();
  Prime multiBit();
  Prime sqaureSumBit();
private:
  const int num;
  
};
int main()
{
    SuperPrime sp(113);
    if(sp.isPrime()) {
    	//cout<<sp.isPrime()<<endl;
        cout<<"do something//is SuperPrime"<<endl; // do something
    }
    return 0;
}
Prime::Prime(int num):mNum(num){}

bool Prime::isPrime(){
	int flag=0;
	for(int i=2;i<=sqrt(mNum);i++){
		if(mNum%i==0){
			flag=1;
			break;
		} 
	}
	if(flag==1){
		
		return false;
	}
	else{
		return true;
	}
}
SuperPrime::SuperPrime(int num):num(num),Prime(num){
}
bool SuperPrime::isPrime(){
	if(sumBit().isPrime()&&multiBit().isPrime()&&sqaureSumBit().isPrime()){
		return true;
	}
	else{
		return false;
		
	}

}
SuperPrime::~SuperPrime(){

}
Prime::~Prime(){
	
}
Prime SuperPrime::sumBit(){
	int m=this->num;
	int sum=0;
	while(m!=0){
		sum+=m%10;
		m=m/10;
	}
	return Prime(sum); 
}
Prime SuperPrime::multiBit(){
	int m=this->num;
	int sum=1;
	while(m!=0){
		sum*=m%10;
		m=m/10;
	}
	return Prime(sum); 
}
Prime SuperPrime::sqaureSumBit(){
	int m=this->num;
	int sum=0;
	while(m!=0){
		sum+=(m%10)*(m%10);
		m=m/10;
	}
	return Prime(sum); 
}
