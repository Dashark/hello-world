#include<iostream>
class Prime {
public:
  Prime(int num);
  ~Prime();

  bool isPrime();

  Prime sumBit();
  Prime multiBit();
  Prime sqaureSumBit();
private:
  const int mNum;
};
Prime::Prime(int num){
  mNUM=num;
}
Prime Prime::sumbit() {
  int a=mNum,sum;
  while(a){
    sum+=num%10;
    a/=10;
  }
  Prime b(sum);
  return b;
}

Prime Prime::multibit() {
 int a=mNum,sum;
  while(a){
    sum*=num%10;
    a/=10;
  }
  Prime b(sum);
  return b;
}

Prime Prime::squaresumbit(Prime num) {
 int a=mNum,sum;
  while(a){
    sum+=(num%10)*(num%10);
    a/=10;
  }
  Prime b(sum);
  return b;
}

bool isprime(int num) {
  for(int i=2;i*i<=num;i++){
    if(num%i==0){
      return false;
    }
  }
  return true;
}
int main() {
  Prime pm(113);
  Prime sb = pm.sumBit();
  Prime mb = pm.multiBit();
  Prime ssb = pm.sqaureSumBit();
  if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime()){
      cout>>"This is prim number">>endl;
  }
    ; //to do sth
  return 0;
}
