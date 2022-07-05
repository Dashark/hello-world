#include<stdio.h>
int main(){
	int i,n,k;
	printf("输入数组项数：\n"); 
	scanf("%d",&n);//
	int a[n];
	printf("输入数组：\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("输入数组中的待删除项：\n"); 
	scanf("%d",&k);
	for(i=0;i<n;i++){
		if(a[i]==k) continue;
		else printf("%d ",a[i]);
	}
	return 0;
} 
