/*满足下列条件的自然数称为超级素数:
该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.
例如113就是一个超级素数.求[100,9999]之内:
(1)超级素数的个数.
(2)所有超级素数之和.
(3)最大的超级素数.*/
#include<iostream>

class Prime {
public:
  Prime(int num): mNum(num){}
  ~Prime(){}

  bool isPrime();

  Prime sumBit();
  Prime multiBit();
  Prime sqaureSumBit();
private:
  const int mNum;
};

Prime Prime::sumBit()
{
	int sum = 0;
	int temp = mNum;
	while(true)
	{
		if(temp == 0)  break;
		sum += temp%10;
		temp /= 10;
	}
	Prime Temp(sum);
	return Temp;
}

Prime Prime::multiBit()
{
	int Mul = 1;
	int temp = mNum;
	while(true)
	{
		if(temp == 0)  break;
		Mul *= temp%10;
		temp /= 10;
	}
	Prime Temp(Mul);
	return Temp;
}

Prime Prime::sqaureSumBit()
{
	int sum = 0;
	int temp = mNum;
	while(true)
	{
		if(temp == 0)  break;
		sum += (temp%10)*(temp%10);
		temp /= 10;
	}
	Prime Temp(sum);
	return Temp;
}

bool Prime::isPrime()
{
	int temp = mNum;
	if(temp == 1) return false;
	if(temp == 0) return false;
	for(int i = 2;i < mNum;i++)
	{
		if(temp % i==0) return false;
	}
	return true;
}

int main() {
  // Prime pm(101);
  // Prime sb = pm.sumBit();
  // Prime mb = pm.multiBit();
  // Prime ssb = pm.sqaureSumBit();
  // if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime())
  // 	std::cout << "it is a super prime" << '\n';
  // else std::cout << "it isn't a super prime" << '\n';

 int sum = 0;
 for(int i = 100;i <=9999 ;i++)
  {
	  Prime pm(i);
	  Prime sb = pm.sumBit();
	  Prime mb = pm.multiBit();
	  Prime ssb = pm.sqaureSumBit();
	  if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime())
	  	{
			std::cout << i << "		it is a super prime" << '\n';
			sum++;
		}
	  //else std::cout << "it isn't a super prime" << '\n';
  }
  std::cout << "the sum is  " << sum <<'\n';
  return 0;
}
