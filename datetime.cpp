#include <iostream>
class DateTime {
private:
  int year, month, day;
  int hour, minute, second;
public:
  DateTime();
  DateTime(int y, int m, int d, int hour, int minute, int second); 
  ~DateTime();
  void showTime();
  void showMoon();  //作业：将当前公历转换为农历显示出来 
};
int main() {
  DateTime dt, dt1(2020, 3, 27, 10, 40, 55);
  dt.showTime();
  dt1.showTime();
  return 0;
}
DateTime::DateTime()
{
  year = 2020; month = 3; day = 20;
  hour = 11; minute = 27; second = 55;
}
DateTime::DateTime(int y, int m, int d, int hour, int minute, int second)
{
  year = y; month = m; day = d;
  this->hour = hour; this->minute = minute; this->second = second;
}
DateTime::~DateTime() 
{
  std::cout << " Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
  printf("当前时间：%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}
 
