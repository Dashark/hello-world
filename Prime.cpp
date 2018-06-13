#include<iostream>
using namespace std;
class Prime {
public:
  Prime(int num);
  ~Prime();
  bool isPrime();
  Prime sumBit();
  Prime multiBit();
  Prime sqaureSumBit();
private:
  int mNum;
};
Prime::Prime(int num){
  mNum=num;
}
Prime Prime::sumBit() {
  int a=mNum,sum=0;
  while(a){
    sum+=a%10;
    a/=10;
  }
  Prime b(sum);
  return b;
}

Prime Prime::multiBit() {
 int a=mNum,sum=0;
  while(a){
    sum*=a%10;
    a/=10;
  }
  Prime b(sum);
  return b;
}

Prime Prime::sqaureSumBit() {
 int a=mNum,sum=0;
  while(a){
    sum+=(a%10)*(a%10);
    a/=10;
  }
  Prime b(sum);
  return b;
}

bool Prime::isPrime() {
  for(int i=2;i*i<=mNum;i++){
    if(mNum%i==0){
      return false;
    }
  }
  return true;
}
Prime::~Prime(){
}
int main() {
  Prime pm(113);
  Prime sb = pm.sumBit();
  Prime mb = pm.multiBit();
  Prime ssb = pm.sqaureSumBit();
  if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime()){
      cout<<"This is prim number"<<endl;
  }
    ; //to do sth
  return 0;
}
