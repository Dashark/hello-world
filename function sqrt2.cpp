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
	///printf("%f",mid); �������ص���mid�������ֵ������mid��������� 
	return 0;
}

///�����ж�������������������ʡ�ԣ� float squart(float x,float y,float z){}      float����ʡ�� 
