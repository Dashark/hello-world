#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int T,p,len,flag;
	char stack[80]={0};
	cin>>T;
	getchar();
	string input;
	while (T>0){
		getline(cin,input);
		len=input.length();
		p=-1;
		flag=1;
		for (int i=0;i<len && flag;i++){
			switch (input[i]){
				case '(':stack[++p]=input[i]; break;
				case '{':stack[++p]=input[i]; break;
				case ')':
					if (p==-1 || stack[p--]!='(') flag=0;
					break;
				case '}': 
					if (p==-1 || stack[p--]!='{') flag=0;
				default: continue;
			}
		}
		if (p!=-1) flag=0;
		if (flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		T--;
	}
	return 0;
}
