#include <iostream>
using namespace std;

class superprime{
private:
	bool prime[1000];//素数存放组
	bool super[1000];//超级素数存放组
	int left, right;
	int n;
public:
	superprime(int p, int q) : left(p), right(q){ //初始化表
		for (int p = 100; p < 1000; p++)
		{
			prime[p] = false;
			super[p] = false;
		}//初始化
		int t, m, a, b, c;
		for (n = 0; n <= 999; n++)
		{
			for (t = 2; t < n; t++)
			{
				m = n % t;
				if (m == 0)
				{
					prime[n] = false;
					break;
				}
				prime[n] = true;
			}
		}//存放素数
		for (n = 100; n <= 999; n++)
		{
			if (prime[n])
			{
				a = n / 100;
				c = n % 10;
				b = (n - a * 100 - c) / 10;
				int sum = a + b + c;
				int multiple = a * b * c;
				int mulsum = a * a + b * b + c * c;
				if (prime[sum] == true && prime[multiple] == true && prime[mulsum] == true)//直接在素数组里找
					super[n] = true;//超级素数存放
			}
		}
	}//构造函数
	~superprime(){}//析构函数
	int max();
	int sum_super();
	int count();
};
int superprime::max()
{
	int max = 0;
	for (int i = 100; i <= 999; i++)
	{
		if (super[i])
			max = i;
	}
	return max;
}
int superprime::sum_super()
{
	int sum_super = 0;
	for (int i = 100; i <= 999; i++)
	{
		if (super[i])
			sum_super += i;
	}
	return sum_super;
}
int superprime::count()
{
	int count = 0;
	for (int i = 100; i <= 999; i++)
	{
		if (super[i])
			count++;
	}
	return count;
}
int main()
{
	superprime sup(100,999);
	cout << "最大值为" << sup.max() << endl;
	cout << "总和为" << sup.sum_super() << endl;
	cout << "超级素数个数" << sup.count() << endl;

	return 0;
}