#include <stdio.h>
typedef struct _datetime {
  int year, month, day;
  int hour, minute, second;
  void initTime();
  void showTime();
} DateTime;
int main() {
  DateTime dt, dt1;
  dt.initTime();
  dt.showTime();
  dt1.initTime();
  dt1.showTime();
  return 0;
}
void DateTime::initTime()
{
  year = 2020; month = 3; day = 13;
  hour = 11; minute = 27; second = 55;
}
void DateTime::showTime()
{
  printf("当前时间：%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}
 
