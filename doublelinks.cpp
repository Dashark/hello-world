#include <conio.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifndef DoubleLinkList_H
#define DoubleLinkList_H
using namespace std;
struct NodeType
{
	char name[20];
	char tel[20];
	int  age;
	int  index;
};
template< class NodeType > class Node;  
template< class NodeType > class DoubleLinkList; 
/***************************************************************/

template< class NodeType >
class Node															  //结点类
{
	friend class DoubleLinkList< NodeType >;						  //友元类

	private :
		NodeType Data;												  //结点数据	
		Node< NodeType > *NextNode;									  //后向指针
		Node< NodeType > *PreviousNode;								  //前向指针
	public :
		void Show();
		Node();														  //默认构造函数
		Node( NodeType &Value );									  //拷贝构造函数				 
		~Node();												      //析构函数
};
/********************************************************/
template< class NodeType >
class DoubleLinkList												  //双向链表类
{
	private :
	  Node< NodeType > *FirstNode;									  //首结点
	  Node< NodeType > *RearNode;								      //尾结点
	public :
		DoubleLinkList();											  //默认构造函数	
		~DoubleLinkList();										      //析构函数
		bool IsEmpty();		                                          //判断链表是否为空	
		Node< NodeType > *CreateNode( NodeType &Value);               //生成一个新结点
		void AddNode(NodeType Value1);                                //排序插入结点
		void ShowForward();	                                      //向前输出链表			
		void ShowBackwards();                                     //向后输出链表				 
		int LenghtOfDoubleLinkList();                                 //链表结点个数          
		void DelByName(char *Name);                                   //根据姓名删除结点
		void DelByTel(char *Tel);									  //根据电话删除结点
		void DelByIndex(int Index);                                   //根据序号删除结点
        bool SearchByTel(char *Tel);                                  //根据号码查寻
		bool SearchByIndex(int index);                                //根据序号查询
		bool CompSearch(char *Name);                                   //通配符查找
	    bool UpdataByName(char *Name);								  //根据姓名修改结点
	    bool UpdataByTel(char *Tel);	                              //根据号码修改	
	    bool UpdataByIndex(int Index);                                //根据序号修改结点
	    bool LoadFromFile(char *filename);                            //从文件中输出数据
		bool SaveToFile(char *filename);                              //将数据保存到文件中
		
}; 
#endif
/*******************************************************/
int main()
{
	cout<<"\2017141461363 朱嘉宁\n";
	int Index;
	char Tel[20];
	char Name1[20];
    char Filename[20];
	int Option,Option1,Option2,Option3,Option4;
	DoubleLinkList<NodeType> List;
	do
	{
		cout<<"\n\t 电话簿                       "
			<<"\n\t 1：插入电话簿数据                        "
			<<"\n\t 2：查找电话簿数据（1姓名, 2号码，3序号） "
			<<"\n\t 3：删除电话簿数据（1姓名，2号码，3序号） "
			<<"\n\t 4：修改电话簿数据（1姓名，2号码，3序号） "                            
			<<"\n\t 5：输出电话簿数据（1从前往后，2从后往前）"
			<<"\n\t 6：把数据存储到文件                      "
			<<"\n\t 7：从文件中读取数据                      "
            <<"\n\t 0：退出                                  "
            <<"\n请输入你的选择:";
		cin>>Option;
		switch(Option)
		{
		case 1:NodeType Value;
				cout<<"请输入姓名:（0退出 ）";
				cin>>Value.name;
				while(strcmp(Value.name,"0")!=0)
				{
					cout<<"请输入号码:";
					cin>>Value.tel;
					cout<<"请输入年龄:";
					cin>>Value.age;
					List.AddNode(Value);
					cout<<"\n请输入姓名:";
					cin>>Value.name;
				}
				break;

		case 2: cout<<"查找途径.\n1.根据姓名,\n2.根据号码,\n3.根据序号.\n请选择：";
				cin>>Option1;
				switch(Option1)
				{
					case 1:	cout<<"请输入姓名：";
							cin>>Name1;
							List.CompSearch(Name1); break;
					case 2: cout<<"请输入号码:";
							cin>>Tel;
							List.SearchByTel(Tel); break;
			    	case 3: cout<<"请输入序号:";
						    cin>>Index;
						    List.SearchByIndex(Index); break;
					default : cout<<"错误"; break;
				} break;
		case 3: cout<<"删除途径.\n1.根据姓名,\n2.根据号码,\n3.根据序号.\n请选择：";
				cin>>Option2;
				switch(Option2)
				{
					case 1:	cout<<"请输入姓名：";
							cin>>Name1;
							List.DelByName(Name1); break;
					case 2: cout<<"请输入号码:";
							cin>>Tel;
							List.DelByTel(Tel); break;
                    case 3: cout<<"请输入序号:";
						    cin>>Index;
						    List.DelByIndex(Index); break;
					default : cout<<"错误"; break;
				} break;
		case 4: cout<<"修改方式.\n1.根据姓名,\n2.根据号码,\n3.根据序号.\n请选择:";
				cin>>Option3;
				switch(Option3)
					{
						case 1: cout<<"请输入姓名:";
								cin>>Name1;
 								List.UpdataByName(Name1); break;
						case 2: cout<<"请输入号码:";
								cin>>Tel;
 								List.UpdataByTel(Tel); break;
						case 3: cout<<"请输入序号:";
							    cin>>Index;
								List.UpdataByIndex(Index); break;
						default :cout<<"错误"; break;
					} break;
		case 5: cout<<"查看方式.\n1.从前向后输出,\n2.从后向前输出.\n请选择：";
			    cin>>Option4;
				switch(Option4)
				{
					case 1:cout<<"链表数据个数："<<List.LenghtOfDoubleLinkList()<<"\n";
						List.ShowForward(); break;
					case 2:cout<<"链表数据个数："<<List.LenghtOfDoubleLinkList()<<"\n";
						List.ShowBackwards(); break;
					default :cout<<"错误"; break;
				} break;

		case 6: cout<<"请输入文件途径:";
			    cin>>Filename;
				List.SaveToFile(Filename); break;
		case 7: cout<<"请输入文件途径:";
			    cin>>Filename;
				List.LoadFromFile(Filename); break;
		case 0: break;
		default :Option=0; break;
		}
	}
	while(Option!=0);
	return 0;
}

