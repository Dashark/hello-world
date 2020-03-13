#include <stdio.h>
typedef struct _datetime {
  int year, month, day;
  int hour, minute, second;
} DateTime;
static void initTime(DateTime *dt);
static void showTime(DateTime dt);
int main() {
  DateTime dt;
  initTime(&dt);
  showTime(dt);
  return 0;
}
static void initTime(DateTime *dt)
{
  dt->year = 2020; dt->month = 3; dt->day = 13;
  dt->hour = 10; dt->minute = 25; dt->second = 55;
}
static void showTime(DateTime dt)
{
  printf("当前时间：%d/%d/%d %d:%d:%d\n", dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second);
}
 
