#include<iostream>
#include<algorithm>

using namespace std;

class SuperPrime {
private:
	bool nature_range[1000];//素数数组存放
	bool super_range[1000];//超级素数存放
	int left;//左边界
	int right;//右边界
	int count;//数目
public:
	SuperPrime(int a, int b) :left(a), right(b) {
		count = 0;
		for (int i = 0; i < 1000; i++)
		{
			nature_range[i] = false;
		}
		//初始化
		for (int i = 0; i < 1000; i++)
		{
			super_range[i] = false;
		}
		//初始化
		for (int i = 0; i < 1000;i++)
		{
			int flag = 0;
			for (int j = 2; j < i; j++)
			{
				if (i % j == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				nature_range[i] = true;
		}
		//判断素数(0~1000)
		for (int i = a; i <= b; i++)
		{
			if (nature_range[i] == true&&i>100)
			{
				int hun, dec, uni;
				uni = i % 10, dec = (i / 10) % 10, hun = i / 100;
				int sum = uni + dec + hun;//和
				int pro = uni * dec * hun;//积
				int sum_qua = uni * uni + dec * dec + hun * hun;//平方和
				if (nature_range[sum] == true && nature_range[pro] == true && nature_range[sum_qua] == true)
				{
					super_range[i] = true;
					count++;
				}
			}
		}
		//判断超级素数(a~b)
	}
	//构造函数
	~SuperPrime(){}
	//析构函数
	int max();
	int recount();
	int sum_super();
	void print();
};
int SuperPrime::max() {
	for (int i = SuperPrime::right; i > SuperPrime::left; i--)
	{
		if (super_range[i] == true)
		{
			return i;
		}
	}
}
int SuperPrime::recount() {
	return SuperPrime::count;
}
int SuperPrime::sum_super() {
	int sum = 0;
	for (int i = left; i <= right; i++)
	{
		if (super_range[i] == true)
		{
			sum += i;
		}
	}
	return sum;
}
void SuperPrime::print(){
	for (int i = left; i <= right; i++)
	{
		if (super_range[i] == true)
		{
			cout << i << " ";
		}
	}
}
int main()
{
	SuperPrime sup(100, 999);
	cout << "超级素数：";
	sup.print();
	cout << endl;
	cout << "最大值:" << sup.max() << endl;
	cout << "数目：" << sup.recount() << endl;
	cout << "总和：" << sup.sum_super() << endl;
	return 0;
}
