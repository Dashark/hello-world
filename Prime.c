/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
#include <stdio.h>
//2018/11/14 更新
#include<math.h>

int sum_bit(int num);
int multi_bit(int num);
int square_sum_bit(int num);
int isprime(int num);

int main() {
  int n,max,count = 0,sum = 0;
  for(n = 100; n <= 9999; n++){
    if(isprime(n)&&isprime(sum_bit(n))&&isprime(multi_bit(n))&&isprime(square_sum_bit(n)))
    {
      max = n;
      count++;
      sum += max;
    }//to do sth
  }
  printf("超级素数的个数为%d\n",count);
  printf("所有超级素数之和为%d\n",sum);
  printf("最大的超级素数为%d\n",max);
  return 0;
}

int sum_bit(int num) {
  int a, n;
  a = num%10;
  while((num = num/10) != 0){
    n = num%10;
    a += n;
  }
  return a;
}

int multi_bit(int num) {
  int a, n;
  a = num % 10;
  while((num = num / 10) != 0){
    n = num % 10;
    a *= n;
  }
  return a;
}

int square_sum_bit(int num) {
  int a, n;
  a = num % 10;
  while((num = num / 10) != 0){
    n = num % 10;
    a += n * n;
  }
  return a;
}

int isprime(int num) {
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