/**********************************************************************/
template< class NodeType >//输出函数
 void Node< NodeType >::Show()
{
	cout<<Data.index<<"."<<Data.name<<" "<<Data.tel<<" "<<Data.age<<endl;
}
/**********************************************************************/
template< class NodeType >
Node< NodeType >::Node()
:Data( NULL ),NextNode( NULL ),PreviousNode( NULL ) {}
/**********************************************************************/
template< class NodeType >
Node< NodeType >::Node( NodeType &Value )
{
	strcpy(Data.name,Value.name);
	strcpy(Data.tel,Value.tel);
	Data.age=Value.age;
	Data.index=1;
	NextNode=NULL;
	PreviousNode=NULL;
}
/**********************************************************************/
template< class NodeType >
Node< NodeType >::~Node()
{
	cout<<"\n 释放了结点.";
}
/**********************************************************************/
template< class NodeType >
DoubleLinkList< NodeType >::DoubleLinkList()
:FirstNode( NULL ),RearNode( NULL ) 
{}

/**********************************************************************/

template< class NodeType >
DoubleLinkList< NodeType >::~DoubleLinkList()
{
	Node< NodeType > *CurrentNode = FirstNode, *TempNode ;
	while( CurrentNode != NULL )
		{
		TempNode = CurrentNode;
		CurrentNode = CurrentNode->NextNode;
		TempNode->Show();
		delete TempNode;
		}
	cout<<"\n 释放了一个双向链表."
		<<"\n 按任意键继续!";
	getch();
}
/**********************************************************************/
template< class NodeType >
bool DoubleLinkList< NodeType >::IsEmpty()//判断链表是否为空
{
	if( FirstNode == NULL )
		return true;
	else
		return false;
}
/**********************************************************************/
template< class NodeType >
Node< NodeType > *DoubleLinkList< NodeType >::CreateNode( NodeType &Value )//生成一个新结点,返回节点指针
{
	Node< NodeType > *NewNode = new Node< NodeType >( Value );
	assert( NewNode != NULL );
	return NewNode ;
}

