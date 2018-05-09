#include <stdio.h>
#include <string.h>
int next[200];
void Get_next(char str[],int next[]){
	int len=strlen(str);
	int i=0,j=-1;
	next[0]=-1;
	while(i<len){
		if(str[i]==str[j] || j==-1){
			i++;j++;
			next[i]=j;
		}
		else{
			j=next[j];
		}
	}
}
int KMP(char strm[],char sc[]){
	int lens=strlen(sc);
	int i=0,j=0;
	while(1){
		if(strm[i]=='\0') return -1;
		if(sc[j]==strm[i]){
			i++;j++;
			if(sc[j]=='\0') return i-lens;
		}
		else{
			j=next[j];
			if(j==-1){
				i++;
				j=0;
			}
		}
	}
}
int main(){
	char str[200];
	gets(str);	
	Get_next(str,next);
//	for(int i=0;i<strlen(str);i++)
//		printf("%d ",next[i]);
	printf("%d",KMP("abcdefg",str));
	return 0;
}