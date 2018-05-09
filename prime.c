/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:
(1)超级素数的个数.
(2)所有超级素数之和.
(3)最大的超级素数.*/
#include<stdio.h>
#include<math.h>

 
int sum_bit(int num) {
	int sum1=0;
	while(num!=0){
		sum1+=num%10;
		num/=10;
	}
  return sum1;

}



int multi_bit(int num) {
	int mul=1;
	while(num!=0){
		mul*=num%10;
		num/=10;
	}
  return 0;

}



int square_sum_bit(int num) {
	int sum2=0;
	while(num!=0){
		sum2+=(num%10)*(num%10);
		num/=10;
	}
  return sum2;

}



bool isprime(int num) {
	int x=0;
	int i=0;
	for(i=2;i<num;i++){
		if(num%i==0){
			x=1;
			break;
		}
	}
	if(x==1){
		  return false;
	}
	else{
		return true;
	}


}



int main() {
	int i=0,j=0;
	int flag=0;
	int sum=0;
	int maxin=0;
	long long int allsum=0;
	for(i=100;i<=9999;i++){
	
	if(isprime(i)&&isprime(sum_bit(i))&&isprime(multi_bit(i))&&isprime(square_sum_bit(i))){
		sum++;
		allsum+=i;
		maxin=i;
	}
	
	}
  
	printf("%d %lld %d",sum,allsum,maxin);
    //to do sth

}
