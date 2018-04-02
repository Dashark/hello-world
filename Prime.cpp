#include<iostream>
#include<cmath>
using namespace std;
class Prime {
public:
  Prime(int num);
  ~Prime();

  bool isPrime();
  void print() const;
  Prime sumBit();
  Prime multiBit();
  Prime sqaureSumBit();
private:
  const int mNum;
};
Prime::Prime(int num):mNum(num){}
Prime::~Prime(){}
bool Prime::isPrime() {
	if (mNum == 1) {
		return false;
	}
	for (int j = 2; j <= sqrt(double(number)); j++)
	{
		if (mNum%j == 0)return false;
	}
	return true;
}
Prime Prime::sumBit() {
	if (mNum >= 1000) {
		int a[4]
		for (int i = 0; i < 4; i++) {
			a[i] = mNum % 10;
			mNum /= 10;
		}
		Prime a(a[0] + a[1] + a[2] + a[3]);
		return a;
	}
}
Prime Prime::multiBit() {
	if (mNum >= 1000) {
		int a[4]
			for (int i = 0; i < 4; i++) {
				a[i] = mNum % 10;
				mNum /= 10;
			}
		Prime b(a[0] * a[1] * a[2] * a[3]);
		return b;
	}
}
Prime Prime::sqaureSumBit() {
	if (mNum >= 1000) {
		int a[4]
			for (int i = 0; i < 4; i++) {
				a[i] = mNum % 10;
				mNum /= 10;
			}
		Prime c(a[0] * a[0] + a[1] * a[1] + a[2] * a[2] + a[3] * a[3]);
		return c;
	}
}
void Prime::print()const {
	cout << mNum << endl;
}
int main() {
  Prime pm(113);
  Prime sb = pm.sumBit();
  Prime mb = pm.multiBit();
  Prime ssb = pm.sqaureSumBit();
  if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime())
    pm.print(); //to do sth
  return 0;
}