/**********************************************************************/
template< class NodeType >
void DoubleLinkList< NodeType >::AddNode( NodeType Value )                      //添加结点
{
	Node< NodeType > *CurrentNode=FirstNode,*TempNode,*TEMPNode;
	Node< NodeType > *NewNode = CreateNode(Value);                              //根据数据生成节点
	
		if ( IsEmpty() )	                                                    //链表为空，节点为唯一节点
		{	cout<<"\n 添加在空链表中。";                                      
			FirstNode = RearNode = NewNode;
		}                                                                       
		else
		{
			if(strcmp(FirstNode->Data.name,NewNode->Data.name)>0)				//添加在头结点
			{
				FirstNode->PreviousNode = NewNode;                              //与头节点的前向指针连接起来
				NewNode->NextNode = FirstNode;                                  //节点的后向指针与头节点连接起来
				FirstNode = NewNode;                                            //新节点成为头节点
				FirstNode->PreviousNode = NULL;                                 //头节点的前向指针为空
				TEMPNode=FirstNode->NextNode;                                   //将头节点赋给另一个指针，用于修改序号
				while(TEMPNode!=NULL)
					{
						(TEMPNode->Data.index)++;
						TEMPNode=TEMPNode->NextNode;
					}
			}
			else
			{
				while(strcmp(NewNode->Data.name,CurrentNode->Data.name)!=0&&CurrentNode->NextNode!=NULL)
						CurrentNode=CurrentNode->NextNode;
				if(CurrentNode->NextNode==NULL)									//添加在尾结点
				{
					NewNode->PreviousNode = RearNode;                           //连接新节点的前向指针		
					RearNode->NextNode = NewNode;                               //连接节点的后向指针
					NewNode->Data.index=(RearNode->Data.index)+1;               //设定新节点的序号
					RearNode = NewNode;                                         //将新节点赋值为尾节点
					RearNode->NextNode = NULL;                                  //将尾节点的后向指针赋为0
				}
				if(strcmp(NewNode->Data.name,CurrentNode->Data.name)<0)			//添加在中间结点
				{
					TempNode = CurrentNode;                                     //节点插在当前节点之前
					NewNode->PreviousNode = CurrentNode->PreviousNode;          //连接新节点的前向指针
					NewNode->NextNode = CurrentNode;                            //连接新节点的后向指针
					CurrentNode = CurrentNode->PreviousNode;                    //当前节点指向新节点的前节点
					CurrentNode->NextNode = NewNode ;                           //连接新节点的前节点的后向指针
					TempNode->PreviousNode = NewNode;                           //连接新节点后节点的前向指针
					TEMPNode=NewNode;                                           //将新节点赋值给另一节点
					TEMPNode->Data.index=CurrentNode->Data.index;               //给新节点之后重新编序号
					while(TEMPNode!=NULL)
					{
						(TEMPNode->Data.index)++;
						TEMPNode=TEMPNode->NextNode;
					}	
				}
			}
		}
		cout<<"\n添加成功!";
		cout<<"\n添加的结点为:\n";
		NewNode->Show();
}
/**********************************************************************/
template<class NodeType>
void DoubleLinkList<NodeType>::DelByName(char *Name)                            //根据姓名删除
{
	char choice;
	if( IsEmpty() )
		{
			cout<<"链表为空,删除失败!"<<"\n按任意键继续.";
			getch();
			return  ;
		}
	else
		{
			Node< NodeType > *CurrentNode = FirstNode,*TempNode=RearNode,*TEmpNode,*TEMPNode;
			if(strcmp(FirstNode->Data.name,Name)==0)							//删除头结点
			{
					cout<<"删除的结点为:";
					FirstNode->Show();                                          //展示要删除的节点
					cout<<"是否删除(YorN)";                                     //询问是否确认删除
					cin>>choice;
				if(choice=='Y'||choice=='y')
				{
					if( FirstNode == RearNode )                                 //链表有唯一节点
						FirstNode = RearNode = NULL;
					else
					{
						FirstNode = FirstNode->NextNode;                        //头节点后移
						FirstNode->PreviousNode = NULL ;                        //新的头节点前向指针赋值为空
						TEMPNode=FirstNode;                                     //将头节点赋值给新节点
						while(TEMPNode!=NULL)
						{
							(TEMPNode->Data.index)--;
							TEMPNode=TEMPNode->NextNode;
						}
					}
					delete CurrentNode;
					cout<<"\n删除成功!";
					return ;
				}
				cout<<"\n按任意键继续.";
				getch();
			}
			if(strcmp(RearNode->Data.name,Name)==0)							    //删除尾结点
			{
					cout<<"删除的结点为:";
					RearNode->Show();                                           //展示要删除的节点
					cout<<"是否删除(Y/N)";                                      //询问是否确认删除
					cin>>choice;
				if(choice=='Y'||choice=='y')
				{
					RearNode = RearNode->PreviousNode;                          //尾节点前移
					RearNode->NextNode = NULL;                                  //尾节点的后向指针赋值空
					delete TempNode;
					cout<<"\n删除成功!";
					return  ;
				}
				cout<<"\n按任意键继续.";
				getch();
			}
			else																//删除中间结点
			{
				while(strcmp(CurrentNode->Data.name,Name)!=0&&CurrentNode->NextNode!=NULL)
					CurrentNode=CurrentNode->NextNode;
				if(CurrentNode->NextNode==NULL)
				{
					cout<<"删除的结点不存在!";
					return  ;
					cout<<"\n按任意键继续.";
					getch();
				}
				else
				{
					cout<<"欲删除的结点为:";
					CurrentNode->Show();                                         //展示要删除的节点
					cout<<"是否删除(Y/N)";                                       //询问是否确认删除
					cin>>choice;
					if(choice=='Y'||choice=='y')
					{
						TempNode = CurrentNode ;                                 //TempNode为欲删除的节点
						CurrentNode = CurrentNode->NextNode ;                    //欲删除节点的后节点
						CurrentNode->PreviousNode = TempNode->PreviousNode ;     /*连接删除节点的前后两个节点*/
						TEmpNode = TempNode->PreviousNode ;                      //欲删除节点的前节点
						TEmpNode->NextNode = CurrentNode ;                       //连接前节点的后向指针
						while(CurrentNode!=NULL)
						{
							(CurrentNode->Data.index)--;
							CurrentNode=CurrentNode->NextNode;
						}
						delete TempNode;
					}
					cout<<"\n删除成功!"<<"\n按任意键继续.";
					getch();
					return ;
				}
			}
	}
}

