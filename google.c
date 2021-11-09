//f(n)函数的定义为0~n中包含的1的个数
//f(13)是0~13中包含1的有 1，10，11，12，13，所以f(13)=6
//f(1) = 1。
//求另一个f(n)=n的n值
// 2021-11-04
#include<stdio.h>
long f(long number);

int main(){
	long i=2;
	for(;f(i)!=i;i++){
		printf("%ld %ld\n",i,f(i));
	}
	
	printf("%ld is the target",i);
	return 0;
}
long f(long number){
	long a=number;
	
	if(a==1)
	return 1;
	
	int b[30]={0},self=0;
	
	for(int i=0;a>0;a/=10,i++){
		b[i]=a%10;
		if(b[i]==1)
		self++;
	}
	long ret=self+f(number-1);
	return ret;
	
	
}
