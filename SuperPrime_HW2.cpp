#include <iostream>
#include <vector>
using namespace std;

class Nature
{
private:
  int num;

public:
  Nature() : num(0) {}
  Nature(int n) : num(n) {}
  ~Nature(){};

  void show(){
    cout << num << endl;
  }

  int isPrime(int n)
  {
    if (n < 2)
      return 0;
    for (int i = 2; i <= (n/2); i++)
    {
      if (n % i == 0)
        return 0;
    }
    return 1;
  }

  int compare(Nature it){
    if(it.num > num)
      return 1;
    else 
      return 0;
  }
  int isSuperPrime()
  {
    int bai = num / 100; 
    int shi = (num % 100) / 10;
    int ge = num % 10;
    if (isPrime(num) && isPrime(bai + shi + ge) && isPrime(bai * shi * ge) && isPrime(bai * bai+ shi * shi + ge * ge))
    {
      return 1;
    }
    return 0;
  }
  friend class SuperPrime;
};

class SuperPrime : public Nature
{
private:
  vector<Nature> natures;

public:
  SuperPrime(int a, int b)
  {
    for (int i = a; i < b; i++)
    {
      Nature nat(i);
      if (nat.isSuperPrime())
        {natures.push_back(nat);
          cout << nat.num << endl;
        }
    }
  }

    Nature max()
    {
      vector<Nature>::iterator it = natures.begin();
      Nature max(0);
      for (; it != natures.end(); it++)
      {
        if (max.compare(*it))
            max = *it;
      }
      return max;
    }

    Nature count()
    {
      vector<Nature>::iterator it = natures.begin();
      Nature count(0);
      for (; it != natures.end(); it++)
      {
        count.num++;
      }
      return count;
    }

  Nature sum()
    {
      vector<Nature>::iterator it = natures.begin();
      Nature sum(0);
      for (; it != natures.end(); it++)
      {
        sum.num += it->num;
      }
      return sum;
    }
};

int main()
{
  SuperPrime sp(100, 999);
  Nature max = sp.max();
  Nature count = sp.count();
  Nature sum = sp.sum();
  cout << "超级素数的和是：";
  sum.show();
  cout << "超级素数的最大数是: ";
  max.show();
  cout << "超级素数的个数是： ";
  count.show();
  return 0;
}

