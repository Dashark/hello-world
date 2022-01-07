#include <stdio.h>
int main(){
	int a, n, m, p, sum1 = 0, sum2 = 0, sum3 = 0;
	printf("please put into a number between 0 and 100:  ");
	scanf("%d",&a);
	
	for(n = 0; n <= a; n = n +1){
		sum1 = sum1 + n;
	}
	printf("%d\n",sum1);                   //for
	
	while(m <= a){
	    sum2 = sum2 + m;
		m++;	
	}
	printf("%d\n",sum2);                  //while
	
	do{
	    p++;
		sum3 = sum3 + p;	
	}while(p < a);
	printf("%d\n",sum3);                  //do while
	
	
	return 0;
	
} 
