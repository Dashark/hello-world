#include <stdio.h>



int main(){
	float target = 2.0f;
	float left = 0.0f;
	float right = target;
	float mid = (left + right)/2;
	while((mid*mid - 2) > 0.01 ||(2 - mid*mid)> 0.01){
		if (mid*mid < target){ 
			left = mid;
		}
		else{
			right = mid;
		}
	   mid = (left + right)/2; 
	}
	printf("%f",mid);
	return 0;
}
