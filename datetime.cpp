#include <iostream>
class DateTime {
private:
  int year, month, day;
  int hour, minute, second;
  int lyear,lmonth,lday;
public:
  DateTime();
  ~DateTime();
  void showTime();
  void showMoon();  //作业：将当前公历转换为农历显示出来 
};
int main() {
  DateTime dt;

  dt.showTime();
  dt.showMoon();
  return 0;
}
DateTime::DateTime()
{
	year = 2020; month = 3; day = 20;
	hour = 11; minute = 27; second = 55;
}
DateTime::~DateTime() 
{
  std::cout << "公历已被转换为农历" << std::endl;
}
void DateTime::showTime()
{
  printf("当前时间：%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}
void DateTime::showMoon()
{
	lyear = 2020; lmonth = 2; lday = 27;
 	printf("当前时间：%d/%d/%d %d:%d:%d\n", lyear, lmonth, lday, hour, minute, second);
} 
