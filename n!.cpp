//求输入正整数的阶乘 
#include <stdio.h>
int main(){
    int a;
    int b = 1;
    scanf("%d",&a);
    while(a > 1){
    	
		b = a * b;
        a--;
	}
	printf("%d",b);
	
	return 0 ;
	
}
