#include<stdio.h>
#include<math.h>

int sum_bit(int num) {
	int one=num%10;
	int two=num/10%10;
	int three=num/100%10;
   int test;
   test=one+two+three; 
  return test;

}



int multi_bit(int num) {
	int one=num%10;
	int two=num/10%10;
	int three=num/100%10;
   int test;
 test=one*two*three; 
  return test;

}



int square_sum_bit(int num) {
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



bool isprime(int num) {
	int flag=0;
	for(int i=2;i<=sqrt(num);i++){
		if(num%i==0){
			flag=1;
			break;
		}
	}
	if(!flag){
		return true;
	}
  return false;

}



int main() {
	int n;
	scanf("%d",&n);
  if(isprime(n)&&isprime(sum_bit(n))&&isprime(multi_bit(n))&&isprime(square_sum_bit(n)))
  {
  	printf("it's super primer\n");
  }

return 0;
}
