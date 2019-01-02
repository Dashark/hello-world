//回文数：正读与反读相等的数
//2018/11/14 更新
#include"stdio.h"
#define MAX_LEN 101
int numBit(long long num);
// int power(int n, int exp);
int main() {
    //to do sth
    long long n, temp;
    int numarr[MAX_LEN], bits, bit_temp;
    scanf("%lld",&n);
    temp = n;
    bits = numBit(n);
    bit_temp = bits;
    // s = power(10,numBit(n) - 1);
    // while(n != 0) {
    //     numarr[i] = n / s;
    //     i++;
    //     n = n % s;
    //     s = s / 10;
    // }
    while(bits != 0) {
        numarr[bits--] = n % 10;
        n = n/10;
    }
    // printf("%d\n",bit_temp);
    for(int i = 1; i <= (bit_temp / 2); i++) {
        if(numarr[i] == numarr[bit_temp + 1 - i]) {
            continue;
        }
        else {
            printf("%lld不是回文串。\n",temp);
            return 1;
        }
    }
    printf("%lld是回文串。\n",temp);
    return 0;
}
int numBit(long long num) {
    int i = 0;
    while(num != 0) {
        i++;
        num /= 10;
    }
    return i;
}

// int power(int n, int exp) {
//     int res = 1;
//     while(exp--) {
//         res *= n;
//     }
//     return res;
// }