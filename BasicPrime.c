#include <stdio.h>
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=2;i<n+1;i++){
		if(n%i==0){
		j=n/i;
		break;
	}}
	if(j!=1)
	printf("%d不是素数",n);
	else
	printf("%d是素数",n);
return 0;
}

