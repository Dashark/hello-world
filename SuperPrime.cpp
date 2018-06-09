#include<iostream>
#include<vector>
using namespace std;

class Prime {
public:
  Prime(int num):mNum(num){}
  ~Prime();

  bool isPrime();
  void show();
private:
  const int mNum;
};

class SuperPrime : public Prime {
public:
  SuperPrime(int num): Prime(num), num(num){}
  ~SuperPrime();

  virtual bool isPrime();

  Prime sumBit();
  Prime multiBit();
  Prime squareSumBit();
private:
  const int num;
};

int main()
{
    SuperPrime sp(113);
    if(sp.isPrime()) {
        cout << "113 is a SuperPrime."<<endl; // do something
    }
    //version 1
    for(int i = 1; i < 1000; i++) {
      if(Prime(i).isPrime() && SuperPrime(i).isPrime()) {
        cout << i << "is a SuperPrime." << endl;
      }
    }
    //version 2
    int i = 1000;
    vector <Prime*> PreSP;
    while(i--) {
      if(Prime(i).isPrime()) 
        PreSP.push_back(new SuperPrime(i))
    }
    for(auto one:PreSP) {
      if(one->isPrime() {
        one->show();
      }
    }
    return 0;
}    

bool Prime::isPrime() {
  int i = 2, m =mNum;
  if (m==0) {
    return false;
  }
  for (;i <= m/i;i++){
    if (m % i == 0){
      return false;
	  }
  }
   return true;
}

Prime SuperPrime::sumBit(){
  int a = (num/1000)+(num%1000/100)+(num%100/10)+(num%10);
  Prime p(a);
  return p;
}

Prime SuperPrime::multiBit(){
  int a = 1,m,n;
  a = n = num%10;
  m = num;
  while((m = m/10) != 0){
    n = m % 10;
    a *= n;
  }
  Prime p(a);
  return p;
}

Prime SuperPrime::squareSumBit(){
  int a = (num/1000)*(num/1000)+(num%1000/100)*(num%1000/100)+(num%100/10)*(num%100/10)+(num%10)*(num%10);
  Prime p(a);
  return p;
}

bool SuperPrime::isPrime() {
  if(this->sumBit().isPrime() && this->multiBit().isPrime() && this->squareSumBit().isPrime()) {
    return true;
  }
}

void SuperPrime::show() {
  cout << this->num << "is a SuperPrime." << endl;
  return;
}