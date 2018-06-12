#include <iostream>
#include <ctime>
using namespace std;
struct Node{
	int value;
	Node* next;
	Node* top;
	Node* bottom;
	Node* prev;
};
class Skip_list{
public:
	Skip_list(int flr);
	int insert(int value);
	int Delete(int value);
	void Show();
	Node* search(int value);
private:
	Node* head[100]; // 0=bottom
	int floor;
};
void Skip_list::Show(){
	int i;
	for(i=0;i<floor;i++){
		Node *temp=head[i]->next;
		while(temp!=NULL){
			cout<<temp->value<<' ';
			temp=temp->next;
		}
		cout<<endl;
	}
}
Skip_list::Skip_list(int flr){
	try{
		if(flr<1) throw 1;
	}
	catch(int){
		cout<<"The floor shouldn't be lower than 1!"<<endl;
		exit(0);
	}
	floor = flr;
	int i=0;
	for(i=0;i<flr;i++){
		head[i]=new Node;
		head[i]->next=head[i]->top=head[i]->bottom=NULL;
		head[i]->value=0;
	}
	if(flr!=1){
		head[0]->top=head[1];
		head[flr-1]->bottom=head[flr-2];
	}
	for(i=1;i<flr-1;i++){
		head[i]->top=head[i+1];
		head[i]->bottom=head[i-1];
	}
}
int Skip_list::insert(int value){
	Node* temp = head[floor-1];
	Node *poses[100];
	int stage=floor-1;
	while(1){
		if(temp->next==NULL || value<(temp->next->value) ){
			if(temp->bottom!=NULL){
				poses[stage]=temp;
				stage--;
				temp = temp->bottom;
				continue;
			}
			else
				break;
		}
		temp=temp->next;
	}
	//now , temp points to the position where new node should be inserted
	Node* new_node0 = new Node;
	new_node0->value=value;
	if(temp->next!=NULL)
		temp->next->prev=new_node0;
	new_node0->next = temp->next;
	new_node0->bottom=new_node0->top=NULL;
	new_node0->prev = temp;
	temp->next = new_node0;
	int numer=1;
	while(numer<floor){
		if(rand()%2==0){
			Node* new_node1 = new Node;
			new_node1->top=NULL;
			new_node1->value = value;
			new_node1->bottom = new_node0;
			new_node0->top = new_node1;
			
			if(poses[numer]->next!=NULL)
				poses[numer]->next->prev = new_node1;

			new_node1->next = poses[numer]->next;

			poses[numer]->next=new_node1;
			new_node1->prev = poses[numer];
			

			numer++;
			new_node0 = new_node1;
			if(numer>=floor) break;
			continue;
		}
		break;
	}
	Show();
	return 0;
}
Node* Skip_list::search(int value){
	int i=floor-1;
	Node* temp = head[i];
	int flag=0;
	while(1){
		if( (flag==1 && value==temp->value) || temp->next==NULL || value<(temp->next->value) ){
			if(temp->bottom!=NULL){
				temp = temp->bottom;
				continue;
			}
			else
				break;
		}
		temp=temp->next;
		flag=1;
	}
	if(temp==head[0] || value!=temp->value)
		return NULL;
	return temp;
}

int Skip_list::Delete(int value){
	Node* temp = search(value);
	while(temp!=NULL){
		Node* record = temp->top;
		temp->prev->next=temp->next;
		if(temp->next!=NULL) temp->next->prev=temp->prev;
		delete temp;
		temp = record;
	}
	return 0;
}
int main(){
	srand(time(NULL));
	Skip_list mysl(10);
	for(int i=0;i<30;i++){
		mysl.insert(i);
		cout<<endl;
	}
	mysl.Delete(7);
	mysl.Show();
	return 0;
}