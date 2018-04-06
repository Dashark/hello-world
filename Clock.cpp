#include<iostream>

using namespace std;

class Clock
{
	void click(){}

};

int main() {
  Clock ck;
  ck.tick;
  ck.show();
  ck.adjust(16,45,00);
  ck.show();
  return 0;
}
