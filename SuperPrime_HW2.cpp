#include <iostream>
#include <vector>
using namespace std;

class Nature
{
private:
  int num;

public:
  Nature() : num(0) {}
  Nature(int n) : num(n) {}//num=n 
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
  }//？？ 
  int isSuperPrime()
  {
    int a = num / 100; //baiwei
    int b = (num % 100) / 10;
    int c = num % 10;
    if (isPrime(num) && isPrime(a + b + c) && isPrime(a * b * c) && isPrime(a * a + b * b + c * c))
    {
      return 1;
    }
    return 0;
  }
  friend class SuperPrime;//将SuperPrime作为友元函数 
};

class SuperPrime : public Nature//继承 
{
private:
  vector<Nature> natures;//pushback   begin end  iterator  等操作不会 
//natures保存Nature类型的对象 是一个空的vector 
public:
  SuperPrime(int a, int b)
  {
    // cout << "Create SuperPrime from " << a << " to " << b << endl;
    for (int i = a; i < b; i++)
    {
      Nature nat(i);
      if (nat.isSuperPrime())
        {natures.push_back(nat.num);//为什么这里nat.num可以被访问 
        //push_back 把一个值加到natures的尾端 
          
        }
    }
  }

    Nature max()
    {
      vector<Nature>::iterator it = natures.begin();
      Nature max(0); 
      
      for (; it != natures.end(); it++)// end 尾后迭代器 
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
        sum.num += it->num;//==(*it).num 
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
  cout << "SuperPrime's Sum is："; //因为num是private  所以只能通过成员函数来访问 
  sum.show();
  cout << "SuperPrime's Max is: ";
  max.show();
  cout << "SuperPrime's Num is: ";
  count.show();
  return 0;
}

