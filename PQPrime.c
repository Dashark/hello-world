// 求 p 和 q
// 当 p 和 q 都是素数，求 p 和 q
#include<stdio.h>
#include<math.h>
#define N 300 //range of p
int Isprime(float x);
int main(){
	
	for(float p=3;p<=N;p++){
		for(float q=2;p>q;q++){
				int a=pow(p,q);
				int b=pow(q,p);
				if(Isprime(a+b) /*&& Isprime(q) && Isprime(p)*/)
				printf("%g %g\n",p,q);
			}
		}
	}


int Isprime(float x){
	int a=(int)x;
	for(int i=2;i*i<=a;i++){
		if(!(a%i))
		return 0;
	}
	return 1;
}
