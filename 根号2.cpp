#include <stdio.h>
#include <math.h>
int main(){ 
float n = 3;
float mysqrt(n); 
float x = n/2;
	while (x - n > 0.0001 || n - x > 0.0001){
		if (x*x > n)
		  x = (0+x)/2;
		else
		  x = (x+n)/2;
	}
	printf("%f",x);
	return 0.0f;
return 0;
}
