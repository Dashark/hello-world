#include "SDL.h"
#include <string>
#include <vector>
#include <iostream>
#include <SDL_ttf.h>
using namespace std;
int x=40;
int ymx=0;
int is_num(char a){
	if( (a>='0' && a<='9') || (a=='+' || a=='-'))
		return 1;
	return 0;
}
struct node{
	int value;
	int ptx;
	int pty;
	vector<node> sons;
};
class BTG{
public:
	BTG(string ips):index(0),input_str(ips){}
	node* parse_N();
private:
	string input_str;
	int index;
	vector<node> parse_G();
	void next();
	int read_value();
};
void BTG::next(){
	while(input_str[index]==' ')
		index++;
}
int BTG::read_value(){
	int result = 0;
	int np = 0;
	if(input_str[index]=='-')
		np = 1;
	if(input_str[index]=='-' || input_str[index]=='+')
		index++;
	while(is_num(input_str[index])){
		result = result*10 + (input_str[index]-'0');
		index ++;
	}
	if(np==1) result *= -1 ;
	next();
	return result;
}
node* BTG::parse_N(){
	next();
	node *tmp = NULL;
	if( is_num(input_str[index])==1 ){
		tmp = new node;
		int value = read_value();
		tmp -> value = value;
		if(input_str[index]=='('){
			index++;next();
			tmp->sons = parse_G();
			index++;next();
		}
	}
	return tmp;
}
vector<node> BTG::parse_G(){
	next();
	vector<node> rts;
	if( is_num(input_str[index]) == 1 ){
		node* temp = parse_N();
		rts.push_back(*temp);
		if(input_str[index]==','){
			index++;next();
			vector<node> new_cm = parse_G();
			rts.insert(rts.end(),new_cm.begin(),new_cm.end());
		}
	}
	return rts;
}
void Visit(node *tgt,int y){
	tgt->ptx = x;
	tgt->pty = y;
	if(y>ymx) ymx=y;
	for(unsigned int i=0;i<tgt->sons.size();i++){
		Visit(&tgt->sons[i],y+60);
		if(i!=tgt->sons.size()-1) x+=60;
	}
	if(tgt->sons.size()!=0)
		tgt->ptx = (tgt->sons[0].ptx + tgt->sons[tgt->sons.size()-1].ptx)/2;
	cout<<"("<<tgt->ptx<<","<<tgt->pty<<")"<<tgt->value<<' ';
}

SDL_Window* win=NULL;
SDL_Renderer* ren=NULL;
TTF_Font *font = NULL;
void Dw_visit(node *tgt){
	SDL_Rect rect = {tgt->ptx-20,tgt->pty-20,40,40};
	SDL_RenderFillRect(ren,&rect);
	for(int i =0;i<tgt->sons.size();i++){
		SDL_RenderDrawLine(ren,tgt->ptx,tgt->pty,tgt->sons[i].ptx,tgt->sons[i].pty);
		Dw_visit(&tgt->sons[i]);
	}
	char tmp[100];
	_itoa_s(tgt->value,tmp,10);
	cout<<tmp;
	SDL_Color cl = {0,0,0};
	SDL_Surface *surf = TTF_RenderText_Blended(font,tmp,cl);
	int w,h;
	TTF_SizeText(font,tmp,&w,&h);
	SDL_Texture *text = SDL_CreateTextureFromSurface(ren,surf);
	if(w<60){
		rect.w = w;
		rect.x += (40-w)/2;
		rect.y += (40-h)/2;
	}
	rect.h = h;
	SDL_RenderCopy(ren,text,NULL,&rect);
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(text);
	SDL_UpdateWindowSurface(win);

}	


int main(int argc,char* argv[])
{
	TTF_Init();
	font = TTF_OpenFont("msyh.ttf",14);
	char temp[10086];
	cin.getline(temp,10086);
	string tps(temp);
	BTG btg(tps);
	node *head = btg.parse_N();
	Visit(head,40);
	//初始化sdl
	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("Rect",100,100,x+50,ymx+50,SDL_WINDOW_SHOWN);

	ren = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(ren,255,255,255,255);
	//创建窗口
	Dw_visit(head);
	//更新屏幕
	SDL_RenderPresent(ren);
	SDL_Delay(3000);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
