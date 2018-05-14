#include<stdio.h>
#include<math.h>
void function_one(void);
void function_two(void);
void function_three(void);
int mainone()
{
	int choice;
	printf("                1.分离一个数的整数和小数部分。\n");
	printf("                2.对二元一次方程组求解。\n");
	printf("                3.对一个数进行四舍五入运算。\n");
	printf("                                   请输入你想要执行的命令");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:function_one(); break;
	case 2:function_two(); break;
	case 3:function_three(); break;
	default:printf("请输入有效的命令！\n");
		break;
	}
	return 0;
}

void function_one(void)
{
	float k;
	int k_1;
	float k_2;
	printf("                请输入一个带有限小数位的有理数");
	scanf("%f", &k);
	k_1 = k;
	k_2 = k - k_1;
	printf("                %f的整数部分为%d，小数部分为%f\n", k, k_1, k_2);
}

void function_two(void)
{
	float a, b, c, d, e, f;
	printf("                形如｛ax+by=c，dx+ey=f｝的方程组为二元一次方程组\n");
	printf("                请输入a=");
	scanf("%f", &a);
	printf("                请输入b=");
	scanf("%f", &b);
	printf("                请输入c=");
	scanf("%f", &c);
	printf("                请输入d=");
	scanf("%f", &d);
	printf("                请输入e=");
	scanf("%f", &e);
	printf("                请输入f=");
	scanf("%f", &f);
	printf("                该方程组的解为x=%f,y=%f", (c*e - b*f) / (a*e - b*d), (c*d - a*f) / (b*d - a*e));
}

void function_three(void)
{
	float k;
	int a;
	printf("                请输入一个带有限小数位的有理数");
	scanf("%f", &k);
	a = (int)(k + 0.5);
	printf("                %f四舍五入后为%d", k, a);
}