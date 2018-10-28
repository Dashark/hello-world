//求解如下方程组
//ax + by = c
//dx + ey = f
//注意输入/输出，数据类型
#include<stdio.h>
int main(void)
{
	float a, b, c, d, e, f;
	while (scanf("%f%f%f%f%f%f", &a, &b, &c, &d, &e, &f) != EOF)
	{
		if (a*e - b * d == 0)
		{
			if (c*d - e * f != 0)
			{
				printf("y has no answer.\n");
				if (c*e - b * f != 0)printf("x has no answer.\n");
				else printf("x has infinite answers.\n");
				continue;
			}
			if (c*e - b * f != 0)
			{
				printf("x has no answer.\n");
				if (c*d - e * f != 0)printf("y has no answer.\n");
				else printf("y has infinite answers.\n");
				continue;
			}
			printf("x has infinite answers.\n");
			printf("y has infinite answers.\n");
			continue;
		}
		else printf("x=%.2f,y=%.2f", (c*e - b * f) / (a*e - b * d), (c*d - a * f) / (b*d - a * e));
	}
	return 0;
}