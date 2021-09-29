#include <stdio.h>
int main() {
  int year;
  scanf("%d", &year);
  if (year % 4 == 0)
    if(year % 100 != 0)
      printf("%d 年就是闰年\n", year); 
    else // year % 4 == 0 && year % 100 == 0 确定 year % 400 != 0？ 、
	  if(year % 400 == 0)
	    printf("%d 年就是闰年\n", year); 
	  else
        printf("%d 年不是闰年\n", year);
  else  //已知 year % 4 != 0  确定  year % 400 != 0
    printf("%d 年不是闰年\n", year); 

  return 0;
} 