/**********************************************************************/
template< class NodeType >
void DoubleLinkList<NodeType>::DelByTel(char *Tel)//根据号码删除(同上)
{
	char choice;
	if( IsEmpty() )
		{
			cout<<"链表为空,删除失败!"<<"\n按任意键继续.";
			getch();
			return  ;
		}
	else
		{
			Node< NodeType > *CurrentNode = FirstNode,*TempNode=RearNode,*TEmpNode,*TEMpNode;
			if (strcmp(FirstNode->Data.tel,Tel)==0)										
			{
					cout<<"删除的结点为:";
					FirstNode->Show();
					cout<<"是否删除(Y/N)";
					cin>>choice;
				if(choice=='Y'||choice=='y')
				{
					if( FirstNode == RearNode )
						FirstNode = RearNode = NULL;
					else
					{
						FirstNode = FirstNode->NextNode;
						FirstNode->PreviousNode = NULL ;
						TEMpNode=FirstNode;
						while(TEMpNode!=NULL)
						{
							(TEMpNode->Data.index)--;
							TEMpNode=TEMpNode->NextNode;
						}
					}
				delete CurrentNode;
				cout<<"\n删除成功!";
				return  ;
				}
				cout<<"\n按任意键继续.";
				cout<<endl;
				getch();
			}
			if(strcmp(RearNode->Data.tel,Tel)==0)										
			{
					cout<<"删除的结点为:";
					RearNode->Show();	
					cout<<"是否删除(Y/N)";
					cin>>choice;
				if(choice=='Y'||choice=='y')
				{
					RearNode = RearNode->PreviousNode;
					RearNode->NextNode = NULL;
					delete TempNode;
					cout<<"\n删除成功!";
					return ;
				}
				cout<<"\n按任意键继续.";
				getch();
			}
			else															
			{
				while(strcmp(CurrentNode->Data.tel,Tel)!=0&&CurrentNode->NextNode)
					CurrentNode=CurrentNode->NextNode;
				if(CurrentNode->NextNode==NULL)
				{
					cout<<"删除的结点不存在!";
					return ;
					cout<<"\n按任意键继续.";
					getch();
				}
				else
				{
					cout<<"删除的结点为:";
					CurrentNode->Show();
					cout<<"是否删除(Y/N)";
					cin>>choice;
					if(choice=='Y'||choice=='y')
					{
						TempNode = CurrentNode ;
						CurrentNode = CurrentNode->NextNode ;
						CurrentNode->PreviousNode = TempNode->PreviousNode ;
						TEmpNode = TempNode->PreviousNode ;
						TEmpNode->NextNode = CurrentNode ;
						while(CurrentNode!=NULL)
						{
							(CurrentNode->Data.index)--;
							CurrentNode=CurrentNode->NextNode;
						}
						delete TempNode;
					}
					cout<<"\n删除成功!"<<"\n按任意键继续.";
					getch();
					return ;
				}
			}
	}
}

