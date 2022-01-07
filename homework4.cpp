#include<stdio.h>
int isPrime(int b){ 	
	int n,cont=0;
	if(b==2){
		return 1;
	}
	if(b<=0)return 0;
	for(n=2;n<b;n++){
		if(b%n==0)cont++;
	}
	if(cont!=0) return 0;
	else return 1;
}
int ab(int a,int b){
	int ret1=1,ret2=1;
	int i=0;
	for(i=0;i<b;i++){
		ret1*=a;
	}
	for(i=0;i<a;i++){
		ret2*=b;
	}
	return ret1+ret2;
}
int main(){
	int p,q;
	for(p=0;p<10;p++){
		for(q=0;q<10;q++){
			if(isPrime(p)==1&&isPrime(q)==1&&isPrime(ab(p,q))){
				printf("%d %d\n",p,q);
			}	
		}
	}
	
	return 0;
}
