//被4整除的年份是闰年，但是00结尾的年份被400整除才是闰年。
//2018/11/14 更新
#include"stdio.h"
int main() {
    //to do sth
    int year;
    int leapyearFLAG = 0;
    scanf("%d",&year);
    if(year %4 != 0) {
        leapyearFLAG = 1;
    }
    else if((year % 100 == 0)&& (year % 400 != 0 )) {
        leapyearFLAG = 1;
    }
    if(leapyearFLAG == 0) {
        printf("%d is leap year.\n",year);
    }
    else {
        printf("%d is not leap year.\n",year);
    }
}
