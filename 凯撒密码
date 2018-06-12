#include<iostream>
using namespace std;
int main(){
	string word;
	int len;
	while (getline(cin,word)){
		if (word=="END") continue; 
		else if (word=="START") getline(cin,word);
		else if (word=="ENDOFINPUT") return 0;
		len=word.length();
		for (int i=0;i<len;i++){
			if (word[i]>='E' && word[i]<='Z') word[i]-=5;
			else if (word[i]>='A' && word[i]<='D') word[i]=word[i]+21;
			else continue;
		}
		for(int i=0;i<len;i++)
		if (i==len-1) cout<<word[i]<<endl;
		else cout<<word[i];
	}
	
	return 0;
}
