#include <iostream>

#ifdef WINDOWS
#include <Windows.h>
void beep() {
  Beep(440, 100);
}
#elif LINUX
#include <cstdio>
void beep() {
  system("echo -e "\007" >/dev/tty10");
}
#else
#include <cstdio>
void beep() {
  std::cout << "\a";
}
#endif

class Clock {
public:
  Clock() {
    hh = 0;
    mm = 0;
    ss = 0;
  }
  Clock(int h, int m, int s) {
    hh = h;
    mm = m;
    ss = s;
  }
  ~Clock(){ }

  void tick();
  void show();
  void adjust(int hur, int min, int sec);

private:
  int hh, mm, ss;
};

void Clock::tick() {
  beep();
}

void Clock::show() {
  if (Clock::hh <= 9) {
    std::cout << 0 << Clock::hh << ":";
  } else {
    std::cout << Clock::hh << ":";
  }
  if (Clock::mm <= 9) {
    std::cout << 0 << Clock::mm << ":";
  } else {
    std::cout << Clock::mm << ":";
  }
  if (Clock::ss <= 9) {
    std::cout << 0 << Clock::ss << std::endl;
  } else {
    std::cout << Clock::ss << std::endl;
  }
}

void Clock::adjust(int hur, int min, int sec) {
  Clock::hh = hur;
  Clock::mm = min;
  Clock::ss = sec;
}

int main() {
  Clock ck;
  ck.tick();
  ck.show();
  ck.adjust(16,45,00);
  ck.show();
  return 0;
}
