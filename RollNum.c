//回文数：正读与反读相等的数
//2018/11/14 更新
#include"stdio.h"
#define MAX_LEN 101
int numBit(int num);
int power(int n, int exp);
int main() {
    //to do sth
    int n, numarr[MAX_LEN], i = 1, bits, s, temp;
    scanf("%d",&n);
    temp = n;
    bits = numBit(n);
    s = power(10,numBit(n) - 1);
    while(n != 0) {
        numarr[i] = n / s;
        i++;
        n = n % s;
        s = s / 10;
    }
    for(i = 1; i < (bits / 2); i++) {
        if(numarr[i] == numarr[bits - i]) {
            continue;
        }
        else {
            printf("%d不是回文串。\n",temp);
            return 1;
        }
    }
    printf("%d是回文串。\n",temp);
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