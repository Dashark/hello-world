#include <iostream>
#include <vector>
class Nature
{
private:
	int num;

public:
	Nature(int n)
	{
		num = n;
	}
	~Nature() {}

	bool isPrime()
	{
		for (int i = 2; i * i <= num; i++)
		{
			if (num % i == 0)
				return false;
		}
		return true;
	}
	bool isSuperPrime()
	{
		int xx = num, a, sum = 0, mul = 1, sqrsum = 0;
		while (xx != 0)
		{
			a = xx % 10;
			sum += a;
			mul *= a;
			sqrsum += (a * a);
			xx /= 10;
		}
		Nature mul1(mul), sum1(sum), sqrsum1(sqrsum);
		if (mul == 0)
			return false;
		else if (this->isPrime() && mul1.isPrime() && sum1.isPrime() && sqrsum1.isPrime())
			return true;
		else
			return false;
	}
	int show()
	{
<<<<<<< HEAD
<<<<<<< HEAD
		return num;
=======
		return num ;
>>>>>>> a4bb835fa3c3d18aba01162082cc1be822c7b46f
=======
		return num;
>>>>>>> d2062996a9aeb4aa58738d425f92646cb9620d22
	}
};

class SuperPrime
{
private:
	std::vector<Nature> range;

public:
	SuperPrime(int a, int b)
	{
		for (int i = a; i < b; i++)
		{
			Nature nat(i);
			if (nat.isSuperPrime())
				range.push_back(nat);
		}
	}
	int max()
	{
		int Max = 0;
		for (std::vector<Nature>::iterator it = range.begin(); it != range.end(); it++)
		{
			if (it->show() > (it + 1)->show())
				Max = it->show();
			else
				Max = (it + 1)->show();
		}
		return Max;
	}

	int sum()
	{
		int Sum = 0;
		for (std::vector<Nature>::iterator it = range.begin(); it != range.end(); it++)
		{
			Sum += it->show();
		}
		return Sum;
	}

	int howmany()
	{
		return range.size();
	}
};

int main()
{
	SuperPrime sp(100, 999);
<<<<<<< HEAD
<<<<<<< HEAD
	std::cout << "è¶…çº§ç´ æ•°çš„ä¸ªæ•°ï¼š" << sp.max() << std::endl;
	std::cout << "æ‰€æœ‰çš„è¶…çº§ç´ æ•°ä¹‹å’Œï¼š" << sp.sum() << std::endl;
	std::cout << "æœ€å¤§çš„è¶…çº§ç´ æ•°ï¼š" << sp.howmany() << std::endl;
=======
	std::cout << "³¬¼¶ËØÊýµÄ¸öÊý£º" << sp.max() << std::endl;
	std::cout << "ËùÓÐµÄ³¬¼¶ËØÊýÖ®ºÍ£º" << sp.sum() << std::endl;
	std::cout << "×î´óµÄ³¬¼¶ËØÊý£º" << sp.howmany() << std::endl;
>>>>>>> a4bb835fa3c3d18aba01162082cc1be822c7b46f
=======
	std::cout << "è¶…çº§ç´ æ•°çš„ä¸ªæ•°ï¼š" << sp.max() << std::endl;
	std::cout << "æ‰€æœ‰çš„è¶…çº§ç´ æ•°ä¹‹å’Œï¼š" << sp.sum() << std::endl;
	std::cout << "æœ€å¤§çš„è¶…çº§ç´ æ•°ï¼š" << sp.howmany() << std::endl;
>>>>>>> d2062996a9aeb4aa58738d425f92646cb9620d22
	return 0;
}
