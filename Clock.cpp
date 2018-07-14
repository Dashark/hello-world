#include<iostream>
using namespace std;

class Clock {
  public:
  Clock(int h = 0, int m = 0, int s = 0) : h(h), min(m), sec(s) {}
  ~Clock(){}
  void show();
  void adjust(int hour, int min, int sec);
  void tick();

  private:
  int h, min, sec;
};

int main() {
  Clock ck;
  ck.tick();
  ck.show();
  ck.adjust(16,45,00);
  ck.show();
  return 0;
}
void Clock::adjust(int hour, int min, int sec) {
  h = hour;
  this-> min = min;
  this-> sec = sec;
  return;
}
void Clock::show() {
  cout << "The time is " << h << ": " << min << ": " << sec << endl;
  return;
}

void Clock::tick() {
  sec++;
  if(sec == 60) {
    sec = 0;
    min++;
  }
  if(min == 60) {
    min = 0;
    h++;
  }
  if(h == 24) {
    h = 0;
  }
  return;
}