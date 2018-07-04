#include<bits/stdc++.h>
class Prime {
public:
  Prime(int num):mNum(num){ }
  ~Prime(){ }

  bool isPrime();

  Prime sumBit();
  Prime multiBit();
  Prime sqaureSumBit();

private:
  const int mNum;
};

bool Prime::isPrime() {
  int tmp = (int)sqrt((double)Prime::mNum);
  for (int i = 2; i <= tmp; ++i) {
    if (Prime::mNum % i == 0)
      return false;
  }
  return true;
}

Prime Prime::sumBit() {
  int tmp = Prime::mNum;
  int ans = 0;
  while (tmp != 0) {
    ans += (tmp % 10);
    tmp /= 10;
  }
  Prime res(ans);
  return res;
}

Prime Prime::multiBit() {
  int tmp = Prime::mNum;
  int ans = 1;
  while (tmp != 0) {
    ans *= (tmp % 10);
    tmp /= 10;
  }
  Prime res(ans);
  return res;
}

Prime Prime::sqaureSumBit() {
  int tmp = Prime::mNum;
  int ans = 0;
  while (tmp != 0) {
    ans += (tmp % 10) * (tmp % 10);
    tmp /= 10;
  }
  Prime res(ans);
  return res;
}


int main() {
  Prime pm(113);
  Prime sb = pm.sumBit();
  Prime mb = pm.multiBit();
  Prime ssb = pm.sqaureSumBit();
  if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime())
    ; //to do sth
  return 0;
}
