#include <stdio.h>
int main() {
  int x, y, z, temp;
  // 输入两个变量，按照从大到小输出 
  scanf("%d %d", &x, &y); 
  if ( x < y ) {
    temp = x;   // Copy 一份 
    x = y;   // Copy y 
    y = temp;   // 把x的拷贝赋值给y 
  }
  printf("x = %d, y = %d", x, y);
  return 0;
}
