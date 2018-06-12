#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int debug=0;
struct Node{
	int value;
	char color;
	Node* left;
	Node* right;
	Node* parent;
};
class RBT{
public:
	RBT():root(NULL),Inited(0){}
	void Show();
	Node* searcher(int value);
	int Init(int value);
	int Insert(int value);
	int Delete(int value);
	int Inited;
	int Good_tree(Node* stt);
	Node* root;
private:
	void Show_cent(Node* vst,int floor);
	int Adjust(Node* tgt);
	int Rtt(Node* tgt);
};

Node* RBT::searcher(int value){
	Node *temp = root;
	while(temp!=NULL && value!=temp->value){
		if(value>temp->value)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return temp;
}

int RBT::Good_tree(Node* stt){
	if(stt==NULL) return 1;
	int lf = Good_tree(stt->left);
	int rf = Good_tree(stt->right);
	if(lf != rf || (stt->color=='R' && stt->parent->color=='R'))
		cout<<"--BAD TREE--\n";
	return (stt->color=='B') ? lf+1 : lf;
}

int RBT::Delete(int value){
	Node *del = searcher(value);
	if(del == NULL) return 0;
	Node *temp = del;
	while(temp->left != NULL || temp->right != NULL){
		if(temp->left != NULL){
			temp = temp->left;
			while(temp->right!=NULL)
				temp = temp->right;
			del->value = temp->value;
			del = temp;
		}
		if(temp->right != NULL){
			temp = temp->right;
			while(temp->left!=NULL)
				temp = temp->left;
			del->value = temp->value;
			del = temp;
		}
	}
	int Mode = (del->parent->left==del) ? 0:1 ;
	Node *father = del->parent;
	if(Mode==0){
		father->left = NULL;
		if(del->color=='R'){
			delete del;
			return 1;
		}
		delete del;
	}
	else{
		father->right = NULL;
		if(del->color=='R'){
			delete del;
			return 1;
		}
		delete del;
	}
	Node *brother;
	while(1){
		if(Mode==0){
			brother = father->right;
			if(father->color=='B' && brother->color=='B' && 
			  (brother->left==NULL || brother->left->color=='B') && (brother->right==NULL || brother->right->color=='B') ){
				brother->color='R';
				Node* temp2 = father->parent;
				if(temp2==NULL) break;
				Mode = (temp2->left==father) ? 0:1 ;
				father = temp2;
				continue;
			}
			else if(father->color=='R' && brother->color=='B' && 
			  (brother->left==NULL || brother->left->color=='B') && (brother->right==NULL || brother->right->color=='B') ){

				father->color = 'B';
				brother->color = 'R';
				break;
			}
			else if(brother->color == 'B' && brother->right!=NULL && brother->right->color=='R'){

				char temp = brother->color;
				brother->color = father->color ;
				father->color = temp;
				brother->right->color = 'B';
				Rtt(brother);
				break;
			}
			else if(brother->color == 'B' && brother->left!=NULL && brother->left->color=='R' && 
				(brother->right==NULL || brother->right->color=='B') ){
				Node *ls = brother->left;
				ls->color = 'B';
				brother->color = 'R';
				Rtt(ls);
				brother = ls;
				continue;
			}
			else if(brother->color == 'R'){
				father->color = 'R';
				brother->color = 'B';
				Rtt(brother);
				brother = father->right;
				continue;
			}
		}
		else{  // Mode==1
			brother = father->left ;

			if(father->color=='B' && brother->color=='B' && 
			  (brother->right==NULL || brother->right->color=='B') && (brother->left==NULL || brother->left->color=='B') ){
				
				brother->color = 'R' ;
				Node* temp2 = father->parent;
				if(temp2==NULL) break;
				Mode = (temp2->left==father) ? 0:1 ;
				father = temp2;
				continue;
			}
			else if(father->color=='R' && brother->color=='B' && 
			  (brother->right==NULL || brother->right->color=='B') && (brother->left==NULL || brother->left->color=='B') ){

				father->color = 'B';
				brother->color = 'R';
				break;
			}
			else if(brother->color == 'B' && brother->left!=NULL && brother->left->color=='R'){
				
				char temp = brother->color;
				brother->color = father->color ;
				father->color = temp;
				brother->left->color = 'B';
				Rtt(brother);
				break;
			}
			else if(brother->color == 'B' && brother->right!=NULL && brother->right->color=='R' && 
				(brother->left==NULL || brother->left->color=='B') ){
				
				Node *ls = brother->right;
				ls->color = 'B';
				brother->color = 'R';
				Rtt(ls);
				brother = ls;
				continue;
			}
			else if(brother->color == 'R'){

				father->color = 'R';
				brother->color = 'B';
				Rtt(brother);
				brother = father->left;

				continue;
			}
		}
	}



	return 0;
}







int RBT::Init(int value){
	root = new Node;
	root->left=root->right=root->parent=NULL;
	root->color='B';
	root->value=value;
	Inited=1;
	return 1;
}
void RBT::Show(){
	if(Inited!=1 || root==NULL) return;
	Show_cent(root,0);
	cout<<endl;
}
void RBT::Show_cent(Node* vst,int floor){
	cout<<'('<<floor<<','<<vst->color<<')'<<(vst->value)<<' ';
	if(vst->left!=NULL) Show_cent(vst->left,floor+1);
	if(vst->right!=NULL) Show_cent(vst->right,floor+1);
}

int RBT::Rtt(Node* tgt){
	Node* father = tgt->parent;
	Node* grand_father = father->parent;
	int Mode = (father->left==tgt) ? 0:1;
	if(Mode==0){
		father->parent = tgt;
		father->left = tgt->right;
		if(tgt->right!=NULL) tgt->right->parent = father;
		tgt->right = father;
	}
	else{
		
		father->parent = tgt;

		father->right = tgt->left;

		if(tgt->left!=NULL) tgt->left->parent = father;

		tgt->left = father;
	}
	if(grand_father!=NULL){
		if(grand_father->left==father){
				grand_father->left=tgt;
				tgt->parent = grand_father;
		}
		else{
			grand_father->right=tgt;
			tgt->parent = grand_father;
		}
	}
	else{

		root = tgt;
		tgt->parent=NULL;
	}
	return 1;
}
int RBT::Adjust(Node* tgt){
	if(tgt==NULL) return 0;
	while(1){
		if(tgt==root && tgt->color=='R'){
			tgt->color='B';
			break;
		}
		Node *temp1,*temp2;
		temp1 = tgt->parent;
		temp2 = temp1->parent;
		if(tgt->color =='R' && temp1->color=='R'){
			if(temp2->left!=NULL && temp2->right!=NULL && temp2->left->color=='R' && temp2->right->color=='R'){

				temp2->left->color = 'B';
				temp2->right->color = 'B';
				temp2->color = 'R';
				tgt =temp2;
				continue;
			}
			else{
				if((temp2->left==temp1 && temp1->left==tgt) || (temp2->right==temp1 && temp1->right==tgt)){
					temp2->color = 'R';
					temp1->color = 'B';
					Rtt(temp1);

					break;
				}
				else{

					Rtt(tgt);
					tgt = temp1;
					continue;
				}
			}

		}
		break;
	}
	return 1;
}
int RBT::Insert(int value){
	if(Inited!=1) return 0;
	Node* temp = root;
	Node* temp2;
	int Pos=0;
	while(1){
		if(value>(temp->value)){
			if(temp->right==NULL){
				Pos=1;
				break;
			}
			else 
				temp=temp->right;
		}
		else{
			if(temp->left==NULL){
				break;
			}
			else
				temp=temp->left;
		}
	}
	if(Pos==0){
		temp2 = new Node;
		temp2->left=temp2->right=NULL;
		temp2->value=value;
		temp2->parent=temp;
		temp2->color='R';
		temp->left = temp2;
		Adjust(temp2);
		
	}
	else{

		temp2 = new Node;
		temp2->left=temp2->right=NULL;
		temp2->value=value;
		temp2->parent=temp;
		temp2->color='R';
		temp->right = temp2;
		Adjust(temp2);
	}
	return 1;
}
int main(){
	while(1){
		srand(clock());
		int Rand[31];
		RBT myrbt;
		Rand[0]=1;
		myrbt.Init(0);
		for(int i=1;i<=30;i++){
			myrbt.Insert(i);
			Rand[i]=1;
		}
		myrbt.Show();
		for(int j=1;j<=30;j++){
			int temp=rand()%31;
			do{
				temp = rand()%31;
			}while(Rand[temp]!=1);
			Rand[temp]=0;
			cout<<temp<<": ";
			myrbt.Delete(temp);
			myrbt.Good_tree(myrbt.root);
			myrbt.Show();
		}
		Sleep(1000);
		system("cls");
	}
	return 0;
}