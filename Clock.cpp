#include<iostream>

using namespace std;

class Clock
{
public:
	void adjust(int,int,int );
	void show(){}
	int tick;
	int kkk;
<<<<<<< HEAD
	int zzz;
=======
>>>>>>> 17a15c67fb724b56912f97e70d137545ce99291b
};

int main() {
  Clock ck;
  ck.tick;
  ck.show();
  ck.adjust(16,45,00);
  ck.show();
  return 0;
}
