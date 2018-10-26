//求解如下方程组
//ax + by = c
//dx + ey = f
//注意输入/输出，数据类型
#include"stdio.h"

int main() {
    double a, b, c, d, e, f;
    double ansx, ansy;
    printf("Please enter two equation in the form of \'ax + by = c\'\n");
    scanf("%lfx + %lfy = %lf",&a,&b,&c);
    scanf("%lfx + %lfy = %lf",&d,&e,&f);
    if(a * e == b * d || (a == 0&& b == 0) || (d == 0&&e == 0)) {
        printf("It can't be solved(two equivalent equation)\n");
    }
    else {
    ansx = (c * e -f * b)/(a * e - b * d);
    ansy = (c * d - f * a)/(b * d - a * e);
    printf("x = %lf\ny = %lf\n",ansx, ansy);
    }
    return 0;
}