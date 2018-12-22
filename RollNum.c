#include <stdio.h>
#include <string.h>
int main(){	
int n,i,x,z,m;
scanf("%d",&n);
for(i=0;i<n;i++){
	scanf("%d",&x);
	z=x;
	m=0;
	while(x){
	m=m*10+x%10;
	x=x/10;
	}
	if(z==m)
	printf("yes");
	else
	printf("no");
}
	return 0;
}
