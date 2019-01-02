//素数是只有1和本身是因子的数
//2018/11/14 更新
#include"stdio.h"
#include"math.h"
int isPrime(int num);
int main() {
    //to do sth
    int num;
    int count = 0;
    scanf("%d",&num);
    for(int i = 1; i <= num; i++) {
        if(isPrime(i)) {
            printf("%d is a Prime num\n",i);
            count ++;
        }
        else {
            printf("%d is not a Prime num\n",i);
        }
    }
    printf("在[1,%d]的范围中,共有%d个素数\n",num,count);
    return 0;
}

int isPrime(int num) {
    if(num < 2) {
        return 0;
    }
    int i;
    int root = (int)floor(sqrt((double)num));
    for(i = 2; i <= root; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}