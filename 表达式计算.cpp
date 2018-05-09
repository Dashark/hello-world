#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct{ 
	double data[100];
	int top;
}Stack;
int ST=0;
int icp(char a){
	switch(a){
	case '#':return 0;
	case '(':return 6;
	case '*':return 4;
	case '/':return 4;
	case '+':return 2;
	case '-':return 2;
	case ')':return 6;
	}
	return -1;
}
double push(Stack& a,double b){
	a.top++;
	a.data[a.top] = b;
	return 1;
}
double pop(Stack& a){
	a.top--;
	return a.data[a.top+1];
}
double CtoB(char* a,char *b){
	Stack sver,cpter;
	sver.top=0;sver.data[sver.top]='#';
	cpter.top=-1;
	int i,count=0;
	for(i=0;i<strlen(a);i++){
		char x = a[i];
		if(icp(x) == -1 || ST==0){
			ST=1;
			int k=0;
			char my_num[10];
			while(icp(a[i]) == -1){
				my_num[k]=a[i];my_num[k+1]='\0';
				k++;i++;
			}
			i--;
			push(cpter,atof(my_num));
		}
		else{
			int flag;
			do{
				if(x=='(') ST=0;
				flag=1;
				if( (icp(sver.data[sver.top]) >= icp(x) && sver.data[sver.top]!='#' && abs(sver.data[sver.top]-'('>0.1) ) || (abs(x-')')<0.1 && sver.data[sver.top]!='(') ){
					flag=0;
					double a = pop(cpter);
					double b = pop(cpter);
					if(sver.data[sver.top]== '+')	push(cpter,b+a);
					else if(abs(sver.data[sver.top] - '-') <0.1)	push(cpter,b-a);
					else if(abs(sver.data[sver.top] - '*') <0.1)	push(cpter,b*a);
					else if(abs(sver.data[sver.top] - '/') <0.1)	push(cpter,b/a);
					pop(sver);
				}
				else if ( icp(sver.data[sver.top]) < icp(x) || (sver.data[sver.top]=='(' && abs(x-')')>0.1 ) )
					push(sver,x);
				else pop(sver);
			
			}while(flag==0);
		}
	}
	return cpter.data[cpter.top];
}
int main()
{
	printf("请输入一个表达式:可含 + - * / 与 小括号:\n");
	char a[100];char b[100];
	gets(a);
	a[strlen(a)+1]='\0';a[strlen(a)]='#';
	printf("结果是:%.2lf\n",CtoB(a,b));
	return 0;
}