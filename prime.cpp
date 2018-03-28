#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

class Prime {

public:

  Prime(int num):mNum(num) {}

  ~Prime();



  bool isPrime();
	
	

  Prime sumBit();

  Prime multiBit();

  Prime sqaureSumBit();

private:
	
  const int mNum;
  
  

};



Prime::~Prime(){

	return;

}

Prime Prime::sumBit() {

	int a = 0;

	int b = mNum;

    while(b != 0){

    	a += b % 10;

    	b /= 10;

	}

	Prime p(a);

	return p;

}



Prime Prime::multiBit() {

	int a = 1;

	int b = mNum;

  	while(b != 0){

    	a *= b % 10;

    	b /= 10;

	}

	Prime p(a);

	return p;

}



Prime Prime::sqaureSumBit() {

	int a = 0;

	int b = mNum;

  	while(b != 0){

    	a += b % 10 * b % 10;

    	b /= 10;

	}

	Prime p(a);

	return p;

}



bool Prime::isPrime() {

    if(mNum % 2 == 0) return false;

    for(int i = 3;i * i < mNum;i+=2){

		if(mNum % i == 0){

			return false;

		}

    }

    return true;

}



int main() {
	int count=0;
	int allsum=0;
	int maxin=0;
	for(int i=100;i<9999;i++){
		Prime pm(i);

  		Prime sb = pm.sumBit();

  		Prime mb = pm.multiBit();

  		Prime ssb = pm.sqaureSumBit();

  		if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime()){
  				allsum+=i;
  				count++;
  				maxin=i;
  			}
	}
	
		cout<<count<<" "<<allsum<<" "<<maxin<<endl;
  

    //to do sth

  return 0;

}
