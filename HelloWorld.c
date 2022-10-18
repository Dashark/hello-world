#include <stdio.h>
int main() {
  int x, y, temp;
  // 交换两个变量的值
  scanf("%d %d", &x, &y); 
  temp = x;   // Copy 一份 
  x = y;   // Copy y 
  y = temp;   // 把x的拷贝赋值给y 
  printf("x = %d, y = %d", x, y);
  return 0;
}
