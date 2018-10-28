//求解一元二次方程的根
//查阅sqrt()函数
//注意有没有解
#include<stdio.h>
#include<math.h>
int main(void)
{
	float a, b, c;
	while (scanf("%f%f%f", &a, &b, &c) != EOF)
	{
		if (a == 0) {
			if (b == 0) {
				if (c == 0)printf("There are infinite answers.\n");
				else printf("There is no answer to x.\n");
			}
			else printf("x=%.2f", -c / b);

		}
		else {
			if (b*b - 4 * a*c < 0)printf("There is no answer to x.\n");
			else {
				printf("x1=%.2f\n", (-b + sqrt(b*b - 4 * a*c)) / (2 * a));
				printf("x2=%.2f\n", (-b - sqrt(b*b - 4 * a*c)) / (2 * a));
			}
		}
	}
	return 0;
}