/**********************************************************************/
template< class NodeType >
void DoubleLinkList<NodeType>::DelByIndex(int Index)//根据序号删除（同上） 
{
	char choice;
	if( IsEmpty() )
		{
			cout<<"链表为空,删除失败!"<<"\n按任意键继续.";
			getch();
			return ;
		}
	else
		{
			Node< NodeType > *CurrentNode = FirstNode,*TempNode=RearNode,*TEmpNode,*TEMpNode;
			if (FirstNode->Data.index==Index)										
			{
					cout<<"删除的结点为:";
					FirstNode->Show();
					cout<<"是否删除(Y/N)";
					cin>>choice;
				if(choice=='Y'||choice=='y')
				{
					if( FirstNode == RearNode )
						FirstNode = RearNode = NULL;
					else
					{
						FirstNode = FirstNode->NextNode;
						FirstNode->PreviousNode = NULL ;
						TEMpNode=FirstNode;
						while(TEMpNode!=NULL)
						{
							(TEMpNode->Data.index)--;
							TEMpNode=TEMpNode->NextNode;
						}
					}
				delete CurrentNode;
				cout<<"\n删除成功!";
				return ;
				}
				cout<<"\n按任意键继续.";
				cout<<endl;
				getch();
			}
			if(RearNode->Data.index==Index)										
			{
					cout<<"删除的结点为:";
					RearNode->Show();	
					cout<<"是否删除(Y/N)";
					cin>>choice;
				if(choice=='Y'||choice=='y')
				{
					RearNode = RearNode->PreviousNode;
					RearNode->NextNode = NULL;
					delete TempNode;
					cout<<"\n删除成功!";
					return ;
				}
				cout<<"\n按任意键继续.";
				getch();
			}
			else															
			{
				while(CurrentNode->Data.index==Index&&CurrentNode->NextNode)
					CurrentNode=CurrentNode->NextNode;
				if(CurrentNode->NextNode==NULL)
				{
					cout<<"删除的结点不存在!";
					return ;
					cout<<"\n按任意键继续.";
					getch();
				}
				else
				{
					cout<<"删除的结点为:";
					CurrentNode->Show();
					cout<<"是否删除(Y/N)";
					cin>>choice;
					if(choice=='Y'||choice=='y')
					{
						TempNode = CurrentNode ;
						CurrentNode = CurrentNode->NextNode ;
						CurrentNode->PreviousNode = TempNode->PreviousNode ;
						TEmpNode = TempNode->PreviousNode ;
						TEmpNode->NextNode = CurrentNode ;
						while(CurrentNode!=NULL)
						{
							(CurrentNode->Data.index)--;
							CurrentNode=CurrentNode->NextNode;
						}
						delete TempNode;
					}
					cout<<"\n删除成功!"<<"\n按任意键继续.";
					getch();
					return ;
				}
			}
	}
}
/**********************************************************************/
template< class NodeType >
void DoubleLinkList< NodeType >::ShowForward()                     //向前输出链表
{
	Node< NodeType > *CurrentNode = FirstNode ;
	cout<<"\n 链表如下:\n";
	if(CurrentNode == NULL) cout<<"链表为空!";
	else{
		while ( CurrentNode != NULL)
		{
			CurrentNode->Show();
			CurrentNode = CurrentNode->NextNode;
		}
	cout<<"\n 按任意键继续.";
	getch();
	}
}
/**********************************************************************/
template< class NodeType >
void DoubleLinkList< NodeType >::ShowBackwards()                   //向后输出链表
{
	Node< NodeType > *CurrentNode = RearNode ;
	cout<<"\n 链表如下:\n";
	while ( CurrentNode != NULL)
	{   CurrentNode->Show();
		CurrentNode = CurrentNode->PreviousNode;
	}

	cout<<"\n 按任意键继续.";
	getch();
}
/**********************************************************************/
template< class NodeType >
int DoubleLinkList< NodeType >::LenghtOfDoubleLinkList()               //链表结点个数 
{
	int NosOfNodes = 0 ;
	Node< NodeType > *CurrentNode = FirstNode ;
	while ( CurrentNode != NULL)
		{
		NosOfNodes++;
		CurrentNode = CurrentNode->NextNode;
		}
	return NosOfNodes;
}



