#include <stdio.h>

int Primenum(int n)
{
	int k = 0, i, m;
	for(i = 2; i < n; i++)
	{
		if(n % i == 0)
		break;
		k++;
	}//素数判断 
	if(k == n - 2)
		m = 1;
	else m = 0;
	return m;
}

int main()
{
	int n1, n2, n3, n4, k1, k2, k3, k4, m1 = 0, m2 = 0, m3 = 0, m4, a, b, c, num = 0, max;
	long int sum = 0;
	for(n1 = 100; n1 <= 999; n1++)
	{
		a = n1 / 100;
		c = n1 % 10;
		b = (n1 - 100 * a - c) / 10;
	m1 = Primenum(n1);//该数本身为素数判断标志 
	n2 = a + b + c;
	m2 = Primenum(n2);//三位数字和为素数判断标志 
	n3 = a * b * c;
	m3 = Primenum(n3);//三位数字乘积为素数判断标志 
	n4 = a*a + b*b + c*c;
	m4 = Primenum(n4);//三位数字平方和为素数判断标志
	if(m1 ==1 && m2 == 1 && m3 == 1 && m4 == 1)
	{
		num++;
		max = n1;
		sum += n1;
	}
	}
	printf("%d %d %d", num, max, sum);
	
	return 0;
}
