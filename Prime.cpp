#include <iostream>
using namespace std;
class Prime {
public:
  Prime(int num);
  ~Prime();

  bool isPrime();

  Prime sumBit();
  Prime multiBit();
  Prime squareSumBit();

  int show();
private:
  const int mNum;
};

Prime::Prime(int a):mNum (a){}

Prime::~Prime(){}

bool Prime::isPrime() {
  int i = 2, m =mNum;
  bool a = true;
  for (;i <= m/i;i++){
    if (m%i==0){
      a = false;
		break;
	}
  }
   if (m==0)
	  a = false;
  return a;
}

Prime Prime::sumBit(){
  int a = (mNum/1000)+(mNum%1000/100)+(mNum%100/10)+(mNum%10);
  Prime p(a);
  return p;
}

Prime Prime::multiBit(){
  int a = 1,m,n;
  a = n = mNum%10;
  m = mNum;
  while((m = m/10) != 0){
    n = m%10;
    a *= n;
  }
  Prime p(a);
  return p;
}

Prime Prime::squareSumBit(){
  int a = (mNum/1000)*(mNum/1000)+(mNum%1000/100)*(mNum%1000/100)+(mNum%100/10)*(mNum%100/10)+(mNum%10)*(mNum%10);
  Prime p(a);
  return p;
}

int Prime::show(){
  return mNum;
}
int main() {
  int sum, count, max;
  sum = count = max = 0;
  for(int n = 100; n <= 9999; n++){
    Prime pm(n);
    Prime sb = pm.sumBit();
    Prime mb = pm.multiBit();
    Prime ssb = pm.squareSumBit();
    if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime()){
      max = pm.show();
      count++;
      sum += max;//to do sth
    }
  }
  cout<<"超级素数的个数为"<<count<<endl;
  cout<<"所有超级素数之和为"<<sum<<endl;
  cout<<"最大的超级素数为"<<max<<endl;
  
  return 0;
}
