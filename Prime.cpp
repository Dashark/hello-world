#include<iostream>
#include<math.h>
using namespace std;
class Prime {

public:

  Prime(int num);

  ~Prime();



  bool isPrime();



  Prime sumBit();

  Prime multiBit();

  Prime sqaureSumBit();

private:

  const int mnum;

};
bool Prime::isPrime(){
	int flag=0;

	for(int i=2;i<=sqrt(mnum);i++){

		if(mnum%i==0){

			flag=1;

			break;

		}

	}

	if(!flag){

		return true;

	}

  return false;


	
}
Prime Prime::multiBit(){
	int one=mnum%10;

	int two=mnum/10%10;

	int three=mnum/100%10;

   int test;

 test=one*two*three; 

  return test;


}
Prime::Prime(int num){
	mnum=num;
	
}
Prime Prime::sqaureSumBit(){
	int test;

		int one=mnum%10;

	

		one*=one;

	int two=mnum/10%10;

	two*=two;

	int three=mnum/100%10;

	three*=three;
test=one+two+three; 

  return test;

	
}
Prime Prime::sumBit(){
	
	int one=mnum%10;

	int two=mnum/10%10;

	int three=mnum/100%10;

   int test;

   test=one+two+three; 

  return test;


}



int main() {

  Prime pm(113);

  Prime sb = pm.sumBit();

  Prime mb = pm.multiBit();

  Prime ssb = pm.sqaureSumBit();

  if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime()){
  	cout<<"it's super primer"<<endl;
  }


  return 0;

}
