#include<iostream>

using namespace std;

class Clock
{
public:
	void adjust(int,int,int );
	void show(){}
	int tick;
	int kkk;
	int zzz;
};

int main() {
  Clock ck;
  ck.tick;
  ck.show();
  ck.adjust(16,45,00);
  ck.show();
  return 0;
}
