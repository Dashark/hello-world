//ç´ æ•°æ˜¯åªæœ‰1å’Œæœ¬èº«æ˜¯å› å­çš„æ•°
//2018/11/14 æ›´æ–°
//ÊäÈëÒ»¸öÊın ±íÊ¾Òª²âÊÔn¸öÊı £¬ÅĞ¶ÏÃ¿¸öÊıÊÇ²»ÊÇËØÊı 
#include <stdio.h>
int main() {
	int i,n,m,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		for(j=1;j<=m;j++){
			if(j!=1&&j!=m&&m%j==0){
				break;
			}
		}
		if (j-1==m)
		printf("%dÊÇËØÊı\n",m);
		else
		printf("%d²»ÊÇËØÊı\n",m);
	}
	
}
