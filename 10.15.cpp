#include<stdio.h>
int main(){
	int height ,length ,width,v,v1;
	scanf("%d",&height);
	scanf("%d",&length);
	scanf("%d",&width);
	
	v = height*length*width;
	v1 = (v+165)/166;
	printf("%d",v1);
	return 0; 
}