/**********************************************************************/
template<class NodeType>
bool DoubleLinkList<NodeType>::CompSearch(char *Name)       //通配符查询
{
	int i,j=0,k=0;
	Node< NodeType > *CurrentNode=FirstNode;
	for(i=0;i<strlen(Name);i++)                            //利用循环算法来历遍每一个字符
		if(Name[i]=='?') break;              //找到？跳出
	if(Name[i]!='?') 
	{
		{while(strcmp(CurrentNode->Data.name,Name)!=0&&CurrentNode->NextNode!=NULL)
			CurrentNode=CurrentNode->NextNode;}
		if(strcmp(CurrentNode->Data.name,Name)==0)
		{	
		cout<<"查找的结点为:";
		CurrentNode->Show();	
		cout<<"按任意键继续.";
		getch();
		}
		else
		{cout<<"查找的结点不存在!"<<endl;}
	}
	
	if(Name[i]=='?')
	{
		while(CurrentNode!=NULL)
		{
			int j=0;
			while((Name[j]=='?'||CurrentNode->Data.name[j]==Name[j])&&CurrentNode->Data.name[j])
				j++;                                       //匹配带有？的字符和原字符串
			if(j==strlen(CurrentNode->Data.name))
			{
				cout<<"查找的结点为:\n";
				CurrentNode->Show();
				k++;
			}
			CurrentNode=CurrentNode->NextNode;	
		}
		if(k) return true;
		else return false;
	} 
}

