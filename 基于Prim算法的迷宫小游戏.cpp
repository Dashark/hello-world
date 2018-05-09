#include <iostream>
#include <windows.h>
#include <vector>
#include <ctime>
using namespace std;
HANDLE hd_ot = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hd_in = GetStdHandle(STD_INPUT_HANDLE);
INPUT_RECORD rec;
DWORD res;
void GotoXY(int x,int y){
	COORD pos = {2*x,y};
	SetConsoleCursorPosition(hd_ot,pos);
}
struct Wall{
	int x;
	int y;
};
class MAP{
public:
	MAP();
	void Get_Maze();
	void Show_MAP();
	int Get_content(int x,int y){return content[x][y];}
private:
	int content[23][23];
};
MAP::MAP(){
	int i,j;
	for(i=0;i<23;i++){
		for(j=0;j<23;j++){
			if(i%2==0 || j%2==0)
				content[i][j]=1;
			else
				content[i][j]=0;
		}
	}
}
void MAP::Get_Maze(){
	srand(time(NULL));
	int viewed[23][23],i,j;
	for(i=0;i<23;i++)
		for(j=0;j<23;j++)
			viewed[i][j]=0;
	viewed[1][1]=1;
	int stx=1,sty=1;
	vector<Wall> my_walls;
	Wall temp = {1,2};
	my_walls.push_back(temp);
	temp.x = 2;temp.y = 1;
	my_walls.push_back(temp);
	while(!my_walls.empty()){
		int n = rand()%my_walls.size();
		if(my_walls[n].x%2==1){
			if(viewed[my_walls[n].x][my_walls[n].y-1] == 0){
				viewed[my_walls[n].x][my_walls[n].y-1]=1;
				content[my_walls[n].x][my_walls[n].y]=0;
				temp.x=my_walls[n].x;
				temp.y=my_walls[n].y-1;
				temp.x--;
				if(temp.x!=0)
					my_walls.push_back(temp);
				temp.x+=2;
				if(temp.x!=22)
					my_walls.push_back(temp);
				temp.x--;
				temp.y--;
				if(temp.y!=0)
					my_walls.push_back(temp);
			}
			else if(viewed[my_walls[n].x][my_walls[n].y+1] == 0){
				viewed[my_walls[n].x][my_walls[n].y+1]=1;
				content[my_walls[n].x][my_walls[n].y]=0;
				temp.x=my_walls[n].x;
				temp.y=my_walls[n].y+1;
				temp.x--;
				if(temp.x!=0)
					my_walls.push_back(temp);
				temp.x+=2;
				if(temp.x!=22)
					my_walls.push_back(temp);
				temp.x--;
				temp.y++;
				if(temp.y!=22)
					my_walls.push_back(temp);
			}
		}
		else{
			if(viewed[my_walls[n].x-1][my_walls[n].y] == 0){
				viewed[my_walls[n].x-1][my_walls[n].y]=1;
				content[my_walls[n].x][my_walls[n].y]=0;
				temp.x=my_walls[n].x-1;
				temp.y=my_walls[n].y;
				temp.y--;
				if(temp.y!=0)
					my_walls.push_back(temp);
				temp.y+=2;
				if(temp.y!=22)
					my_walls.push_back(temp);
				temp.y--;
				temp.x--;
				if(temp.x!=0)
					my_walls.push_back(temp);
			}
			else if(viewed[my_walls[n].x+1][my_walls[n].y] == 0){
				viewed[my_walls[n].x+1][my_walls[n].y]=1;
				content[my_walls[n].x][my_walls[n].y]=0;
				temp.x=my_walls[n].x+1;
				temp.y=my_walls[n].y;
				temp.y--;
				if(temp.y!=0)
					my_walls.push_back(temp);
				temp.y+=2;
				if(temp.y!=22)
					my_walls.push_back(temp);
				temp.y--;
				temp.x++;
				if(temp.x!=22)
					my_walls.push_back(temp);
			}
		}
		my_walls.erase(my_walls.begin()+n);
	}
}
void MAP::Show_MAP(){
	int i,j;
	GotoXY(0,0);
	for(i=0;i<23;i++){
		for(j=0;j<23;j++){
			cout<< (content[j][i]==1 ? "■" : "  "); 
		}
		cout<<endl;
	}
}

int main(){
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hd_ot, &cci);
	cci.bVisible = 0;
	SetConsoleCursorInfo(hd_ot, &cci);
	MAP my_maze;
	my_maze.Get_Maze();
	my_maze.Show_MAP();
	SetConsoleTextAttribute(hd_ot, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	GotoXY(1,1);
	cout<<"★";
	GotoXY(21,21);
	SetConsoleTextAttribute(hd_ot, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout<<"终";
	SetConsoleTextAttribute(hd_ot, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	int x=1,y=1;
	unsigned long hh;
	while(1){
		GetNumberOfConsoleInputEvents(hd_in,&hh);
		if(hh!=0){
			int flag=0;
			ReadConsoleInput(hd_in,&rec,1,&res);
			if(rec.EventType==KEY_EVENT && rec.Event.KeyEvent.bKeyDown!=0){
				switch(rec.Event.KeyEvent.wVirtualKeyCode){
				case VK_LEFT:
					if(my_maze.Get_content(x-1,y)==0){
						GotoXY(x,y);
						cout<<"  ";
						x--;
						flag=1;
					}
					break;
				case VK_RIGHT:
					if(my_maze.Get_content(x+1,y)==0){
						GotoXY(x,y);
						cout<<"  ";
						x++;
						flag=1;
					}
					break;
				case VK_DOWN:
					if(my_maze.Get_content(x,y+1)==0){
						GotoXY(x,y);
						cout<<"  ";
						y++;
						flag=1;
					}
					break;
				case VK_UP:
					if(my_maze.Get_content(x,y-1)==0){
						GotoXY(x,y);
						cout<<"  ";
						y--;
						flag=1;
					}
					break;
				}
			}
			if(flag==1){
				GotoXY(x,y);
				cout<<"★";
			}
			if(x==21 && y==21){
				SetConsoleTextAttribute(hd_ot, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
				GotoXY(2,23);
				cout<<"行了行了知道你牛逼了     ";
				system("pause");
				return 0;
			}
		}
	}
	return 0;
}