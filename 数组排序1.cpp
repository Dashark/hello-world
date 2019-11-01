#include <stdio.h>

int main() {
	int x[3] = {5, 2, 1}, i, temp;
	while(1) {
	scanf("%d %d %d", &x[0], &x[1], &x[2]);
	for(i=0;i<2;i++) {

      if( x[i] > x[i+1]) {
		temp = x[i];
		x[i] = x[i+1];
		x[i+1] = temp;
		}
    }
	  if( x[0] > x[2]){
	  	temp = x[0];
	  	x[0] = x[2];
	  	x[2] = temp;
	  }
	  if(x[0] > x[1]){
	  	temp = x[0];
	  	x[0] = x[1];
	  	x[1] = temp;	 
	  }	
	  
	  
	  printf(" %d, %d, %d", x[0], x[1], x[2]);
	}
	return 0;
}
