//f(n)�����Ķ���Ϊ0~n�а�����1�ĸ���
//f(13)��0~13�а���1���� 1��10��11��12��13������f(13)=6
//f(1) = 1��
//����һ��f(n)=n��nֵ
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

