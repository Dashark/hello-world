#include <stdio.h>
#include <time.h>
#include <windows.h>
int BaseY[4];
HANDLE hd_ot=GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
int cs;
clock_t m;
int TIMES=1;
void Clear(int x){
	for(int i=0;i<x;i++)
		printf(" ");
}
void Print(int x){
	for(int i=0;i<x;i++)
		printf("#");
}
void GotoXY(int x,int y){
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hd_ot,pos);
}
class blocks{
public:
	int length;
	int x;
	int y;
	void Set(int stx,int sty,int len){
		x=stx;
		y=sty;
		length=len;
	}
	void Mover(int tget,int start){
		while(y!=0){
			Sleep(m);
			GotoXY(x,y);
			Clear(length);
			if(y>=2){
				GotoXY(x+length/2,y);
				printf("|");
			}
			y--;
			GotoXY(x,y);
			Print(length);
		}
		int c=(12+24*(tget-1))-length/2;
		while(x!=c){
			Sleep(m);
			GotoXY(x,y);
			Clear(length);
			if(x>c)x--;
			else x++;
			GotoXY(x,y);
			Print(length);
		}
		while(y!=BaseY[tget]-1){
			Sleep(m);
			GotoXY(x,y);
			Clear(length);
			if(y>=2){
				GotoXY(x+length/2,y);
				printf("|");
			}
			y++;
			GotoXY(x,y);
			Print(length);
		}
		BaseY[tget]--;
		BaseY[start]++;
	}
};
blocks mbks[100];
void Hanoi(int n,int st,int tget,int SP){
	if(n==1){
		GotoXY(1,15);
		printf("%4d:将 1号盘从%d柱移到%d柱\n",TIMES,st,tget);
		TIMES++;
		mbks[n].Mover(tget,st);
	}
	else{
		Hanoi(n-1,st,SP,tget);
		GotoXY(1,15);
		printf("%4d:将%2d号盘从%d柱移到%d柱\n",TIMES,n,st,tget);
		TIMES++;
		mbks[n].Mover(tget,st);
		Hanoi(n-1,SP,tget,st);
	}
}
int main(){
	printf("请输入层数n(n<=12):");scanf("%d",&cs);if(cs>12) cs=12;
	int width=1;
	int xx=12;
	int yy=14-cs;
	printf("请输入移动时间间隔(单位ms)");scanf("%d",&m);
	system("cls");
	for(int mm=0;mm<=2;mm++){
		for(int jj=2;jj<=13;jj++){
			GotoXY(12+mm*24,jj);
			printf("|");
		}
	}
	for(int i=1;i<=cs;i++){
		GotoXY(xx,yy);
		for(int j=0;j<width;j++) printf("#");
		mbks[i].Set(xx,yy,width);
		xx--;
		yy++;
		width+=2;
	}
	BaseY[1]=14-cs;
	BaseY[2]=14;
	BaseY[3]=14;
	Hanoi(cs,1,3,2);
	return 0;
}
