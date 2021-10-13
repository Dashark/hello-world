#include <stdio.h>
float squart(float value){
	float left = 0.0f;
	float right = value;
	float mid = (left + right)/2;
	while((mid*mid - 2) > 0.01 ||(2 - mid*mid)> 0.01){
		if (mid*mid < value){ 
			left = mid;
		}
		else{
			right = mid;
		}
	   mid = (left + right)/2; 
	}
	return mid;
}

int main(){
float target = 2.0f;
printf("%f",squart(target)); 
	///squart(2.0f);
	///printf("%f",mid); 函数返回的是mid代表的数值，不是mid这个变量。 
	return 0;
}

///函数中定义多个变量类型名不能省略： float squart(float x,float y,float z){}      float不能省略 
