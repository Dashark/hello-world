//è¢«4æ•´é™¤çš„å¹´ä»½æ˜¯é—°å¹´ï¼Œä½†æ˜¯00ç»“å°¾çš„å¹´ä»½è¢«400æ•´é™¤æ‰æ˜¯é—°å¹´ã€‚
//2018/11/14 æ›´æ–°
#include <stdio.h>
int main() {
    int i,n,y;
    printf("ÇëÊäÈëÐèÅÐ¶ÏÄê·ÝµÄ¸öÊý\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	printf("ÇëÊäÈëÄê·Ý\n");
    	scanf("%d",&y);
   		if(y%100!=0){
			if(y%4==0)
				printf("%dÊÇÈòÄê\n",y);
			else
				printf("%d²»ÊÇÈòÄê\n",y);
		}
		else{
			if(y%400==0)
				printf("%dÊÇÈòÄê\n",y);
			else
				printf("%d²»ÊÇÈòÄê\n",y);
		}
    }
}
