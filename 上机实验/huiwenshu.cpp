//回文数猜想

#include<iostream>

int inverse(int n)
{
	int sum = 0;
	while(n!=0)
	{
		sum = sum*10+n%10;
		n/=10;
	}
	return sum;
}

class number
{
public:
	number(int a):num(a){}
	int Isinverse();
private:
	const int num;
};

int number::Isinverse()
{
	int n = inverse(num);
	int m = num;
	while(m!=n)
	{
		if(m<=0||n<=0) return 0;
		m += n;
		n = inverse(m);
		std::cout<<m<<'\n'; 
	}
	return m;
}

int main()
{
	int n;
	std::cin >> n;
	number NUM(n);
	if(NUM.Isinverse()==0) std::cout << "No\n";
	else std::cout << NUM.Isinverse() << '\n';
	return 0;
}
