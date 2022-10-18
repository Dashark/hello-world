#include <stdio.h>
int main() {
  int x, y, z, temp;
  // 输入三个变量，按照从大到小输出 
  scanf("%d %d %d", &x, &y, &z); 
  if ( y < z ) {
  	temp = y;
	y = z;
	z = temp; 
  }
  else if ( x < y ) {
  	temp = x;
	x = y;
	y = temp; 
  }
  else if ( y < z ) {
  	temp = y;
	y = z;
	z = temp; 
  }
  printf("%d, %d, %d\n", x, y, z);
  return 0;
}
