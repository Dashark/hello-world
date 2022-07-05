//f(n)函数的定义为0~n中包含的1的个数
//f(13)是0~13中包含1的有 1，10，11，12，13，所以f(13)=6
//f(1) = 1。
//求另一个f(n)=n的n值
// 2021-11-04

#include<stdio.h>
int f(int n){
	int i,sum=0,k;
	for(i=1;i<=n;i++){//13
		for(k=i;k>0;){
			if(k%10==1){
				sum++;
			}
			k=k/10;
		}
	}
	return sum;
}
int main(){
	for(int i=0;i<100;i++){
		if(f(i)==i)
			printf("f(%d)=%d ",i,i);
	}	
	return 0;
}

