//è¾“å…¥æ•´æ•°ï¼Œå°†æ¯ä½æ•°å­—æ‰“å°å‡ºæ¥ï¼ˆä»å·¦å‘å³æ‰“å°ï¼Œç©ºæ ¼åŒºåˆ†ï¼‰
//2018/11/14 æ›´æ–°
#include <stdio.h> 
int main() {
	int a[1000];
    int N,n,m,i,t,k,j;
    printf("ÇëÊäÈëĞèÒªÊä³öÊıµÄ¸öÊı\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&k);
		N=k;t=1;
		while (N>9){
			N/=10;
			t*=10;
		}
		j=0;
		while (t>0){
			a[j]=k/t;
			k%=t;
			t/=10;
			j++;
		}
		m=j;
		for(j=0;j<m;j++){
			printf("%d ",a[j]);
		}
		printf("\n");
	} 
}
