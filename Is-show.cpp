#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;
HANDLE hd_ot = GetStdHandle(STD_OUTPUT_HANDLE);
void Gotoxy(int x,int y){
	COORD pos ={x,y};
	SetConsoleCursorPosition(hd_ot,pos);
}
int main(){
	int i,j,k,pos=0;
	vector<int> nums;
	cout<<"Input your array :"<<endl;
	while(1){
		int temp;
		cin>>temp;
		nums.push_back(temp);
		if(cin.get()=='\n') break;
	}
	system("cls");
	for(i=0;i<nums.size();i++){
		Gotoxy(4,i);
		cout<<nums[i];
	}
	Gotoxy(1,pos);
	cout<<"->";
	for(i=1;i<nums.size();i++){
		Gotoxy(1,i-1);
		cout<<"  ";
		Gotoxy(1,i);
		cout<<"->";
		Sleep(200);
		for(j=0;j<i;j++){
			if(nums[i]<nums[j]) break;
		}
		if(j!=i){
			int this_num = nums[i];
			for(k=4;k<11;k+=2){
				Gotoxy(k,i);
				cout<<"                      ";
				Gotoxy(k+2,i);
				cout<<nums[i];
				Sleep(140);
			}
			int temp_pos=i;
			while(j!=temp_pos){
				Gotoxy(12,temp_pos);
				cout<<"                      ";
				temp_pos--;
				Gotoxy(12,temp_pos);
				cout<<nums[i];
				Sleep(70);
			}
			for(int temp=i-1;temp>=j;temp--){
				Gotoxy(4,temp);
				cout<<"        ";
				Gotoxy(4,temp+1);
				cout<<nums[temp];
				nums[temp+1]=nums[temp];
				Sleep(140);
			}
			for(k=12;k>=6;k-=2){
				Gotoxy(k-2,j);
				cout<<"                      ";
				Gotoxy(k-2,j);
				cout<<this_num;
				Sleep(70);
			}
			nums[j]=this_num;
		}
	}
	Sleep(100000);
	return 0;
}