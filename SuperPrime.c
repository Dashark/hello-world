//超级素数：它本身，各位数字的和，各位数字的平方和，都是素数。
//求 100~10000 内的所有超级素数，及它们的平均数。
#include<stdio.h> 
int isPrime(int x);
int *splitNum(int x, int *num);
int main()
{
	int num[4];
	int x,i;
	int z=0;
	float prime[9900];
	for(x=100;x<10000;x++){
		for(i=0;i<4;i++)
			num[i]=0;
		splitNum(x,num);
		if(isPrime(x)){
			int sum=0;
			for(i=0;i<4;i++)
			sum+=*(num+i);
			if(isPrime(sum)){
				int sqsum=0;
				for(i=0;i<4;i++)
				sqsum+=num[i]*num[i];
				if(isPrime(sqsum)){
					printf("%d ",x);
					prime[z]=x;
					z++;
				}	
			}
		}
	}
	float sum=0.00;
	for(i=0;i<z;i++)
		sum+=prime[i];
	printf("平均数：%f\n",sum/z);
    return 0;
}
int *splitNum(int x, int *num){
	int n=0;
	do{
		*(num+n)=x%10;
		x=x/10;
		n++;
	}while(0!=x);
	return num;
} 
int isPrime(int x){
	int i;
	int flag=1;
	for(i=2;i<x;i++){
		if(x%i==0){
			flag=0;
			break;	
		}		
	}
	if(flag)
	return 1;
	else
	return 0;	
}

