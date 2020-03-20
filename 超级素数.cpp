#include<stdio.h>
int isPrime(int x);
int splitNum(int x);

int main()
{
	int spprime[1000];
	for(int i=0;i < 100;i++){
		spprime[i] = 0;
	}
	
	int IP = 0,sum = 0;
	int average;
	for(int i=100;i < 10000;i++){
		if(isPrime(i) == 1&&splitNum(i) == 1){
			spprime[IP] = i;
			printf("%d ",i);
			sum += i;
			IP++;		
		}
	}
	
	average = sum/IP;
	
	printf("\n");
	printf("%d",average);
    return 0;
}
isPrime(int x){
	int num = 0;
	for(int i=1;i < x;i++){
		if(x%i == 0){
			num++;
		}
	}
	if(num == 1){
		return 1;
	}
	else return 0; 
} 
splitNum(int x){
	int num[4];
	num[0] = x/1000;
	num[1] = (x-1000*num[0])/100;
	num[2] = (x-1000*num[0]-100*num[1])/10;
	num[3] = x-1000*num[0]-100*num[1]-10*num[2];
	
	int sum = 0 ;
	int sum0 = 0;
	for(int i=0;i < 4;i++){
		sum += num[i];
		sum0 += num[i]*num[i];
	}
	
	int num1=0,num2=0;
	for(int i=1;i < sum;i++){
		if(sum % i == 0){
			num1++;
		}
	}
	
	for(int i=1;i < sum0;i++){
		if(sum0%i == 0){
			num2++;
		}
	}
	
	
	if(num1 == 1 && num2 == 1){
		return 1;
	}
	else return 0;
}
