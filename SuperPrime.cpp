#include <iostream>
using namespace std;

class Prime {
	public:
	  Prime(int num):mNum(num) {};
	  ~Prime() {};
	  bool isPrime(int mNum) {
	  	if (mNum == 1 || mNum == 0) {
			return false;
		}
		else if (mNum == 2 || mNum == 3) {
			return true;
		}
		else {
			int flag = 0;
			for (int i = 2; i * i <= mNum; i++) {
				if (mNum % i != 0) {
					continue;
				}
				else {
					flag = 1;
					break;
				}
			} 
			if (flag) {
				cout << "not prime" << endl;
				return false;
			}
			else {
				cout << "is prime" << endl;
				return true;
			}
		}
	  }
	private:
	  const int mNum;
};

class SuperPrime : public Prime {
	public:
	  SuperPrime(int num):Prime(num), num(num) {
	    //a = num / 1000;
		b = (num % 1000) / 100;
		c = (num % 100) / 10;
		d = (num % 10);
		cout << b << " " << c << " " << d << endl;
	  };
	  ~SuperPrime() {};
	
	  bool isPrime() {
	  	Prime::isPrime(num);
	  }
	
	  bool sumBit() {
	  	Prime::isPrime(b+c+d);
	  };
	  bool multiBit() {
	  	Prime::isPrime(b*c*d);
	  };
	  bool squareSumBit() {
	  	Prime::isPrime(b*b+c*c+d*d);
	  };
	private:
	  const int num;
	  int a, b, c, d;
};

int main() {
    SuperPrime sp(113);
    if(sp.isPrime() == true && sp.sumBit() == true && sp.multiBit() == true && sp.squareSumBit() == true) {
        cout << "yes" << endl; // do something
    }
    else cout << "no" << endl;
    return 0;
}
