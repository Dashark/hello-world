#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
typedef struct NODE{
	int x;
	int y;
	struct NODE* nextnd;
}Node;
int MAP[100][100];
int main(void){
	int mbx,mby;
	int mode=0;
	int total=0;
	printf("输入两次移动的时间间隔(当然是越短越快啦,单位毫秒):");
	int n;scanf("%d",&n);getchar();
	printf("是否开启自动模式？(在你不按键盘时会自动寻路)要请输入1:");
	scanf("%d",&mode);getchar();
	int i,j;
	for(i=0;i<100;i++) for(j=0;j<100;j++) MAP[i][j]=0;
	Node* head;
	head = (Node*)malloc(sizeof(Node));
	head->x=20;head->y=12;head->nextnd=NULL;
	MAP[head->y][head->x/2]=1;
	char dirc='D';
	for(i=0;i<22;i++){
		for(j=0;j<24;j++){
			if(i==0 || i==21) MAP[i][j]=1;
			else if(j==0 || j==23) MAP[i][j]=1;
		}
	}
	HANDLE ss;
	COORD pos= {0,0}; /* 光标的起始位（第1列，第3行） 0是第1列 2是第3行*/
    ss = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X=0;pos.Y=0;SetConsoleCursorPosition(ss, pos);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
	for(i=1;i<=20;i++) printf("■                                            ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
	pos.X=20;pos.Y=12;SetConsoleCursorPosition(ss, pos);
	printf("○");
	Sleep(200);
	int JPx,JPy;
	do{
		srand((unsigned)time(NULL)); 
		JPx = rand()%22+1;
		JPx = JPx/2*2;
		JPy = rand()%20+1;
	}while(MAP[JPy][JPx]==1);
	MAP[JPy][JPx]=2;
	mbx=JPx;mby=JPy;
	pos.X=JPx*2;pos.Y=JPy;SetConsoleCursorPosition(ss, pos);
	printf("★");
	while(1){
		
		int xx=head->x,yy=head->y;
		clock_t tm1=clock();
		while(1){
			if(mode==1){
				if(head->x/2 < mbx && dirc!='L' && MAP[head->x/2+1][head->y]!=1) dirc='R';
				else if(head->x/2 > mbx && dirc!='R' && MAP[head->x/2-1][head->y]!=1) dirc='L';
				else if(head->y > mby && dirc!='D' && MAP[head->x/2][head->y-1]!=1) dirc='U';
				else if(head->y < mby && dirc!='U' && MAP[head->x/2][head->y+1]!=1) dirc='D';
			}
			if(mode==1){
				int wy=head->y,wx=head->x;
				switch(dirc){
						case 'D':wy=head->y+1;break;
						case 'U':wy=head->y-1;break;
						case 'L':wx=head->x-2;break;
						case 'R':wx=head->x+2;break;
				}
				while(MAP[wy][wx/2]==1){
					wy=head->y,wx=head->x;
					dirc= (dirc=='U')?'L':(dirc=='L')?'D':(dirc=='D')?'R':'U';
					switch(dirc){
						case 'D':wy=head->y+1;break;
						case 'U':wy=head->y-1;break;
						case 'L':wx=head->x-2;break;
						case 'R':wx=head->x+2;break;
					}
				}
			}
			int a;
			a = GetKeyState(VK_LEFT);
			if(a<0 && dirc!='R')  dirc='L';
			a = GetKeyState(VK_UP);
			if(a<0 && dirc!='D')  dirc='U';
			a = GetKeyState(VK_DOWN);
			if(a<0 && dirc!='U')  dirc='D';
			a = GetKeyState(VK_RIGHT);
			if(a<0 && dirc!='L')  dirc='R';
			clock_t tm2=clock();
			if(tm2-tm1>n)break;
		}
		switch(dirc){
		case 'D':head->y+=1;break;
		case 'U':head->y-=1;break;
		case 'L':head->x-=2;break;
		case 'R':head->x+=2;break;
		}
		if(MAP[head->y][head->x/2]==1) break;
		else if(MAP[head->y][head->x/2]==2) {
			total++;
			Node* p=(Node*)malloc(sizeof(Node));
			p->x=xx;p->y=yy;p->nextnd=head->nextnd;
			head->nextnd=p;
			pos.X=head->x;pos.Y=head->y;SetConsoleCursorPosition(ss, pos);MAP[pos.Y][pos.X/2]=1;
			printf("○");
			srand((unsigned)time(NULL)); 
			do{
			JPx = rand()%22+1;
			JPx = JPx/2*2;
			JPy = rand()%20+1;
			}while(MAP[JPy][JPx]==1);
			MAP[JPy][JPx]=2;
			pos.X=JPx*2;pos.Y=JPy;SetConsoleCursorPosition(ss, pos);
			printf("★");
			mbx=JPx;mby=JPy;
		}
		else if(MAP[head->y][head->x/2]==0){
			Node* p=head;Node* c=p;
			while(p->nextnd!=NULL){c=p;p=p->nextnd;}
			if(c==p){
				pos.X=xx;pos.Y=yy;SetConsoleCursorPosition(ss, pos);MAP[pos.Y][pos.X/2]=0;
				printf("  ");
				pos.X=head->x;pos.Y=head->y;SetConsoleCursorPosition(ss, pos);MAP[pos.Y][pos.X/2]=1;
				printf("○");
			}
			else{
				pos.X=p->x;pos.Y=p->y;SetConsoleCursorPosition(ss, pos);MAP[pos.Y][pos.X/2]=0;
				printf("  ");
				c->nextnd=NULL;
				p->x=xx;p->y=yy;p->nextnd=head->nextnd;
				head->nextnd=p;
				pos.X=head->x;pos.Y=head->y;SetConsoleCursorPosition(ss, pos);MAP[pos.Y][pos.X/2]=1;
				printf("○");
			}
		}
	}
	pos.X=10;pos.Y=22;SetConsoleCursorPosition(ss, pos);
	printf("你一不小心就撞死了! 最终得分是:%d\n",total);
	system("Pause");
	return 0;
} 