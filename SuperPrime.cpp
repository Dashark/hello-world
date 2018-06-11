#include <iostream>
#include <cmath>
using namespace std;
class Prime {
 public:
  Prime(int num) : mNum(num) {};
  ~Prime() {};

  bool isPrime() {
    int n = sqrt(mNum);
    for (int i = 2; i <= n; i++) {
      if (Prime::mNum % i == 0)
        return false;
      }
    return true;
  }
  int print() {
    return mNum;
  }
  Prime sumBit() {
    int n = mNum;
    int ans = 0;
    while (n != 0) {
      ans += (n % 10);
      n /= 10;
    }
    Prime res(ans);
    return res;
  }
  Prime multiBit() {
    int n = mNum;
    int ans = 1;
    while (n != 0) {
      ans *= (n % 10);
      n /= 10;
    }
    Prime res(ans);
    return res;
  }
  Prime sqaureSumBit() {
    int n = mNum;
    int ans = 0;
    while (n != 0) {
      ans += pow(n%10,2);
      n /= 10;
    }
    Prime res(ans);
    return res;
  }
 private:
  const int mNum;
};

class SuperPrime : public Prime {
 public:
  SuperPrime(int num) : Prime(num), num(num) {};
  ~SuperPrime() {};
  bool isSuperPrime() {
    Prime prime(num);
    if (prime.isPrime() && prime.sumBit().isPrime() && prime.multiBit().isPrime() && prime.sqaureSumBit().isPrime()) {
      return true;
    }
      return false;
  }
 private:
  const int num;
};

int main()
{
  SuperPrime sp(113);
  if(sp.isSuperPrime()) {
    cout<<sp.print<<" is a superprime"<<endl;
  }
  return 0;
}
