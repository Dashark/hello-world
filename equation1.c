//求解一元二次方程的根
//查阅sqrt()函数
//注意有没有解
#include"stdio.h"
#include"math.h"

int main() {
    double a, b, c, d;
    double delta;
    printf("Please enter equation in the form of \'ax^2 + bx + c = d\'\n");
    scanf("%lfx^2 + %lfx + %lf = %lf",&a,&b,&c,&d);
    // printf("%lf\n%lf\n%lf\n%lf\n",a,b,c,d);
    c = c - d;
    delta = b * b - 4 * a * c;
    // printf("%lf\n%lf\n%lf\n",a,b,c);
    if(delta < 0) {
        printf("No real-number solution\n");
    }
    else {
        delta = sqrt(delta);
        printf("x1 = %lf\nx2 = %lf\n",(-b - delta)/2/a,(-b + delta)/2/a);
    }
    return 0;
}