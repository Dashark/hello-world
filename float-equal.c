
#include <stdio.h>
int main()
{
    float m = 1.78;
    float x = 1.779999, y = 2;
    float z = m / y, z1 = x / y;
    float n = z - z1;
	if(n > 0.00009999){
    	printf("not equal");
	}
	else{
		z = ( m + x ) / y;
	}
	printf("z is %.2f\n",z);
	printf("z1 is %f\n",z1);
	return 0;
}
