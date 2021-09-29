//求一元二次方程的根
// 例如 ：y = x2 + 10x + 17
// 当 x = 2, 求 y = 41
// 当 y = 2, 求 x = ? 
#include <stdio.h>
#include <math.h>
int main() {
  float x1, x2;
  float y, a, b, c, temp;
  printf("Please input \n");
  scanf("%f %f %f %f", &y, &a, &b, &c);
  c =  c - y;
  temp = b*b - 4* a*c;
  if(temp >= 0) {
    temp = sqrt(temp);
    a = 2 * a;
    x1 = (-b + temp)/(a);
    x2 = (-b - temp)/(a);
    printf("Results \n");
    printf("%f\n", x1);  
    printf("%f\n", x2);
  }
  else
    printf("No Results \n");
  return 0;
} 
