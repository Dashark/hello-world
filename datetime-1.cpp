#include <iostream>
using namespace std;
class DateTime {
private:
    int year, month, day, hour, minute, second;
    long long int seconds;     //从1970年1月1日0时开始计算的秒数 
public:
    DateTime();
    DateTime(int y, int m, int d, int hour, int minute, int second);
    DateTime(const DateTime& dt);
    ~DateTime();
    void showTime();
/*    void showMoon();  //作业：将当前公历转换为农历显示出来 */
};
int Rn(int year);
long long int Seconds(int year1, int month1, int day1, int hour1, int minute1, int second1);
int main() {
    DateTime dt, dt1(2020, 3, 27, 10, 40, 55);
    DateTime dt2(dt), & dt3 = dt;
    DateTime* dt4 = &dt;
    dt.showTime();
    dt1.showTime();
    dt2.showTime();
    dt3.showTime();
    dt4->showTime();
    return 0;
}
DateTime::DateTime()
{
    year = 2020;month = 3;day = 30;
    hour = 19;minute = 6;second = 14;
    seconds = Seconds(year, month, day, hour, minute, second);
}
DateTime::DateTime(int y, int m, int d, int hour, int minute, int second)
{
    this->year = y;
    this->month = m;
    this->day = d;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    this->seconds = Seconds(year, month, day, hour, minute, second);
}
DateTime::DateTime(const DateTime& dt)
{
    year = dt.year; month = dt.month; day = dt.day;
    hour = dt.hour; minute = dt.minute; second = dt.second;
    seconds = dt.seconds;

}
DateTime::~DateTime()
{
    std::cout << " Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
    printf("当前时间：%d/%d/%d %d:%02d:%02d\n", year, month, day, hour, minute, second);
    cout <<"该日期从1970年1月1日开始计算得到的秒数为："<< seconds << endl;
    printf("\n");
}
int Rn(int year) {
    int a;
    if (year % 400 == 0)
        a = 1;
    else
    {
        if (year % 4 == 0 && year % 100 != 0)
            a = 1;
        else
            a = 0;
    }
    if (a == 1)
        return 1;
    else
        return 0;
}
long long int Seconds(int year1, int month1, int day1, int hour1, int minute1, int second1) {
    long long int sseconds = 0;
    long long int year = year1, month = month1, day = day1, hour = hour1, minute = minute1, second = second1;
    for (int i = 1970; i < year; i++) {
        if (Rn(i) == 1)
            sseconds += 366 * 24 * 60 * 60;
        else
            sseconds += 365 * 24 * 60 * 60;
    }
    long long int Mday[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (Rn(year) == 1)
        Mday[1] += 1;
    for (int i = 1; i < month; i++) {
        sseconds += Mday[i - 1] * 24 * 60 * 60;
    }
    sseconds += (day - 1) * 24 * 60 * 60 + hour * 60 * 60 + minute * 60 + second;
    return sseconds;
}

