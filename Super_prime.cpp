#include<stdio.h>
#include<math.h>
/*该数本身、所有数字之和、所有数字之积和所有数字平方和都是素数
例如113，求【100，999】：
    1.超级素数个数；
    2.所有超级素数之和；
    3.最大的超级素数。*/
int key(int x) {//判断素数
    if(x < 2) {
        return -1;//false
    }
    
    for(int i = 2; i <= (int)(sqrt(x)); i++){
        if(x % i == 0){
            return -1;//False
        }
    }
    return 1;//True
}

int Judge(int number) {//整体
    int a = (number/100) + ((number / 10) % 10) + (number % 10);//数字之和
    int b = (number/100) * ((number / 10) % 10) * (number % 10);//积
    int c = pow((int)(number/100), (int)2) + pow((int)((number / 10) % 10), (int)(2)) + pow(number % 10, (int)2);//平方和
        if(key(number)==1 && key(a)==1 && key(b)==1 && key(c)==1){
            return 1;// 全部满足
        }else{
            return -1;
        }
}

int main() {
    int begin = 100;
    int num = 0, counter = 0, max = 0;//个数, 之和, 最大超级素数
    for(; begin < 999; begin++){
        if(Judge(begin) == 1) {
            // printf("%d\n", begin);
            num++;
            counter += begin;
            if(begin > max) {
                max = begin;
            }
        }
    }

    printf("个数：%d\n总和：%d\n最大数：%d\n", num, counter, max);
    return 0;
}