/**********************************************************************/
template<class NodeType>
bool DoubleLinkList<NodeType>::SearchByTel(char *Tel)      //根据号码查询
{
	Node< NodeType > *CurrentNode=FirstNode;
	while(strcmp(CurrentNode->Data.tel,Tel)!=0&&CurrentNode->NextNode!=NULL)
			CurrentNode=CurrentNode->NextNode;
	if(strcmp(CurrentNode->Data.tel,Tel)==0)
	{
		cout<<"查找的结点为:";
		CurrentNode->Show();
		return true;
	}
	else
	{
		cout<<"查找结点不存在!"<<endl;
		return false;
	}
}

/**********************************************************************/
template<class NodeType>
bool DoubleLinkList<NodeType>::SearchByIndex(int Index)     //根据序号查询
{
	Node< NodeType > *CurrentNode=FirstNode;
	while(CurrentNode->Data.index!=Index&&CurrentNode->NextNode!=NULL)
			CurrentNode=CurrentNode->NextNode;
	if(CurrentNode->Data.index==Index)
	{
		cout<<"查找的结点为:";
		CurrentNode->Show();
		return true;
	}
	else
	{
		cout<<"查找结点不存在!"<<endl;
		return false;
	}
}

/**********************************************************************/
template<class NodeType>
bool DoubleLinkList<NodeType>::UpdataByName(char *Name)    //根据姓名修改
{
	int Option5,Age;
	char Tel[20],choice;
	Node< NodeType > *CurrentNode=FirstNode;
	while(strcmp(CurrentNode->Data.name,Name)!=0&&CurrentNode->NextNode!=NULL)
			CurrentNode=CurrentNode->NextNode;             //寻找需要修改的节点
	if(strcmp(CurrentNode->Data.name,Name)==0)
	{
		cout<<"修改的结点为:";
		CurrentNode->Show();
		cout<<"修改内容.\n1.修改电话,\n2.修改年龄.\n请选择:";
		cin>>Option5;
		switch(Option5)
			{
				case 1: cout<<"请输入电话:";
					cin>>Tel;
					cout<<"改为:"<<endl
						<<CurrentNode->Data.index<<"."<<CurrentNode->Data.name<<" "
						<<Tel<<" "<<CurrentNode->Data.age<<endl
						<<"是否修改(YorN)";
					cin>>choice;
					if(choice=='Y'||choice=='y')
					{
						strcpy(CurrentNode->Data.tel,Tel); 
						cout<<"修改成功!";
					}
					break;
				case 2: cout<<"请输入序年龄:";
					cin>>Age;
					cout<<"改为:"<<endl
						<<CurrentNode->Data.index<<"."<<CurrentNode->Data.name<<" "
						<<CurrentNode->Data.tel<<" "<<Age<<endl
						<<"是否修改(YorN)";
					cin>>choice;
					if(choice=='Y'||choice=='y')
					{
						CurrentNode->Data.age=Age; 
						cout<<"修改成功!";
					}
					break;
				default :cout<<"错误!"; break;
		}
		return true;
	}
	else
	{
		cout<<"修改的结点不存在!"<<endl;
		return false;
	}
}

/**********************************************************************/
template<class NodeType>
bool DoubleLinkList<NodeType>::UpdataByTel(char *Tel)//根据号码修改
{
	int Option5,Age;
	char choice;
	Node< NodeType > *CurrentNode=FirstNode;
	while(strcmp(CurrentNode->Data.tel,Tel)!=0&&CurrentNode->NextNode!=NULL)
			CurrentNode=CurrentNode->NextNode;
	if(strcmp(CurrentNode->Data.tel,Tel)==0)
	{
		cout<<"修改的结点为:";
		CurrentNode->Show();
		cout<<"修改内容.\n1.修改电话,\n2.修改年龄.\n请选择:";
		cin>>Option5;
		switch(Option5)
			{
				case 1: cout<<"请输入电话:";
					cin>>Tel;
					cout<<"改为:"<<endl
						<<CurrentNode->Data.index<<"."<<CurrentNode->Data.name<<" "
						<<Tel<<" "<<CurrentNode->Data.age<<endl
						<<"是否修改(YorN)";
					cin>>choice;
					if(choice=='Y'||choice=='y')
					{
						strcpy(CurrentNode->Data.tel,Tel); 
						cout<<"修改成功!";
					}
					break;
				case 2: cout<<"请输入序年龄:";
					cin>>Age;
					cout<<"改为:"<<endl
						<<CurrentNode->Data.index<<"."<<CurrentNode->Data.name<<" "
						<<CurrentNode->Data.tel<<" "<<Age<<endl
						<<"是否修改(YorN)";
					cin>>choice;
					if(choice=='Y'||choice=='y')
					{
						CurrentNode->Data.age=Age; 
						cout<<"修改成功!";
					}
					break;
				default :cout<<"错误!"; break;
		}
		return true;
	}
	else
	{
		cout<<"修改的结点不存在!"<<endl;
		return false;
	}
}

