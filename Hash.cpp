#include <iostream>
#include <cstring>
using namespace std;
class Hash{
	struct Node{
		char Key[20];
		int value;
		Node* next;
	};
public:
	Hash();
	int& Read(char*);
	int& operator[] (char*);
private:
	Node* Hashs[100];
};
Hash::Hash(){
	for(int i=0;i<100;i++)
		Hashs[i]=NULL;
}
int& Hash::Read(char* key){
	int total=0,len=strlen(key);
	for(int i=0;i<len;i++)
		total+=key[i];
	int Pos=total%100;
	Node *temp = Hashs[Pos];
	while(temp!=NULL){
		if(!strcmp(temp->Key,key)){
			return temp->value;
		}
		temp=temp->next;
	}
	Node* temp2 = new Node;
	strcpy(temp2->Key,key);
	temp2->next=NULL;
	if(Hashs[Pos]==NULL){
		Hashs[Pos]=temp2;
	}
	else{
		Node *lk = Hashs[Pos];
		while(lk->next!=NULL)
			lk=lk->next;
		lk->next=temp2;
	}
	return temp2->value;
}
int& Hash::operator[](char* key){
	return Read(key);
}

int main(){
	Hash my_hash;
	my_hash["BBZ"]=666;
	cout<<my_hash["BBZ"]<<endl;
	my_hash["YL"]=6666;
	my_hash["BBZ"]=my_hash["YL"]+10;
	cout<<my_hash["YL"]<<' '<<my_hash["BBZ"]<<endl;
	return 0;
}