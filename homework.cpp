#include<stdio.h>
int main(){
	int i,n,k;
	printf("��������������\n"); 
	scanf("%d",&n);//
	int a[n];
	printf("�������飺\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("���������еĴ�ɾ���\n"); 
	scanf("%d",&k);
	for(i=0;i<n;i++){
		if(a[i]==k) continue;
		else printf("%d ",a[i]);
	}
	return 0;
} 
