#include <iostream>

using namespace std;
bool check (int a)
{
	while (a % 2 == 0)
	{
		a /= 2;
	}
	return a == 1; //如果表达式成立返回true 不成立返回false 可以直接返回表达式的值 
}
long long cal(int n)
{
	long long sum = 0;
	for(int i = 1; i <= n; i++)
	{
		if(check(i))
		sum -= i;
		else
		sum += i;
	}
	return sum;
}
int t, n;
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << cal(n) << endl;
	}
	return 0;
}
