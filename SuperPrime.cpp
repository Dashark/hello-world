class Number {
public:
  Number(int num);
  ~Number();

  bool isPrime();
private:
  const int mNum;
};
class SuperPrime : public Number {
public:
  SuperPrime(int num);
  ~SuperPrime();

  bool isPrime();

  Prime sumBit();
  Prime multiBit();
  Prime sqaureSumBit();
private:
  const int num;
}
int main()
{
    SuperPrime sp(113);
    if(sp.isPrime()) {
        ; // do something
    }
}
