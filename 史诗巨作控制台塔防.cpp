#include "esapi.h"
int lstx,lsty;
int i,j;
int Soushi=0;
int ATKTM=1;
int Killed;
int GW_MONEY;
int Level=1;
char cards[52][10]={
	"方块2","方块3","方块4","方块5","方块6","方块7","方块8","方块9","方块10","方块J","方块Q","方块K","方块A",
	"黑桃2","黑桃3","黑桃4","黑桃5","黑桃6","黑桃7","黑桃8","黑桃9","黑桃10","黑桃J","黑桃Q","黑桃K","黑桃A",
	"红桃2","红桃3","红桃4","红桃5","红桃6","红桃7","红桃8","红桃9","红桃10","红桃J","红桃Q","红桃K","红桃A",
	"梅花2","梅花3","梅花4","梅花5","梅花6","梅花7","梅花8","梅花9","梅花10","梅花J","梅花Q","梅花K","梅花A",
};
clock_t time_played;
clock_t lst=0;
charactar Zj;
int main()
{
	TYPEset();
	Hide();			//隐藏光标
	title();		//标题画面
	MajSelect();	//职业选择
	Zj.x=8;Zj.y=20;Zj.gold=100;
	MAP();
	Sleep(100000);
	return 0;
}
//--------------------------------------------------------------------------------------------------------------
void MAP()
{
	Mapset(bkst);
	int mnrecd=-1,act;
	Mapdraw();
	SetTxtMode(BACKGROUND_GREEN | BACKGROUND_RED);
	GotoXY(Zj.x,Zj.y);
	printf("%s",Zj.lk);
	while(1){
		do{
			if(mnrecd!=Zj.gold){
				Clear(26,21,38,21);
				SetTxtMode(BACKGROUND_INTENSITY);
				GotoXY(26,21);
				printf("金钱:%d",Zj.gold);
				lst = time_played;
				mnrecd=Zj.gold;
			}
		}while(SeeMessage()==0); //GameLoop
		ReadConsoleInput(hd_in,&event,1,&res);
		if(event.EventType == KEY_EVENT && event.Event.KeyEvent.bKeyDown != 0){
			act = Mov_system(Zj.x,Zj.y,0);
			switch(act){
				case 2:
					Battle_TP();
					break;
				case 3:
					Tiger();
					break;
				case 4:
					skill();
					break;
				case 5:
					FIGHTERs();
					break;
				case 6:
					Shop();
					break;
				case 7:
					Chicken();
				case 0:;
			}
		}
	}
}

void Chicken()
{
	int slt=1;
	title_draw(NULL,1,26,2,12,15,0);
	GotoXY(26,3);
	printf("------听说你想闷鸡------");
	SetTxtMode(BACKGROUND_INTENSITY);
	GotoXY(26,5);printf("你:");
	GotoXY(26,6);printf("对:");
	GotoXY(29,9);
	printf("→下注20  金  ");
	GotoXY(29,10);
	printf("  下注50  金  ");
	GotoXY(29,11);
	printf("  下注100 金  ");
	GotoXY(29,12);
	printf("  下注300 金  ");
	GotoXY(29,13);
	printf("  下注1000金  ");
	GotoXY(29,14);
	printf("  离      开  ");
	while(1){
		int dw=0;
		ReadConsoleInput(hd_in,&event,1,&res);
		if(event.EventType == KEY_EVENT && event.Event.KeyEvent.bKeyDown != 0){
			if(event.Event.KeyEvent.wVirtualKeyCode == VK_DOWN){
				slt = (slt==6) ? 1 : slt+1 ;
				dw=1;
			}
			else if(event.Event.KeyEvent.wVirtualKeyCode == VK_UP){
				slt = (slt==1) ? 6 : slt-1;
				dw=1;
			}
			else if(event.Event.KeyEvent.wVirtualKeyCode == VK_RETURN){
				printf("\a");
				GotoXY(26,3);
				printf("------听说你想闷鸡------");
				SetTxtMode(BACKGROUND_INTENSITY);
				GotoXY(26,5);printf("你:                     ");
				GotoXY(26,6);printf("对:                     ");
				if(slt==6){
					Clear(26,2,38,17);
					return;
				}
				else{
					int dbmn = (slt==1) ? 20 : (slt==2) ? 50 : (slt==3) ? 100 : (slt==4) ? 300 : 1000;
					if(Zj.gold>=dbmn){
						Zj.gold -= dbmn;
						Clear(26,21,38,21);
						SetTxtMode(BACKGROUND_INTENSITY);
						GotoXY(26,21);
						printf("金钱:%d",Zj.gold);
						int u1,u2,u3;
						int e1,e2,e3;
						srand(time(NULL));
						do{
							u1 = rand() % 52;
							u2 = rand() % 52;
							u3 = rand() % 52;
						}while(u1 == u2 || u1 == u3 || u2 == u3);
						do{
							e1 = rand() % 52;
							e2 = rand() % 52;
							e3 = rand() % 52;
						}while(e1 == e2 || e1 == e3 || e2 == e3 || e1==u1 || e1==u2 || e1==u3 || e2==u1 || e2==u2 || e2==u3 || e3==u1 || e3==u2 || e3==u3);
						GotoXY(26,5);
						printf("你:%s,%s,%s\a",cards[u1],cards[u2],cards[u3]);
						Sleep(1000);
						GotoXY(26,18);printf("要加倍下注吗? ");
						GotoXY(26,19);printf("     是     否");
						GotoXY(27,19);printf("→");
						int slt2=0,contin=0;
						while(1){
							int dw2=0;
							ReadConsoleInput(hd_in,&event,1,&res);
							if(event.EventType == KEY_EVENT && event.Event.KeyEvent.bKeyDown != 0){
								if(event.Event.KeyEvent.wVirtualKeyCode != VK_RETURN){
									slt2 = (slt2==0) ? 1 : 0;
									dw2=1;
								}
								else{
									if(slt2==0){
										if(Zj.gold >= dbmn){
											Zj.gold -= dbmn;
											dbmn += dbmn;
											Clear(26,21,38,21);
											SetTxtMode(BACKGROUND_INTENSITY);
											GotoXY(26,21);
											printf("金钱:%d",Zj.gold);
											contin=1;
										}
									}
									else if(slt2 ==1) contin=1;
									if(contin==1){
										Clear(26,18,37,19);
										SetTxtMode(BACKGROUND_INTENSITY);
										GotoXY(26,6);printf("对:%s,%s,%s",cards[e1],cards[e2],cards[e3]);
										int os = compare(u1,u2,u3);
										int es = compare(e1,e2,e3);
										
										if(os > es){
											Zj.gold +=  dbmn * 2;
											GotoXY(26,3);
											printf("------666666666666------");
										}
										else if(os == es){
											Zj.gold += dbmn;
											GotoXY(26,3);
											printf("------不可思议平局------");
										}
										else{
											GotoXY(26,3);
											printf("------运气不佳少年------");
										}
										Clear(26,21,38,21);
										SetTxtMode(BACKGROUND_INTENSITY);
										GotoXY(26,21);
										printf("金钱:%d",Zj.gold);
										break;
									}
								}
								if(dw2==1){
									GotoXY(26,19);printf("     是     否");
									GotoXY(27+3*slt2,19);printf("→");
								}
							}
						}
					}
				}
			}
			if(dw==1){
				SetTxtMode(BACKGROUND_INTENSITY);
				GotoXY(29,9);
				printf("  下注20  金  ");
				GotoXY(29,10);
				printf("  下注50  金  ");
				GotoXY(29,11);
				printf("  下注100 金  ");
				GotoXY(29,12);
				printf("  下注300 金  ");
				GotoXY(29,13);
				printf("  下注1000金  ");
				GotoXY(29,14);
				printf("  离      开  ");		
				switch(slt){
				case 1:
					GotoXY(29,9);
					printf("→下注20  金  ");
					break;
				case 2:
					GotoXY(29,10);
					printf("→下注50  金  ");
					break;
				case 3:
					GotoXY(29,11);
					printf("→下注100 金  ");
					break;
				case 4:
					GotoXY(29,12);
					printf("→下注300 金  ");
					break;
				case 5:
					GotoXY(29,13);
					printf("→下注1000金  ");
					break;
				case 6:
					GotoXY(29,14);
					printf("→离      开  ");
					break;
				}
			}
		}
	}
}


