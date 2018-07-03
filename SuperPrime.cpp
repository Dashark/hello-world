#include<iostream>
#include<math.h>
class Prime {
public:
  Prime(int num){
  	mNum=num;
  }
  ~Prime();

  bool isPrime(){
  	int flag=0;

	for(int i=2;i<=sqrt(mNum);i++){

		if(mNum%i==0){

			flag=1;

			break;

		}

	}

	if(!flag){

		return true;

	}

  return false;
  }
private:
  const int mNum;
};
class SuperPrime: public Prime {
public:
  SuperPrime(int num){
  	this->num=num;
  }
  ~SuperPrime();

  bool isPrime(){
  		int flag=0;

	for(int i=2;i<=sqrt(mNum);i++){

		if(mNum%i==0){

			flag=1;

			break;

		}

	}

	if(!flag){

		return true;

	}

  return false;
  	
  }

  Prime sumBit(){
  	int one=num%10;

	int two=num/10%10;

	int three=num/100%10;

   int test;

   test=one+two+three; 

  return test;



  }
  Prime multiBit(){
  	int one=num%10;

	int two=num/10%10;

	int three=num/100%10;

   int test;

 test=one*two*three; 

  return test;
  }
  Prime sqaureSumBit(){
  		int test;

		int one=num%10;

	

		one*=one;

	int two=num/10%10;

	two*=two;

	int three=num/100%10;

	three*=three;

   

 test=one+two+three; 

  return test;

  }
private:
  const int num;
}
int main()
{
    SuperPrime sp(113);
    if(sp.isPrime()) {
       cout<<"it's super primer'" ;
    }
}
