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
int sum_bit(int num) {
 int sum=0;
  while(num){
    sum+=num%10;
  }
  if(isprime(sum)){
    return ture;
  }
  return 0;
}

int multi_bit(int num) {
  int sum=0;
  while(num){
    sum*=(num%10);
    num%=10;
  }
  if(isprime(sum)){
    return ture;
  }
  return 0;
}

int square_sum_bit(int num) {
  int sum=0;
  while(num){
    sum+=(num%10)*(num%10);
    num%=10;
  }
  if(isprime(sum)){
    return ture;
  }
  return 0;
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
  if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime())
    ; //to do sth
  return 0;
}
