#include<iostream>
int func_1(int in);
int func_2(int in);
using namespace std;
int main()
{
	int in , th=0 , max , sum=0 ;
	for (in=100 ; in <= 999 ; in++ )
	{
		if(func_1(in) == 1)
		{
			th++;
			max = in ;
			sum += in ;
			cout << in << endl ;
		}
	}
	cout << "超级素数的个数为："  << th
		 << endl << "所有超级素数之和为：" << sum
		 << endl << "最大的超级素数为：" << max << endl ; 
}

int func_1(int in)
{
	int fin = 0;
	int sum_2 , po ,ping ;
	int a , b , c ;
	
	a = in / 100 ;
	b = (in - 100 * a ) / 10 ;
	c = in % 10 ;
	
	sum_2 = a+b+c;
	po = a*b*c;
	ping = a*a + b*b + c*c ;
	
	fin = ( func_2(in) + func_2(sum_2) + func_2(po) + func_2(ping) ) ;
	
	if (fin == 0 )
	return 1;
	else return 0;
}

int func_2(int in)
{
	int k , va=0 ;
	for ( k=2 ; k < in ; k++)
	{
		if ( in % k == 0)
		va++; 
	}
	if(va == 0)    //若数in是素数，则返回0//
		return 0;
	else return 1;
}
