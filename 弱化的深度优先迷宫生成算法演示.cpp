#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Will_x;
int Will_y;
int Will_Dirc;
char Map[23][23],i,j;
char Map_viewed[23][23];
int END = 0;
void Found_road(int x,int y){
	if(END==1) return;
	Map[x][y]=2;
	if(x!=21 && Map[x+1][y]==0)
		Found_road(x+1,y);
	if(x!=1 && Map[x-1][y]==0)
		Found_road(x-1,y);
	if(y!=21 && Map[x][y+1]==0)
		Found_road(x,y+1);
	if(y!=1 && Map[x][y-1]==0)
		Found_road(x,y-1);
	if(x==21 && y==21)
		END=1;
	if(END==0)
	Map[x][y]=0;
}
int main(){
	srand(time(NULL));
	for(i=0;i<23;i++){
		for(j=0;j<23;j++){
			if(i%2==0 || j%2==0) Map[i][j]=1;
			else Map[i][j]=0;
			Map_viewed[i][j]=0;
		}
	}
	Map_viewed[1][1]=1;
	int now_x=1,now_y=1;
	while(1){
		Map_viewed[now_x][now_y]=1;
		int Roads[4][2],total=0;
		if(now_x!=21 && Map_viewed[now_x+2][now_y]==0){
			Roads[total][0]=now_x+2;
			Roads[total][1]=now_y;
			total++;
		}
		if(now_x!=1 && Map_viewed[now_x-2][now_y]==0){
			Roads[total][0]=now_x-2;
			Roads[total][1]=now_y;
			total++;
		}
		if(now_y!=21 && Map_viewed[now_x][now_y+2]==0){
			Roads[total][0]=now_x;
			Roads[total][1]=now_y+2;
			total++;
		}
		if(now_y!=1 && Map_viewed[now_x][now_y-2]==0){
			Roads[total][0]=now_x;
			Roads[total][1]=now_y-2;
			total++;
		}
		if(total==0){
			int flag = 0;
			for(i=1;i<22;i+=2){
				for(j=1;j<22;j+=2){
					if(flag==1) continue;
					if(Map_viewed[i][j]==0){
						if(j!=1 && Map_viewed[i][j-2]==1){
							Map[i][j-1]=0;
							now_x = i;
							now_y = j;
							flag = 1;

						}
						else if(j!=21 && Map_viewed[i][j+2]==1){
							Map[i][j+1]=0;
							now_x = i;
							now_y = j;
							flag = 1;	
						}
					}
				}
			}
			if(flag==1)
				continue;
			else
				break;

		}
		int dirc = rand()%total;
		if(Roads[dirc][0]==now_x)
			Map[now_x][(Roads[dirc][1]+now_y)/2]=0;
		else
			Map[(now_x+Roads[dirc][0])/2][now_y]=0;
		now_x = Roads[dirc][0];
		now_y = Roads[dirc][1];
	}

	Found_road(1,1);
	for(i=0;i<23;i++){
		for(j=0;j<23;j++){
			printf("%s",Map[i][j]==1 ? "¡ö" : Map[i][j]==2 ?"¡¤":"  ");
		}
		printf("\n");
	}
	return 0;
}
