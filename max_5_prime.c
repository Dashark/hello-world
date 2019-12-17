//小明有 5 张数字卡片，上面分别为数字 1， 2， 3， 6， 9。小明想用这 5 张数字卡片组成一个最大的 5 位
//素数，这个五位数是_______。
//编程：任意输入5个数字，将它们组合为最大的5位素数输出。如果不存在5位素数，则输出ERROR。
#include<stdio.h>
int main()
{
	int i, j, b, c, d, temp, x, y=0;
	int num=0;
	int a[5];
	
	for(i=1;i<=5;i++)
	{
	   scanf("%d ", &a[i]);//输入 
	}
	

	
	for(i=1;i<=5;i++)
	{
		num=a[i];
		for(j=1;j<=5;j++)
		{
			num=10*num + a[j];
			if(j!=i)
			{
				for(b=1;b<=5;b++)
				{
					num=10*num + a[b];
					if(b!=j&&b!=i)
					{
						for(c=1;c<=5;c++)
						{
							num=10*num + a[c];
							if(c!=b && c!=j && c!=i)
							{
								for(d=1;d<=5;d++)
								{
									num=10*num + a[d];
									if(d!=c&&d!=b&&d!=j&&d!=i)
									{
										for(x=2;x<num;x++)
										{
											if(num>y)
											{ 
										  	if(num%x==0)
										  	{
												y = num;
										  	}
											} 							
											else
										  		break;
										}	
									}
									else
								  		break; 
								}
							}
							else
								break;
						}
					}
					else
						break;
				}
			}
	 	} 
	} 
     printf("%d\n", y);
	 return 0;
	
 } 