/**********************************************************************/
template<class NodeType>
bool DoubleLinkList<NodeType>::UpdataByIndex(int Index)//根据序号修改
{
	int Option6,Age;
	char Tel[20],choice;
	Node< NodeType > *CurrentNode=FirstNode;
	while(CurrentNode->Data.index!=Index&&CurrentNode->NextNode!=NULL)
			CurrentNode=CurrentNode->NextNode;
	if(CurrentNode->Data.index==Index)
	{
		cout<<"修改的结点为:";
		CurrentNode->Show();	
		cout<<"修改内容.\n1.修改电话,\n2.修改年龄.\n请选择:";
		cin>>Option6;
		switch(Option6)
			{
				case 1: cout<<"请输入电话:";
					cin>>Tel;
					cout<<"改为:"<<endl
						<<CurrentNode->Data.index<<"."<<CurrentNode->Data.name<<" "
						<<Tel<<" "<<CurrentNode->Data.age<<endl
						<<"是否修改(YorN)";
					cin>>choice;
					if(choice=='Y'||choice=='y')
					{
						strcpy(CurrentNode->Data.tel,Tel); 
						cout<<"修改成功!";
					}
					break;
				case 2: cout<<"请输入序年龄:";
					cin>>Age;
					cout<<"改为:"<<endl
						<<CurrentNode->Data.index<<"."<<CurrentNode->Data.name<<" "
						<<CurrentNode->Data.tel<<" "<<Age<<endl
						<<"是否修改(YorN)";
					cin>>choice;
					if(choice=='Y'||choice=='y')
					{
						CurrentNode->Data.age=Age; 
						cout<<"修改成功!";
					}
					break;
				default :cout<<"错误!"; break;
		}
		return true;
	}
	else
	{
		cout<<"修改的结点不存在!"<<endl;
		return false;
	}
}

/**********************************************************************/
template<class NodeType>
bool DoubleLinkList<NodeType>::LoadFromFile(char *filename)            //从文件中提取数据
{
	NodeType VAlue;

	ifstream infile;
	infile.open(filename);
	if(!infile)
	{
		cout<<"打开文件错误!\n";
		exit(0);
	}                      
	while(infile>>VAlue.index)
	{
		infile>>VAlue.name>>VAlue.tel>>VAlue.age;                     //将数据输出到节点中
		AddNode(VAlue);                                               //将节点按序加入链表中
	}
	infile.close();
	cout<<"文件读取完毕!";
	return true;
}

/**********************************************************************/
template<class NodeType>
bool DoubleLinkList<NodeType>::SaveToFile(char *filename)              //将数据保存到文件中
{
	ofstream outfile;
	outfile.open(filename);
	if(!outfile)
	{
		cout<<"打开文件错误!\n";
		exit(0);
	}
	Node<NodeType>*CurrentNode=FirstNode;
	while(CurrentNode)
	{
		outfile<<CurrentNode->Data.index<<" "<<CurrentNode->Data.name<<" "
		<<CurrentNode->Data.tel<<" "<<CurrentNode->Data.age<<endl;
		CurrentNode=CurrentNode->NextNode;
	}
	cout<<"文件存储完毕!";
	return true;
}


