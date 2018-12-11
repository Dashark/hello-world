//回文数：正读与反读相等的数
//2018/11/14 更新
#include <stdio.h>
#include <string.h>
int main(){
	int k,n,i,j,T,num1=0,num;
	int a[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&T);
		j=0;num=T;
		while(T>0){
			a[j]=T%10;
			T/=10;
			j++;
		}
		k=0;
		while(k<j){
			num1=num1*10+a[k];
			k++;
		}
		if(num==num1)
		printf("yes\n");
		else
		printf("no\n");
	}
} 
