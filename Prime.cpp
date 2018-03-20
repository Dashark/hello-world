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

int main() {
  Prime pm(113);
  Prime sb = pm.sumBit();
  Prime mb = pm.multiBit();
  Prime ssb = pm.sqaureSumBit();
  if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime())
    ; //to do sth
  return 0;
}