void Shop(){
title_draw("",0,26,2,13,15,0);
	SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN);
	GotoXY(26,2);
	printf("-------可以购买兵种-------");
	GotoXY(27,4);printf("刺客:攻击力999999,但攻");
	GotoXY(27,5);printf(" 速和范围非常低(1000G)");
	GotoXY(27,6);printf("搜尸官:攻击力100范围3,击");
	GotoXY(27,7);printf(" 杀敌人时获得赏金(1000G)");
	GotoXY(27,8);printf("法师:攻击范围999,攻速和");
	GotoXY(27,9);printf(" 攻击力很一般(1000G)");
	GotoXY(27,10);printf("离开");
	GotoXY(28,15);printf("上下选择,Enter学习");
	GotoXY(26,4);
	printf("→");
	int nowslt=1;
	while(1){
		int dw=0;
		ReadConsoleInput(hd_in,&event,1,&res);
		if(event.EventType==KEY_EVENT && event.Event.KeyEvent.bKeyDown!=0){
			if(event.Event.KeyEvent.wVirtualKeyCode == VK_DOWN){
				nowslt= (nowslt==4) ? 1 : nowslt+1;
				dw=1;
			}
			else if(event.Event.KeyEvent.wVirtualKeyCode == VK_UP){
				nowslt= (nowslt==1) ? 4 : nowslt-1;
				dw=1;
			}
			else if(event.Event.KeyEvent.wVirtualKeyCode == VK_RETURN){
				printf("\a");
				switch(nowslt){
					case 4:
						Clear(26,2,38,20);
						return;
					case 1:
						if(Zj.gold >= 1000 && selfTYPE[3].exist != 1){
							Zj.gold -= 1000;
							selfTYPE[3].exist=1;
						}
						break;
					case 2:
						if(Zj.gold>=1000 && selfTYPE[4].exist != 1){
							Zj.gold -= 1000;
							selfTYPE[4].exist=1;
						}
						break;
					case 3:
						if(Zj.gold >= 1000 && selfTYPE[5].exist != 1){
							Zj.gold -= 1000;
							selfTYPE[5].exist=1;
						}
						break;
				}

				Clear(26,21,38,21);
				SetTxtMode(BACKGROUND_INTENSITY);
				GotoXY(26,21);
				printf("金钱:%5d",Zj.gold);
				SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN);
			}
			if(dw==1){
				for(i=0;i<=4;i++){
					GotoXY(26,4+i*2);
					printf("  ");
				}
				GotoXY(26,4+2*(nowslt-1));
				printf("→");
			}
		}
	}
}
void FIGHTERs(){
	title_draw("",0,26,2,13,15,0);
	SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN);
	GotoXY(26,2);
	printf("-------可以升级小兵-------");
	GotoXY(27,4);printf("剑士:增加攻击力以及攻击");
	GotoXY(27,5);printf(" 速度,不能加范围(140G)");
	GotoXY(27,6);printf("弓手:增加攻击范围及攻击");
	GotoXY(27,7);printf(" 力,加极少攻速(140G)");
	GotoXY(27,8);printf("炮兵:增加攻击范围及攻击");
	GotoXY(27,9);printf(" 速度,加极少伤害(140G)");
	GotoXY(27,10);printf("离开");
	GotoXY(28,15);printf("上下选择,Enter学习");
	GotoXY(26,4);
	printf("→");
	int nowslt=1;
	while(1){
		int dw=0;
		ReadConsoleInput(hd_in,&event,1,&res);
		if(event.EventType==KEY_EVENT && event.Event.KeyEvent.bKeyDown!=0){
			if(event.Event.KeyEvent.wVirtualKeyCode == VK_DOWN){
				nowslt= (nowslt==4) ? 1 : nowslt+1;
				dw=1;
			}
			else if(event.Event.KeyEvent.wVirtualKeyCode == VK_UP){
				nowslt= (nowslt==1) ? 4 : nowslt-1;
				dw=1;
			}
			else if(event.Event.KeyEvent.wVirtualKeyCode == VK_RETURN){
				printf("\a");
				switch(nowslt){
					case 4:
						Clear(26,2,38,20);
						return;
					case 1:
						if(Zj.gold >= 140){
							Zj.gold -= 140;
							selfTYPE[0].spec += 6;
							selfTYPE[0].price += 5;
							if(selfTYPE[0].speed > 20) selfTYPE[0].speed -= 7;
						}
						break;
					case 2:
						if(Zj.gold>= 140){
							Zj.gold -= 140;
							selfTYPE[1].spec += 10;
							selfTYPE[1].price += 4;
							selfTYPE[1].size ++;
							if(selfTYPE[1].speed > 20) selfTYPE[1].speed -= 2;

						}
						break;
					case 3:
						if(Zj.gold >= 140){
							Zj.gold -= 140;
							selfTYPE[2].price += 5;
							selfTYPE[2].size++;
							selfTYPE[2].spec += 1;
							if(selfTYPE[2].speed > 200) selfTYPE[2].speed-=50;
						}
						break;
				}
				Clear(26,21,38,21);
				SetTxtMode(BACKGROUND_INTENSITY);
				GotoXY(26,21);
				printf("金钱:%5d",Zj.gold);
				SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN);
			}
			if(dw==1){
				for(i=0;i<=4;i++){
					GotoXY(26,4+i*2);
					printf("  ");
				}
				GotoXY(26,4+2*(nowslt-1));
				printf("→");
			}
		}
	}
}
void skill(){
	title_draw("",0,26,2,13,15,0);
	SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN);
	GotoXY(26,2);
	printf("-------你渴望力量吗-------");
	GotoXY(27,4);printf("Lv5 :对你3范围内的一个");
	GotoXY(27,5);printf(" 敌人造成巨大伤害(100G)");
	GotoXY(27,6);printf("Lv10:对你3范围内的所有");
	GotoXY(27,7);printf(" 敌人造成一定伤害(300G)");
	GotoXY(27,8);printf("Lv15:一定时间内让所有");
	GotoXY(27,9);printf(" 敌人站住不准动(1000G)");
	GotoXY(27,10);printf("Lv20:神秘技能(99999");
	GotoXY(27,11);printf(" 9999999999999999G)");
	GotoXY(27,12);printf("离开");
	GotoXY(28,15);printf("上下选择,Enter学习");
	GotoXY(26,4);
	printf("→");
	int nowslt=1;
	while(1){
		int dw=0;
		ReadConsoleInput(hd_in,&event,1,&res);
		if(event.EventType==KEY_EVENT && event.Event.KeyEvent.bKeyDown!=0){
			if(event.Event.KeyEvent.wVirtualKeyCode == VK_DOWN){
				nowslt= (nowslt==5) ? 1 : nowslt+1;
				dw=1;
			}
			else if(event.Event.KeyEvent.wVirtualKeyCode == VK_UP){
				nowslt= (nowslt==1) ? 5 : nowslt-1;
				dw=1;
			}
			else if(event.Event.KeyEvent.wVirtualKeyCode == VK_RETURN){
				printf("\a");
				switch(nowslt){
					case 5:
						Clear(26,2,38,20);
						return;
					case 1:
						if(Level>=5 && Zj.gold>=100 && skills[1]!=7){
							Zj.gold -= 100;
							skills[1]=7;
						}
						break;
					case 2:
						if(Level>=10 && Zj.gold>=300 && skills[2]!=7){
							Zj.gold -= 300;
							skills[2]=7;
						}
						break;
					case 3:
						if(Level>=15 && Zj.gold>=1000 && skills[3]!=7){
							Zj.gold -= 1000;
							skills[3]=7;
						}
						break;
					case 4:
						if(Level>=10 && Zj.gold>=99999999 && skills[4]!=7){
							Zj.gold = 0;
							skills[4]=7;
						}
						break;
				}
				Clear(26,21,38,21);
				SetTxtMode(BACKGROUND_INTENSITY);
				GotoXY(26,21);
				printf("金钱:%5d",Zj.gold);
				SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN);
			}
			if(dw==1){
				for(i=0;i<=4;i++){
					GotoXY(26,4+i*2);
					printf("  ");
				}
				GotoXY(26,4+2*(nowslt-1));
				printf("→");
			}
		}
	}
}
void Battle(int num,int tm,int enemy_hp,int enemy_num){
	int up=0;
	int svers=tm,ck=0;
	clock_t cksver;
	Killed=0;
	SetTxtMode(0,0);
	GotoXY(25,12);printf("可使用的技能(按B可归位)");
	for(i=0;i<10;i++){
		if(skills[i]==7){
			GotoXY(25,12+2*(i-1));
			switch(i){
				case 1:
					printf("*.按Q使用,对周围1个敌人");
					GotoXY(25,12+2*(i-1)+1);
					printf(" 造成80点伤害,没CD噢");
					break;
				case 2:
					printf("*.按W使用,对周围所有敌人");
					GotoXY(25,12+2*(i-1)+1);
					printf(" 造成65点伤害,没CD噢");
					break;
				case 3:
					printf("*.按E使用,花费50块钱让");
					GotoXY(25,12+2*(i-1)+1);
					printf(" 所有敌人静止1秒");
					break;
			}
		}
	}
	GotoXY(25,2);printf("可召唤的兵种:");
	GotoXY(25,3);printf(" NUM   NM   DMG  RG  SPD  $");
	int Showy=4;
	for(i=0;i<10;i++){
		if(selfTYPE[i].exist!=1) continue;
		if(i==3){
			GotoXY(25,Showy);Showy++;
			printf("  %d  %s  %d  %d  5秒  %d",i+1,selfTYPE[i].name,-1,selfTYPE[i].size,selfTYPE[i].price);
		}
		else{
			GotoXY(25,Showy);Showy++;
			printf("  %d  %s   %d  %d  %d  %d",i+1,selfTYPE[i].name,selfTYPE[i].spec,selfTYPE[i].size,selfTYPE[i].speed,selfTYPE[i].price);
		}
	}
	int mnrecd=-1;
	int counter=enemy_num;
	int flag=0,onShow=15;
	clock_t ct1=clock();
	Mapset(btmp);
	Battle_draw();
	while(1){
		//Game Loop
		do{
			if(ck==1){
				clock_t ckt = clock();
				if(ckt-cksver>1000){
					tm=svers;
					ck=0;
				}
			}
			if(Killed == enemy_num ){
				for(i=0;i<500;i++){
					ours[i].exist=-1;
				}
				for(i=0;i<1999;i++) enemys[i].exist=-1;
				title_draw("",1,8,8,18,10,0);
				GotoXY(10,10);
				SetTxtMode(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
				printf("可以的老哥,获得赏金%d",num);
				Zj.x=20;Zj.y=19;
				Zj.gold += num;
				GotoXY(10,12);
				Level++;
				printf("Press any key to continue^_^");
				while(1){
					ReadConsoleInput(hd_in,&event,1,&res);
					if(event.EventType==KEY_EVENT && event.Event.KeyEvent.bKeyDown!=0){
						Clear(2,2,37,23);
						MAP();
					}
				}
			}
			//money&time
			if(mnrecd!=Zj.gold){
				Clear(26,21,38,21);
				SetTxtMode(BACKGROUND_INTENSITY);
				GotoXY(26,21);
				printf("金钱:%d",Zj.gold);
				lst = time_played;
				mnrecd=Zj.gold;
			}
			clock_t ct2 = clock();
			if(flag==0 && ((ct2-ct1)/1000 != 15-onShow || onShow==15)){
				onShow = 15 - (ct2-ct1)/1000;
				SetTxtMode(BACKGROUND_INTENSITY);
				GotoXY(3,1);
				printf("  敌方还有%d秒到达  ",onShow);
				if(onShow==0){
					ct1=clock();
					flag=1;
					GotoXY(3,1);
					printf("  还有%d个敌人未到达",counter);
				}
			}
			//~~~~~~~finish it;
			if(flag==1){
				ct2=clock();
				if(ct2-ct1>tm){
					for(i=0;enemys[i].exist!=-1;i++){
						if(enemys[i].exist!=1)continue;
						Enemy_mv(i);
					}
					if(counter>0){
						for(i=0;enemys[i].exist!=-1;i++);
						enemys[i].set(12,2,2,1,-1,tm,enemy_hp,-1,1);
						GotoXY(enemys[i].x,enemys[i].y);
						SetTxtMode(BACKGROUND_RED);
						ct1=ct2;
						printf("⊙");
						counter--;
						GotoXY(3,1);
						bk[enemys[i].y][enemys[i].x].type=5;
						SetTxtMode(BACKGROUND_INTENSITY);
						printf("  还有%d个敌人未到达  ",counter);
					}
					ct1=ct2;
				}
				for(i=0;ours[i].exist != -1;i++){
					int secs=0;
					if(ct2-ours[i].lst_atk > ours[i].speed || ours[i].lst_atk==0){
						ours[i].lst_atk = ct2;
						if(ours[i].type==9){
							for(int q2=-1*((ours[i].size)/2);q2<=(ours[i].size)/2;q2++){
								for(int w2=-1*((ours[i].size)/2);w2<=(ours[i].size)/2;w2++){
									Give_ATK(ours[i].x+q2,ours[i].y+w2,ours[i].spec);
								}
							}
						}
						else{
							if(ours[i].type==6) Soushi=1;
							switch(ours[i].size){
							case 1:
								if(secs==0) secs=Give_ATK(ours[i].x-1,ours[i].y,ours[i].spec);
								if(secs==0) secs=Give_ATK(ours[i].x+1,ours[i].y,ours[i].spec);
								if(secs==0) secs=Give_ATK(ours[i].x,ours[i].y-1,ours[i].spec);
								if(secs==0) secs=Give_ATK(ours[i].x,ours[i].y+1,ours[i].spec);
								break;
							default:
								for(int q1=-1*(ours[i].size)/2;q1<=(ours[i].size)/2;q1++){
									for(int w1=-(ours[i].size)/2;w1<=(ours[i].size)/2;w1++){
										if(secs==0) secs=Give_ATK(ours[i].x+q1,ours[i].y+w1,ours[i].spec);
									}
								}
								break;
							}
						}
					}
				}
			}
		}while(SeeMessage()==0);
		//Control System;
		ReadConsoleInput(hd_in,&event,1,&res);
		if(event.EventType == KEY_EVENT && event.Event.KeyEvent.bKeyDown == 0) up=0;
		if(event.EventType == KEY_EVENT && event.Event.KeyEvent.bKeyDown != 0){
			Mov_system(Zj.x,Zj.y,1);
		    if(event.Event.KeyEvent.wVirtualKeyCode == 'B'){
				lstx=Zj.x;
				lsty=Zj.y;
				GotoXY(Zj.x,Zj.y);
				SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN);
				printf("  ");
				Zj.x=3;
				Zj.y=3;
				GotoXY(Zj.x,Zj.y);
				printf("%s",Zj.lk);
			}
			if(lstx != Zj.x || lsty != Zj.y){
				if(event.Event.KeyEvent.wVirtualKeyCode == VK_NUMPAD1 || event.Event.KeyEvent.wVirtualKeyCode == '1'){
					if(!(Zj.x == 3 && Zj.y==3)) 
					CAll(0,Zj.x,Zj.y);
				}
				else if(event.Event.KeyEvent.wVirtualKeyCode == VK_NUMPAD2 || event.Event.KeyEvent.wVirtualKeyCode == '2'){
					if(!(Zj.x == 3 && Zj.y==3)) 
					CAll(1,Zj.x,Zj.y);
				}
				else if(event.Event.KeyEvent.wVirtualKeyCode == VK_NUMPAD3 || event.Event.KeyEvent.wVirtualKeyCode == '3'){
					if(!(Zj.x == 3 && Zj.y==3)) 
					CAll(2,Zj.x,Zj.y);
				}
				else if(event.Event.KeyEvent.wVirtualKeyCode == VK_NUMPAD4 || event.Event.KeyEvent.wVirtualKeyCode == '4'){
					if(!(Zj.x == 3 && Zj.y==3)){
					if(selfTYPE[3].exist==1)
					CAll(3,Zj.x,Zj.y);
					}
				}
				else if(event.Event.KeyEvent.wVirtualKeyCode == VK_NUMPAD5 || event.Event.KeyEvent.wVirtualKeyCode == '5'){
					if(!(Zj.x == 3 && Zj.y==3)){
					if(selfTYPE[4].exist==1)
					CAll(4,Zj.x,Zj.y);
					}
				}
				else if(event.Event.KeyEvent.wVirtualKeyCode == VK_NUMPAD6 || event.Event.KeyEvent.wVirtualKeyCode == '6'){
					if(!(Zj.x == 3 && Zj.y==3)){
					if(selfTYPE[5].exist==1)
					CAll(5,Zj.x,Zj.y);
					}
				}
				else if(event.Event.KeyEvent.wVirtualKeyCode == 'Q' && skills[1]==7 && up==0){
					int secs=0;
					if(secs==0) secs=Give_ATK(Zj.x-1,Zj.y,80);
					if(secs==0) secs=Give_ATK(Zj.x+1,Zj.y,80);
					if(secs==0) secs=Give_ATK(Zj.x,Zj.y-1,80);
					if(secs==0) secs=Give_ATK(Zj.x,Zj.y+1,80);
					up=1;
				}
				else if(event.Event.KeyEvent.wVirtualKeyCode == 'W' && skills[2]==7 && up==0){
					Give_ATK(Zj.x-1,Zj.y,60);
					Give_ATK(Zj.x+1,Zj.y,60);
					Give_ATK(Zj.x,Zj.y-1,60);
					Give_ATK(Zj.x,Zj.y+1,60);
					up=1;
				}
				else if(event.Event.KeyEvent.wVirtualKeyCode == 'E' && skills[3]==7 && Zj.gold>=50){
					Zj.gold -= 50;
					ck = 1;
					tm = 99999;
					cksver = clock();
				}
				else if(event.Event.KeyEvent.wVirtualKeyCode == 'R' && skills[4]==7 && up==0){
					for(j=0;enemys[j].exist!=-1 && j<=6000;j++)
						Give_ATK(enemys[j].x,enemys[j].y,15);
					up=1;
				}
			}
		}
	}
}
void CAll(int cc,int x,int y){
	if(selfTYPE[cc].price <= Zj.gold){
		Zj.gold -= selfTYPE[cc].price;
		SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN);
		GotoXY(x,y);
		printf("%s",selfTYPE[cc].lk);
		bk[y][x].pass=0;
		bk[y][x].type=4;
		GotoXY(lstx,lsty);
		printf("%s",Zj.lk);
		Zj.x=lstx;Zj.y=lsty;
		for(int ka=0;ours[ka].exist!=-1;ka++);
		ours[ka].exist=1;
		ours[ka].x = x;
		ours[ka].y = y;
		ours[ka].size = selfTYPE[cc].size;
		ours[ka].spec = selfTYPE[cc].spec;
		ours[ka].speed = selfTYPE[cc].speed;
		ours[ka].type = selfTYPE[cc].type;
	}
}
void Enemy_mv(int num){
	switch(enemys[num].dirc){
		case 2:
			if(bk[enemys[num].y+1][enemys[num].x].type==3){
				title_draw("",1,5,5,17,8,0);
				GotoXY(8,8);
				printf("你死了!!!!!!回车结束");
				while(1){
					ReadConsoleInput(hd_in,&event,1,&res);
					if(event.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
						exit(0);
				}
			}
			if(bk[enemys[num].y+1][enemys[num].x].type!=2){
				for(int q=0;enemys[q].x !=enemys[num].x || enemys[q].y != enemys[num].y+1;q++);
				Enemy_mv(q);
			}
			bk[enemys[num].y][enemys[num].x].type=2;
			SetTxtMode(BACKGROUND_INTENSITY);
			GotoXY(enemys[num].x,enemys[num].y);
			printf("  ");
			SetTxtMode(BACKGROUND_RED);
			GotoXY(enemys[num].x,enemys[num].y+1);
			enemys[num].y++;
			printf("⊙");
			break;
		case 6:
			if(bk[enemys[num].y][enemys[num].x+1].type!=2){
				for(int q=0;enemys[q].x !=enemys[num].x+1 || enemys[q].y != enemys[num].y;q++);
				Enemy_mv(q);
			}
			bk[enemys[num].y][enemys[num].x].type=2;
			SetTxtMode(BACKGROUND_INTENSITY);
			GotoXY(enemys[num].x,enemys[num].y);
			printf("  ");
			SetTxtMode(BACKGROUND_RED);
			GotoXY(enemys[num].x+1,enemys[num].y);
			enemys[num].x++;
			printf("⊙");
			break;
		case 4:
			if(bk[enemys[num].y][enemys[num].x-1].type!=2){
				for(int q=0;enemys[q].x !=enemys[num].x-1 || enemys[q].y != enemys[num].y;q++);
				Enemy_mv(q);
			}
			bk[enemys[num].y][enemys[num].x].type=2;
			SetTxtMode(BACKGROUND_INTENSITY);
			GotoXY(enemys[num].x,enemys[num].y);
			printf("  ");
			SetTxtMode(BACKGROUND_RED);
			GotoXY(enemys[num].x-1,enemys[num].y);
			enemys[num].x--;
			printf("⊙");
			break;
		case 8:
			if(bk[enemys[num].y-1][enemys[num].x].type!=2){
				for(int q=0;enemys[q].x !=enemys[num].x || enemys[q].y != enemys[num].y-1;q++);
				Enemy_mv(q);
			}
			bk[enemys[num].y][enemys[num].x].type=2;
			SetTxtMode(BACKGROUND_INTENSITY);
			GotoXY(enemys[num].x,enemys[num].y);
			printf("  ");
			SetTxtMode(BACKGROUND_RED);
			GotoXY(enemys[num].x,enemys[num].y-1);
			enemys[num].y--;
			printf("⊙");
			break;
	}
	bk[enemys[num].y][enemys[num].x].type=5;
	if(enemys[num].x==12 && enemys[num].y==6) enemys[num].dirc=6;
	if(enemys[num].x==20 && enemys[num].y==6) enemys[num].dirc=2;
	if(enemys[num].x==20 && enemys[num].y==18) enemys[num].dirc=4;
	if(enemys[num].x==18 && enemys[num].y==18) enemys[num].dirc=8;
	if(enemys[num].x==18 && enemys[num].y==9) enemys[num].dirc=4;
	if(enemys[num].x==12 && enemys[num].y==9) enemys[num].dirc=2;
	if(enemys[num].x==12 && enemys[num].y==18) enemys[num].dirc=4;
	if(enemys[num].x==5 && enemys[num].y==18) enemys[num].dirc=8;
	if(enemys[num].x==5 && enemys[num].y==4) enemys[num].dirc=6;
	if(enemys[num].x==9 && enemys[num].y==4) enemys[num].dirc=2;

}
int Give_ATK(int x,int y,int dmg){
	if(x<=0 || x>=29 || y<=0 || y>=25) return 0;
	if(bk[y][x].type==5){
		for(int kd = 0; enemys[kd].x != x || enemys[kd].y != y || enemys[kd].exist != 1 ;kd++);
		SetTxtMode(BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);
		GotoXY(x,y);
		printf("⊙");
		enemys[kd].hp -= dmg;
		if(enemys[kd].hp < 0){
			if(Soushi==1){
				Zj.gold += Level;
				Soushi=0;
			}
			Killed+=1;
			SetTxtMode(BACKGROUND_INTENSITY);
			GotoXY(x,y);
			printf("  ");
			bk[y][x].type=2;
			enemys[kd].exist = 0;
		}
		Soushi=0;
		Clear(3,23,20,23);
		GotoXY(3,23);
		printf("%6d:%d号敌人受到了%d点伤害!",ATKTM,kd,dmg);
		ATKTM++;
		return 1;
	}
	return 0;
}
void Battle_draw(){
	// 2-23 2-21
	for(i=2;i<=23;i++){
		for(j=2;j<=21;j++){
			switch(btmp[j-2][i-2]-'0'){
			case 0:
				SetTxtMode(BACKGROUND_GREEN | BACKGROUND_BLUE);
				GotoXY(i,j);
				printf("  ");
				break;
			case 1:
				SetTxtMode(0,0);
				GotoXY(i,j);
				printf("■");
				break;
			case 2:
				SetTxtMode(BACKGROUND_INTENSITY);
				GotoXY(i,j);
				printf("  ");
				break;
			case 3:
				SetTxtMode(BACKGROUND_RED | FOREGROUND_INTENSITY);
				GotoXY(i,j);
				printf("※");
				break;
			}
		}
	}
	Zj.x=3;
	Zj.y=3;
	SetTxtMode(BACKGROUND_GREEN | BACKGROUND_BLUE);
	GotoXY(3,3);
	printf("%s",Zj.lk);
}
void Battle_TP(){
	title_draw(NULL,1,26,2,10,8,0);
	GotoXY(27,3);
	printf("   第%d关",Level);
	GotoXY(27,4); 
	printf("确定进入吗?");
	GotoXY(28,6);printf("→是是是");
	GotoXY(28,7);printf("  我怂了");
	int now_select=0;
	while(1){
		ReadConsoleInput(hd_in,&event,1,&res);
		if(event.EventType == KEY_EVENT && event.Event.KeyEvent.bKeyDown != 0){
			if(event.Event.KeyEvent.wVirtualKeyCode == VK_RETURN){
				printf("\a");
				switch(now_select){
				case 0:
					Clear(2,2,38,23);
					if(Level<12)
					Battle(Level*170,1000-Level*80,Level*70,Level*18);
					else
					Battle(2333,25,Level*72,Level*18);
					return;
				case 1:
					Clear(26,2,36,10);
					return;
				}
			}
			now_select = (now_select==1) ? 0 : 1;
			if(now_select==0){
				GotoXY(28,6);printf("→是是是");
				GotoXY(28,7);printf("  我怂了");
			}
			else{
				GotoXY(28,6);printf("  是是是");
				GotoXY(28,7);printf("→我怂了");
			}
		}
	}
}
void Tiger(){
	int slt=1;
	title_draw(NULL,1,26,2,13,15,0);
	GotoXY(26,3);
	printf("------这是一台老虎机------");
	title_draw(NULL,0,27,5,3,3,0);
	title_draw(NULL,0,31,5,3,3,0);
	title_draw(NULL,0,35,5,3,3,0);
	SetTxtMode(BACKGROUND_INTENSITY);
	GotoXY(29,9);
	printf("→下注20  金  ");
	GotoXY(29,10);
	printf("  下注50  金  ");
	GotoXY(29,11);
	printf("  下注100 金  ");
	GotoXY(29,12);
	printf("  下注300 金  ");
	GotoXY(29,13);
	printf("  下注1000金  ");
	GotoXY(29,14);
	printf("  离      开  ");
	while(1){
		int dw=0;
		ReadConsoleInput(hd_in,&event,1,&res);
		if(event.EventType == KEY_EVENT && event.Event.KeyEvent.bKeyDown != 0){
			if(event.Event.KeyEvent.wVirtualKeyCode == VK_DOWN){
				slt = (slt==6) ? 1 : slt+1 ;
				dw=1;
			}
			else if(event.Event.KeyEvent.wVirtualKeyCode == VK_UP){
				slt = (slt==1) ? 6 : slt-1;
				dw=1;
			}
			else if(event.Event.KeyEvent.wVirtualKeyCode == VK_RETURN){
				printf("\a");
				if(slt==6){
					Clear(26,2,38,17);
					return;
				}
				else{
					int mn= (slt==1) ? 20 : (slt==2) ? 50 : (slt==3) ? 100 : (slt==4) ? 300 : 1000;
					if(Zj.gold < mn) continue;
					SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
					GotoXY(26,3);
					printf("--------机器运作中--------");
					int Sver[3];
					SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN);
					GotoXY(28,6);printf("  ");
					GotoXY(32,6);printf("  ");
					GotoXY(36,6);printf("  ");
					srand(time(NULL));
					for(i=1;i<=3;i++){
						int nw=1,tms=10,final=rand()%5+1,ct=0;
						while(1){
							GotoXY(28+4*(i-1),6);
							printf(nw==1 ? "壹" : nw==2 ? "贰" : nw==3 ? "叁" : nw==4 ? "肆" : "伍");
							Sleep(tms);
							ct++;
							if(ct==(200/tms) && tms<=100){
								tms+=10;ct=0;
							}
							if(tms>100 && nw==final){
								Sver[i-1]=final;
								break;
							}
							nw = (nw==5) ? 1 : nw+1;
						}
					}
					if(Sver[0]==Sver[1] && Sver[1]==Sver[2]){
						SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
						Zj.gold += mn*6;
						GotoXY(26,3);
						printf("--------人品爆表!!--------");
						Clear(26,21,38,21);
						SetTxtMode(BACKGROUND_INTENSITY);
						GotoXY(26,21);
						printf("金钱:%5d",Zj.gold);
					}
					else if(Sver[0]==Sver[1] || Sver[1]==Sver[2] || Sver[0]==Sver[2]){
						SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
						GotoXY(26,3);
						printf("---------这波不亏---------");
						Zj.gold += mn/3;
						Clear(26,21,38,21);
						SetTxtMode(BACKGROUND_INTENSITY);
						GotoXY(26,21);
						printf("金钱:%5d",Zj.gold);
					}
					else{
						SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
						GotoXY(26,3);
						printf("---------可惜了呀---------");
						Zj.gold -= mn;
						Clear(26,21,38,21);
						SetTxtMode(BACKGROUND_INTENSITY);
						GotoXY(26,21);
						printf("金钱:%5d",Zj.gold);

					}
				}
			}
			if(dw==1){
				SetTxtMode(BACKGROUND_INTENSITY);
				GotoXY(29,9);
				printf("  下注20  金  ");
				GotoXY(29,10);
				printf("  下注50  金  ");
				GotoXY(29,11);
				printf("  下注100 金  ");
				GotoXY(29,12);
				printf("  下注300 金  ");
				GotoXY(29,13);
				printf("  下注1000金  ");
				GotoXY(29,14);
				printf("  离      开  ");		
				switch(slt){
				case 1:
					GotoXY(29,9);
					printf("→下注20  金  ");
					break;
				case 2:
					GotoXY(29,10);
					printf("→下注50  金  ");
					break;
				case 3:
					GotoXY(29,11);
					printf("→下注100 金  ");
					break;
				case 4:
					GotoXY(29,12);
					printf("→下注300 金  ");
					break;
				case 5:
					GotoXY(29,13);
					printf("→下注1000金  ");
					break;
				case 6:
					GotoXY(29,14);
					printf("→离      开  ");
					break;
				}
			}
		}
	}
}
int Mov_system(int x,int y,int mode=0){
	int gsx=x,gsy=y;
	if(event.Event.KeyEvent.wVirtualKeyCode==VK_UP){
		gsx=x;
		gsy--;
	}
	else if(event.Event.KeyEvent.wVirtualKeyCode==VK_DOWN){
		gsx=x;
		gsy++;
	}
	else if(event.Event.KeyEvent.wVirtualKeyCode==VK_LEFT){
		gsx--;
		gsy=y;
	}
	else if(event.Event.KeyEvent.wVirtualKeyCode==VK_RIGHT){
		gsx++;
		gsy=y;
	}
	if(gsx != x || gsy!= y){
		if(bk[gsy][gsx].pass==1){
			lstx=x,lsty=y;
			if(mode==0){
				if(gsx>=6 && gsy>=9){
					SetTxtMode(BACKGROUND_RED | BACKGROUND_GREEN);	
					if(x<6 || y<9){
						SetTxtMode(BACKGROUND_INTENSITY);	
					}
					GotoXY(x,y);
					printf("  ");
					SetTxtMode(BACKGROUND_RED | BACKGROUND_GREEN);
					GotoXY(gsx,gsy);
					printf("%s",Zj.lk);
				}
				else{
					SetTxtMode(BACKGROUND_INTENSITY);
					if(x>=6 && y>=9){
						SetTxtMode(BACKGROUND_RED | BACKGROUND_GREEN);	
					}
					GotoXY(x,y);
					printf("  ");
					SetTxtMode(BACKGROUND_INTENSITY);
					GotoXY(gsx,gsy);
					printf("%s",Zj.lk);
				}
			}
			else{
				SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN);
				GotoXY(x,y);
				printf("  ");
				GotoXY(gsx,gsy);
				printf("%s",Zj.lk);
			}
			Zj.x=gsx;
			Zj.y=gsy;
			return 0;
		}
		else if(bk[gsy][gsx].type>1){
			return bk[gsy][gsx].type;
		}
	}
	return 1;
}
void Mapset(char tgt[21][23]){
	for(i=2;i<=21;i++){
		for(j=2;j<=23;j++){
			bk[i][j].type = tgt[i-2][j-2]-'0';
			bk[i][j].pass = (bk[i][j].type==0) ? 1 : 0;
		}
	}
}
void Mapdraw(){ // 3-23 3-21
	SetTxtMode(BACKGROUND_RED | BACKGROUND_GREEN);
	GotoXY(2,2);
	printf("■■■■■■■■■■■■■■■■■■■■■■");GotoXY(2,3);
	printf("■              ■          ■            ■");GotoXY(2,4);
	printf("■      ■      ■          ■            ■");GotoXY(2,5);
	printf("■      ■      ■          ■            ■");GotoXY(2,6);
	printf("■      ■      ■          ■            ■");GotoXY(2,7);
	printf("■      ■      ■          ■            ■");GotoXY(2,8);
	printf("■      ■      ■          ■            ■");GotoXY(2,9);
	printf("■■■■■■  ■■■  ■■■■■■■  ■■■");GotoXY(2,10);
	printf("■      ■                                ■");GotoXY(2,11);
	printf("■  ■■■                                ■");GotoXY(2,12);
	printf("■                                        ■");GotoXY(2,13);
	printf("■      ■                        ■  ■  ■");GotoXY(2,14);
	printf("■      ■                        ■  ■  ■");GotoXY(2,15);
	printf("■      ■                        ■  ■  ■");GotoXY(2,16);
	printf("■      ■                        ■  ■  ■");GotoXY(2,17);
	printf("■■■■■                        ■  ■  ■");GotoXY(2,18);
	printf("■                                ■  ■  ■");GotoXY(2,19);
	printf("■      ■                        ■  ■  ■");GotoXY(2,20);
	printf("■      ■                        ■  ■  ■");GotoXY(2,21);
	printf("■■■■■■■■■■■■■■■■■■  ■■■");
	Fillwith(BACKGROUND_INTENSITY,3 ,3 ,9 ,8 );
	Fillwith(BACKGROUND_INTENSITY,3 ,10,5 ,16);
	Fillwith(BACKGROUND_INTENSITY,3 ,18,5 ,20);
	Fillwith(BACKGROUND_INTENSITY,11,3 ,15,8);
	Fillwith(BACKGROUND_INTENSITY,17,3 ,22,8);
	SetTxtMode(FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
	GotoXY(20,21);
	printf("〓");
	SetTxtMode(FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_INTENSITY); 
	GotoXY(3,16);
	printf("虎");
	GotoXY(8,5);
	printf("技");
	GotoXY(13,5);
	printf("兵");
	GotoXY(20,5);
	printf("商");
	GotoXY(3,18);
	printf("闷");
}
void Fillwith(WORD x,int x1,int y1,int x2,int y2){
	SetTxtMode(x);
	for(i=x1;i<=x2;i++){
		for(j=y1;j<=y2;j++){
			if(bk[j][i].pass!=1) continue;
			GotoXY(i,j);
			printf("  ");
		}
	}
}
void MajSelect(){
	//过渡画黑色背景
	ps(5);
	Sleep(700);
	//画完了~~~hiahiahia
	Show_words("来选择一个造型吧(左右选择 Enter确定)",12,6,50);
	title_draw(NULL,1,4,12,9,7,0);
	GotoXY(6,13);printf(" ★ ");
	GotoXY(5,15);printf("当一个会移动的");
	GotoXY(5,16);printf("星星还是不错的");
	title_draw(NULL,0,15,12,9,7,0);
	GotoXY(17,13);printf(" ＄ ");
	GotoXY(16,15);printf("或许这意味着开");
	GotoXY(16,16);printf("局有额外的金钱");
	title_draw(NULL,0,26,12,9,7,0);
	GotoXY(28,13);printf(" § ");
	GotoXY(27,15);printf("来自拉格朗日的");
	GotoXY(27,16);printf("死亡凝视......");
	int slet=1,dw=0;
	while(1){
		ReadConsoleInput(hd_in,&event,1,&res);
		if(event.EventType == KEY_EVENT && event.Event.KeyEvent.bKeyDown != 0){
			if(event.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT){
				slet = (slet==3) ? 1 : slet+1;
				dw=1;
			}
			if(event.Event.KeyEvent.wVirtualKeyCode == VK_LEFT){
				slet = (slet==1) ? 3 : slet-1;
				dw=1;
			}
			if(event.Event.KeyEvent.wVirtualKeyCode == VK_RETURN){
				printf("\a");
				break;
			}
			if(dw==1){
				title_draw(NULL,0,4,12,9,7,0);
				GotoXY(6,13);printf(" ★ ");
				GotoXY(5,15);printf("当一个会移动的");
				GotoXY(5,16);printf("星星还是不错的");
				title_draw(NULL,0,15,12,9,7,0);
				GotoXY(17,13);printf(" ＄ ");
				GotoXY(16,15);printf("或许这意味着开");
				GotoXY(16,16);printf("局有额外的金钱");
				title_draw(NULL,0,26,12,9,7,0);
				GotoXY(28,13);printf(" § ");
				GotoXY(27,15);printf("来自拉格朗日的");
				GotoXY(27,16);printf("死亡凝视......");
				switch(slet){
				case 1:
					title_draw(NULL,1,4,12,9,7,0);
					GotoXY(6,13);printf(" ★ ");
					GotoXY(5,15);printf("当一个会移动的");
					GotoXY(5,16);printf("星星还是不错的");
					break;
				case 2:
					title_draw(NULL,1,15,12,9,7,0);
					GotoXY(17,13);printf(" ＄ ");
					GotoXY(16,15);printf("或许这意味着开");
					GotoXY(16,16);printf("局有额外的金钱");
					break;
				case 3:
					title_draw(NULL,1,26,12,9,7,0);
					GotoXY(28,13);printf(" § ");
					GotoXY(27,15);printf("来自拉格朗日的");
					GotoXY(27,16);printf("死亡凝视......");
					break;
				}
			}
		}
	}
	switch(slet){
	case 1:
		strcpy(Zj.lk,"★");
		Zj.pro=1;
		break;
	case 2:
		strcpy(Zj.lk,"＄");
		Zj.pro=2;
		break;
	case 3:
		strcpy(Zj.lk,"§");
		Zj.pro=3;
		break;
	}
	ps(10);
	Sleep(1000);
}
void title(){
	//以下部分绘制初始界面
	SetTxtMode(BACKGROUND_GREEN);
	GotoXY(14,4);printf("    控制台塔防v1.0    ");
	for(i=0;i<=39;i++){
		for(j=0;j<=24;j++){
			GotoXY(i,j);
			printf("  ");
		}
	}
	SetTxtMode(FOREGROUND_BLUE | FOREGROUND_GREEN);
	for(i=0;i<=39;i++){
		GotoXY(i,0);printf("■");
		GotoXY(i,24);printf("■");
	}
	for(i=0;i<=24;i++){
		GotoXY(0,i);printf("■");
		GotoXY(39,i);printf("■");
	}
	GotoXY(13,4);printf("        控制台塔防        ");
	GotoXY(14,20);printf(" 方向键选择,Enter确定 ");
	GotoXY(0,0);
	title_draw("开      始",1,15,8,9,3,1);
	title_draw("说      明",0,15,12,9,3,1);
	title_draw("退      出",0,15,16,9,3,1);
	SetTxtMode(0,0);
	//好的画完了......hiahiaihiahiaihiahiahiahia233333333333
	int now_select=1;
	while(1){
		ReadConsoleInput(hd_in,&event,1,&res);
		if(event.EventType == KEY_EVENT){
			int mk=0;
			if(event.Event.KeyEvent.wVirtualKeyCode == VK_DOWN && event.Event.KeyEvent.bKeyDown!=0){
				now_select = (now_select==3) ? 1 : now_select+1;
				mk=1;
            }
			if(event.Event.KeyEvent.wVirtualKeyCode == VK_UP && event.Event.KeyEvent.bKeyDown!=0){
				now_select = (now_select==1) ? 3 : now_select-1;
				mk=1;
            }
			if(event.Event.KeyEvent.wVirtualKeyCode == VK_RETURN && event.Event.KeyEvent.bKeyDown!=0){
				printf("\a");
				switch(now_select){
				case 3:
					exit(0);
				case 1:
					return;
					break;
				case 2:
					MessageBox(NULL,"这是作者想告诉你的:\n     经过两次测试和调整,这大概是最后的版本了,有BUG我也不管了.","控制台塔防",0);
					break;
				}
            }
			if(mk==1){
				title_draw("开      始",0,15,8,9,3,1);
				title_draw("说      明",0,15,12,9,3,1);
				title_draw("退      出",0,15,16,9,3,1);
				switch(now_select){
				case 1:
					title_draw("开      始",1,15,8,9,3,1);
					break;
				case 2:
					title_draw("说      明",1,15,12,9,3,1);
					break;
				case 3:
					title_draw("退      出",1,15,16,9,3,1);
					break;
				}
			}
		}
	}
	
}
void title_draw(char* words,int mode,int x,int y, int width,int height,int grened=0){	//这是一个画SLE用的函数
	if(mode==0){
		SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN);
	}
	else SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	int a=x,b=y;
	for(i=x;i<x+width;i++){
		GotoXY(i,y);
		printf("▔");
		for(j=y+1;j<y+height-1;j++){
			GotoXY(i,j);
			printf("  ");
		}
		GotoXY(i,y+height-1);
		printf("▁");
	}
	if(grened==1){
		SetTxtMode(BACKGROUND_GREEN);
		for(i=y;i<y+height;i++){
			GotoXY(x-1,i);
			printf("▕");
			GotoXY(x+width,i);
			printf("▏");
		}
		if(mode==0){
			SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN);
		}
		else SetTxtMode(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		GotoXY(x+2,y+1);printf("%s",words);
		SetTxtMode(BACKGROUND_GREEN);
		GotoXY(x-3,y+1);
		printf("    ");
		GotoXY(x+width+1,y+1);
		printf("    ");
		if(mode!=0){
			GotoXY(x-3,y+1);
			printf("==>>");
			GotoXY(x+width+1,y+1);
			printf("<<==");
		}
	}
}
void Show_words(char* wds,int x,int y,int tm=0){
	GotoXY(x,y);
	i=0;
	while(wds[i]!='\0'){
		printf("%c",wds[i]);
		i+=1;
		Sleep(tm);
	}
}
void ps(int tm){
	SetTxtMode(0,0);
	for(i=1;i<=19;i+=2){
		if(i%4==1){
			for(j=1;j<=23;j++){
				GotoXY(i,j);
				printf("    ");
				GotoXY(38-i,24-j);
				printf("    ");
				Sleep(tm);
			}
		}
		else{
			for(j=23;j>=1;j--){
				GotoXY(i,j);
				printf("    ");
				GotoXY(38-i,24-j);
				printf("    ");
				Sleep(tm);
			}
		}
	}
}
void Clear(int x1,int y1,int x2,int y2){
	SetTxtMode(0,0);
	for(int si=x1;si<=x2;si++){
		for(int sj=y1;sj<=y2;sj++){
			GotoXY(si,sj);
			printf("  ");
		}
	}
}
int compare(int a,int b,int c){
	if(a%13>b%13) swap(&a,&b);
	if(a%13>c%13) swap(&a,&c);
	if(b%13>c%13) swap(&b,&c);
	if(a%13 == b%13 && b%13 == c%13){
		return 500000+1000*(c%13)+20*(b%13)+(a%13);
	}  //三个相同点
	if(c==b+1 && b==a+1 && (c%13)>(a%13)){
		return 400000+1000*(c%13)+20*(b%13)+(a%13);
	}  //顺子+清一色
	if(a/13 == b/13 && b/13 == c/13){
		return 300000+1000*(c%13)+20*(b%13)+(a%13);
	}  //清一色
	if(c%13 == (b%13 + 1) && b%13 == (a%13 +1)){
		return 200000+1000*(c%13)+20*(b%13)+(a%13);
	}  //顺子
	if((a%13 == b%13) || (b%13 == c%13) || (a%13 == c%13)){
		return 100000+1000*(c%13)+20*(b%13)+(a%13);
	}  //对子
	return 1000*(c%13)+20*(b%13)+(a%13);  //散牌
}