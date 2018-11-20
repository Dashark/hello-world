//素数是只有1和本身是因子的数
//2018/11/14 更新
#include"stdio.h"
#include"math.h"
int isPrime(int num);
int main() {
    //to do sth
    int num;
    scanf("%d",&num);
    if(isPrime(num)) {
        printf("%d is a Prime num\n",num);
    }
    else {
        printf("%d is not a Prime num\n",num);
    }
    return 0;
}

int isPrime(int num) {
    int i;
    int root = (int)ceil(sqrt((double)num));
    for(i = i; i < root; i++) {
        if(num % i == 0) {
            return 1;
        }
    }
    return 0;
}