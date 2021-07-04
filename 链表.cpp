#include<stdlib.h> 
#include<stdio.h>
#include<string.h> 
//数据的设计
//数据用链表来处理数据
//数据的内容
struct bookInfo
{
	char name[20];
	float price;
	int num;//书的数量 
}; 

struct Node
{
	struct bookInfo data;
	struct Node* next;
};
struct Node* list=NULL;

//创建表头 
struct Node*creatHead()
{
	//动态内存申请
	struct Node* headNode=(struct Node*)malloc(sizeof(struct Node));
	headNode->next=NULL;
	return headNode; 
};
 
//创建节点：为插入做准备
//把用户数据变为架构体变量 
struct Node* creatNode(struct bookInfo data)
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}; 
 
//插入  表头法插入
void insertNodeByhead(struct Node* headNode,struct bookInfo data)
{
	struct Node *newNode=creatNode(data);
	//先连接后断开 
	newNode->next=headNode->next;
	headNode->next=newNode;
 } 
// void insertNodeByTail(struct Node*headNode,int data)
// {
// 	struct Node*pMove=headNode;
// 	while(pMove->next!=NULL)
// 	{
// 		pMove = pMove->next;
//	 }
//	 struct Node*newNode = creatNode(data);
//	 pMove->next=newNode;
// };表尾法插入 

struct Node*searchByName(struct Node* headNode,char *bookName)
{
	struct Node*posNode = headNode->next;
	while(posNode!=NULL&&strcmp(posNode->data.name,bookName))
	{
		posNode = posNode->next;
	}
	return posNode;//返回空则没找到，返回非空则找到了 
}
void printfList(struct Node* headNode)
{
	struct Node*pMove=headNode->next;
	printf("书名\t价格\t数量\n"); 
	while(pMove!=NULL)
	{
		printf("%s\t%.1f\t%d\n",pMove->data.name,pMove->data.price,pMove->data.num);
		pMove=pMove->next;
	}
}

//指定位置删除
void deleteNodeByname(struct Node*headNode,char* bookName)
{
	struct Node* posLeftNode=headNode;
	struct Node* posNode=headNode->next;
	//书籍名字是字符串 ,字符串比较函数处理 
	while(posNode!=NULL&&strcmp(posNode->data.name,bookName))
	{
		posLeftNode=posNode;
		posNode=posLeftNode->next;
	}
	if(posNode==NULL)
	return;
	else
	{
		printf("删除成功！");
		posLeftNode->next=posNode->next;
		free(posNode);
		posNode=NULL;
	}
 } 
 
 //写界面--->菜单---->模块
void makeMenu()
{
	
	printf("         四川大学图书管理系统    \n");
	printf("         0.退出系统\n"); 
	printf("         1.登记书籍\n"); 
	printf("         2.浏览书籍\n"); 
	printf("         3.借阅书籍\n"); 
	printf("         4.归还书籍\n");  
	printf("         5.书籍排序\n"); 
	printf("         6.删除书籍\n"); 
	printf("         7.查找书籍\n"); 
	printf("---------------------------------\n");
	printf("请输入（0~7）"); 
} 
//直接文件操作
//存操作 
void saveInfoToFile(const char*fileName,struct Node* headNode)
{
	FILE *fp = fopen(fileName,"w");
	struct Node*pMove=headNode->next;
	while(pMove != NULL)
	{
		fprintf(fp,"%s\t%.1f\t%d\n",pMove->data.name,pMove->data.price,pMove->data.num);
		pMove=pMove->next;
	 } 
	fclose(fp); 
}
//文件读操作
void readInfoFromFile(const char* fileName,struct Node*headNode)
{
	FILE *fp=fopen(fileName,"r");//第一次打开文件肯定不存在 
	if(fp==NULL)
	{   //不存在就创建出来这个文件 
		fp=fopen(fileName,"w+");
	}
	struct bookInfo tempData;
	while(fscanf(fp,"%s\t%f\t%d\n",tempData.name,&tempData.price,&tempData.num)!=EOF)
	{
		insertNodeByhead(list,tempData);
	}
	fclose(fp);
} 
void bubbleSort(struct Node*headNode)
{
	for(struct Node* p=headNode->next;p!=NULL;p=p->next)
	{
		for(struct Node*q=headNode->next;q->next!=NULL;q=q->next)
		{
			if(q->data.price > q->next->data.price)
			{
				//交换值 
				struct bookInfo temp=q->data;
				q->data=q->next->data;
				q->next->data=temp;
			}
		}
	}
	printfList(headNode);
}

//做交互
 void keyDown()
{
	int userKey=0;
	struct bookInfo temp;//产生临时变量，存储书籍信息 
	scanf("%d",&userKey);
	switch(userKey)
	{
		case 0:
			printf("【退出】\n");
			printf("退出成功！\n");
			system("pause");
			exit(0);//关闭整个程序 
			break;
		case 1:
			printf("【登记】\n");
			printf("输入书籍的信息（name,price,num）:");
			scanf("%s%f%d",temp.name,&temp.price,&temp.num); 
			insertNodeByhead(list,temp);
			saveInfoToFile("bookinfo.txt",list);
			break;
		case 2:
			printf("【浏览】\n");
			printfList(list);
			break;
		case 3:
		{	
			printf("【借阅】\n");
			printf("输入要借的书籍名字（name）:");//书籍存在，可以借阅，数量-1； 不存在则借阅失败 
			scanf("%s",temp.name);
			struct Node*result=searchByName(list,temp.name);
			if(result==NULL)
			{
				printf("没有相关书籍，无法借阅！\n");
			}
			else
			{
				if(result->data.num==0)
				{
					printf("书籍数量为0，无法借阅！\n"); 
				}
				else
				{
					result->data.num--;
					printf("借阅成功！当前书籍数量为%d\n",result->data.num); 
				}
			}
	        saveInfoToFile("bookinfo.txt",list);
			break;
	    }
		case 4:
		{
			printf("【归还】\n");//书籍数量-1 
			printf("输入要还的书籍名字（name）:"); 
			scanf("%s",temp.name);
			struct Node*result=searchByName(list,temp.name);
			if(result==NULL)
			{
				printf("没有相关书籍，无法归还！\n");
			}
			else
			{
				result->data.num++;
				printf("归还成功！当前书籍数量为%d\n",result->data.num); 
			}
			saveInfoToFile("bookinfo.txt",list);
			break;
	    }
	    case 5:
	    	printf("【排序】\n");
	    	bubbleSort(list);
	    	break;
		case 6:
			printf("【删除】\n");
			printf("请输入删除书籍的名字");
			scanf("%s",temp.name);
			deleteNodeByname(list,temp.name);
			saveInfoToFile("bookinfo.txt",list);
			break;
		case 7:
		{
				
			printf("【查找】\n");
			printf("请输入要查找的书名");
			scanf("%s",temp.name);
		    struct Node* result=searchByName(list,temp.name);
			if(result==NULL)
			{
				printf("没有找到该书籍！");
			}
			else
			{
				printf("书名\t价格\t数量\n");
				printf("%s\t%.1f%d",result->data.name,result->data.price,result->data.num);
			}
			break;
	    }
		default:
			printf("【error】\n");
			break;
	}
}
int main()
{
	list=creatHead();
	readInfoFromFile("bookinfo.txt",list);
	while(1)
	{
		makeMenu();
		keyDown();
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;	
}
