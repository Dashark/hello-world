#include<iostream>
using namespace std;


struct chain{
	int next;
	string name;
};

chain list[65];


void remove(int &p,int &n){
	cout<<list[p].name<<endl;
	for (int i=p;i<n;i++){
		list[i].name=list[i+1].name;
	}
	if (p==n) p=list[n].next;
	n=n-1;
	list[n].next=1;

}

int main(){
	int n,w,s,p,t;
	while (cin>>n){
		for (int i=1;i<n;i++){
			cin>>list[i].name;
			list[i].next=i+1;
		}
		cin>>list[n].name;
		list[n].next=1;
		scanf("%d,%d",&w,&s);
		p=w;
		while (n>0){
			t=1;
			while (t<s) { p=list[p].next; t++;}
			remove(p,n);
		}
	}
	
	return 0;
}
