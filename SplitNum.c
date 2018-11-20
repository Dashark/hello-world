//输入整数，将每位数字打印出来（从左向右打印，空格区分）
//2018/11/14 更新
#include"stdio.h"
int numBit(int num);
int power(int n, int exp);
int main() {
    //to do sth
    int n, s;
    scanf("%d",&n);
    s = power(10,numBit(n) - 1);
    while(n != 0) {
        printf("%d ",n / s);
        n = n % s;
        s = s / 10;
    }
    return 0;
}
int numBit(int num) {
    int i = 0;
    while(num != 0) {
        i++;
        num /= 10;
    }
    return i;
}

int power(int n, int exp) {
    int res = 1;
    while(exp--) {
        res *= n;
    }
    return res;
}