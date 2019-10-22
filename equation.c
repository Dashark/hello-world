#include<stdio.h> 
#include<math.h>

int main(){
	float m , n , z;
	scanf("%f%f",&m,&n);
	z = fabs(m - n);
	if(z < 1e-5){
		printf("equal");
	} 
	else {
	printf("not equal");
	}
	return 0;
}
