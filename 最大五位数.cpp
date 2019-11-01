#include <stdio.h>
int main() {
  int x[5] , i , m = 0;
  while(1) {
    scanf("%d %d %d %d %d",&x[0],&x[1],&x[2],&x[3],&x[4]);
    for(m=0;m<4;m++){
	for(i=0;i<4;i++) {
      if( x[i] > x[i+1]) {
  	    int temp = x[i];
 		x[i] = x[i+1];
 		x[i+1] = temp;
      }
    }
   
    }printf(" %d%d%d%d%d", x[4], x[3], x[2], x[1], x[0]);
}
  return 0;
}
