#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
HANDLE h_in = GetStdHandle(STD_INPUT_HANDLE);
HANDLE h_ot = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
INPUT_RECORD keyrec;
DWORD res;
void gotoxy(int x,int y){
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(h_ot,pos);
}
class ZD{
	public:
		int x;
		int y;
		int exist;
		ZD(){
			x=-1;
			y=2;
			exist=0;
		}
};
int main()
{
	clock_t ck;
	clock_t sver=0;
	while(1){
		//隐藏光标
		CONSOLE_CURSOR_INFO cci;
		GetConsoleCursorInfo(h_ot, &cci);
		cci.bVisible = false;
		SetConsoleCursorInfo(h_ot, &cci);
		int TIMES;
		int SCS;
		FILE* c=fopen("data.ini","r+");
		if(c==NULL){
			c=fopen("data.ini","w+");
			fprintf(c,"0 0");
			fseek(c,0,0);
		}
		fscanf(c,"%d%d",&SCS,&TIMES);
		fclose(c);
		gotoxy(7,16);
		printf("Played:%d",TIMES);
		gotoxy(7,17);
		printf("Record:%d",SCS);
		int i,j;
		SetConsoleTextAttribute(h_ot,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); 
		for(i=2;i<=21;i++){
			for(j=1;j<=20;j++){
				if(i==2 || i==20 || ((j==1 || j==20)&& i%2==0)){
					gotoxy(i,j);
					printf("□");
				}
			}
		}
		SetConsoleTextAttribute(h_ot,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
		gotoxy(8,8);printf("→开始");
		gotoxy(8,12);printf("  退出");
		int status=0;
		int G_start=0;
		while(G_start==0){
			ReadConsoleInput(h_in,&keyrec,1,&res);
			if(keyrec.EventType==KEY_EVENT && keyrec.Event.KeyEvent.bKeyDown!=0){
				switch(keyrec.Event.KeyEvent.wVirtualKeyCode){
					case VK_DOWN:
					case VK_UP:
						status= (status==0)?1:0;
						if(status==0){
							gotoxy(8,8);printf("→开始");
							gotoxy(8,12);printf("  退出");
						}
						else if(status==1){
							gotoxy(8,8);printf("  开始");
							gotoxy(8,12);printf("→退出");
						}
						break;
					case VK_RETURN:
						if(status==1) exit(0);
						if(status==0) G_start=1;
				}
			}
		}
		system("cls");
		sver=clock();
		/*游戏部分*/
		int mark=0;
		int zd_top=0;
		int zd_c=0;
		ZD zd[100];
		clock_t lst=0;
		srand(time(NULL));
		int MAP[11][21]; //0代表空气 1代表障碍 2代表子弹 3代表主角;
		int ini_x=10,ini_y=19;
		MAP[ini_x/2][ini_y]=3;
		gotoxy(ini_x,ini_y);
		SetConsoleTextAttribute(h_ot,FOREGROUND_GREEN | FOREGROUND_INTENSITY); 
		printf("※");
		SetConsoleTextAttribute(h_ot,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); 
		for(i=2;i<=21;i++){
			for(j=1;j<=20;j++){
				if(i==2 || i==20 || ((j==1 || j==20)&& i%2==0)){
					gotoxy(i,j);
					printf("■");
					MAP[i/2][j]=1;
				}
				else if(MAP[i/2][j]!=1)MAP[i/2][j]=0;
			}
		}
		SetConsoleTextAttribute(h_ot,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
		gotoxy(25,4);
		printf("得分:%d",mark);
		int GM_ov=0;
		while(GM_ov==0){
			//子弹部分
			//生成
			int kt;
			ck = clock();
			ck-=sver;
			if(ck<40000) kt=ck/2000;
			else kt=20;
			if(zd_c<kt){
				int wz;
				do{
					wz=(rand()%8+2)*2;
				}while(MAP[wz/2][2]==2);
				for(i=0;zd[i].exist==1;i++);
				zd_top=i;
				MAP[wz/2][2]=2;
				zd[zd_top].exist=1;
				zd[zd_top].x=wz;
				gotoxy(zd[zd_top].x,zd[zd_top].y);
				printf("↓");
				zd_c++;
				zd_top++;
			}
			//下落
			int TM=(ck>90000) ? 20 : ((ck>70000)?40:((ck>50000)?60:((ck>35000)?80:((ck>20000)?100:150))));
			if(ck-lst>=TM){
				SetConsoleTextAttribute(h_ot,FOREGROUND_RED | FOREGROUND_INTENSITY); 
				lst=ck;
				for(i=0;i<30;i++){
					if(zd[i].exist==0) continue;
					gotoxy(zd[i].x,zd[i].y);
					MAP[zd[i].x/2][zd[i].y]=0;
					printf("  ");
					zd[i].y++;
					if(MAP[zd[i].x/2][zd[i].y]==3) GM_ov=1;
					if(MAP[zd[i].x/2][zd[i].y]==0){
						gotoxy(zd[i].x,zd[i].y);
						MAP[zd[i].x/2][zd[i].y]=2;
						printf("↓");
					}
					if(MAP[zd[i].x/2][zd[i].y]==1){
						zd_c--;
						zd[i].y=2;
						zd[i].exist=0;
						mark++;
						gotoxy(25,4);
						SetConsoleTextAttribute(h_ot,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
						printf("得分:%d",mark);
						SetConsoleTextAttribute(h_ot,FOREGROUND_RED | FOREGROUND_INTENSITY);
					}
				}
			}
			//控制部分↓
			unsigned long hh;
			GetNumberOfConsoleInputEvents(h_in,&hh);
			if(hh!=0){
				SetConsoleTextAttribute(h_ot,FOREGROUND_GREEN | FOREGROUND_INTENSITY); 
				ReadConsoleInput(h_in,&keyrec,1,&res);
				if(keyrec.EventType==KEY_EVENT){
					if(keyrec.Event.KeyEvent.bKeyDown != 0){ 
						if(keyrec.Event.KeyEvent.wVirtualKeyCode == VK_LEFT){
							if(MAP[ini_x/2-1][ini_y]!=1){
								gotoxy(ini_x,ini_y);
								printf("  ");
								MAP[ini_x/2][ini_y]=0;
								ini_x-=2;
								Sleep(20);
								gotoxy(ini_x,ini_y);
								printf("※");
								if(MAP[ini_x/2][ini_y]==2) GM_ov=1;
								MAP[ini_x/2][ini_y]=3;
							}
						}
						if(keyrec.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT){
							if(MAP[ini_x/2+1][ini_y]!=1){
								gotoxy(ini_x,ini_y);
								printf("  ");
								MAP[ini_x/2][ini_y]=0;
								ini_x+=2;
								gotoxy(ini_x,ini_y);
								printf("※");
								if(MAP[ini_x/2][ini_y]==2) GM_ov=1;
								MAP[ini_x/2][ini_y]=3;
							}
						}
					}
				}
			}
		}
		SetConsoleTextAttribute(h_ot,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
		gotoxy(2,22);
		printf("Game Over~\n");
		SCS = (mark>SCS)?mark:SCS;
		TIMES++;
		c=fopen("data.ini","wb");
		fprintf(c,"%d %d",SCS,TIMES);
		fclose(c);
		sver=ck;
		system("pause");
		system("cls");
	}
	return 0;
}
