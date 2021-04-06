#include <iostream>
#include <stdio.h>

int superprime(int a)
{
	int i, k = 0, m;
	for(i = 2; i < a; i++)
	{
		m = a % i;
		if(m == 0)
		{
			k = 0;
			break;
		}
		k = 1;	
	}

	return k;
}
int main()
{
	int m1, m2, m3, m4, n, a, b, c, sum = 0, t = 0, max;
	for(n = 100; n <= 999; n++)
	{
		a = n / 100;
		c = n % 10;
		b = (n - a * 100 - c) / 10;
		m1 = superprime(n);
		m2 = superprime(a + b + c);
		m3 = superprime(a * b * c);
		m4 = superprime(a*a + b*b + c*c);
		if(m1 * m2 * m3 * m4 == 1)
		{
			sum += n;
			t++;
			max = n;
		}
	}
	printf("%d %d %d", t, sum, max);
	
	return 0;
}
