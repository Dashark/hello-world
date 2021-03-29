#include<stdio.h> 
int prime(int a){
	int i;
	int b = 0;
	for( i = 2; i <= a; i++){
		if(a % i == 0){
			b = b + 1;
		}
	}
	if(b == 1){
		return 1;
	}
	else{
	 return 0;
	}
}
int main(){
	int i ;
	int q = 0;
	int sum = 0;
	int f = 0;
	for(i = 100; i < 1000; i++ ){
		int a, b, c;
		a = i % 10;
		b = (i / 10) % 10;
		c = i / 100;
		int m , n , t ;
		m = a + b + c;
		n = a * b * c;
		t = a * a + b * b +c * c;
		prime(m);
		prime(n);
		prime(t);
		if( prime(m) == 1 && prime(n) == 1 && prime(t) == 1){
			q = q + 1;
			sum = sum + i;
			f = i;
		}	
	}
	printf("超级素数的个数是%d\n", q);
	printf("超级素数之和为%d\n", sum);
	printf("最大超级素数是%d\n", f);
	return 0;
}
