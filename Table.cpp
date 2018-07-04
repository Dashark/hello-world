#include<iostream> 
#include<string.h>
using namespace std;

class Table
{
	public:
		Table();
		Table(int aa,int bb)
		{
			a=aa;
			b=bb;
			for(int i=0;i<10;i++)
        	for(int j=0;j<10;j++)
        	concept[i][j]=1;
        	for(int i=0;i<15;i++)
        	words[i]='\0';
		}
	    void show();
	    void addRow();
	    void addColumn();
	    void set(int i,int j,int k);
	    void set(int i,int j,char str[]);
	    void delRow(int i);
	    void delColumn(int i);
	private:
		int a,b;
		int concept[10][10];
		int c;
		char words[15];
};

Table::Table()
{
	a=2;
	b=2;
	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
	concept[i][j]=1;
}

void Table::show()
{
	if(a<=0 || b<=0) cout<<"无法制成表格"; 
	else
	{
		int i,j;
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			for(int k=0;k<15;k++)
			cout<<'*';
			cout<<'*'<<endl;
			for(j=0;j<b;j++)
			{
				cout<<'*';
				if(concept[i][j]==1)
				for(int k=0;k<14;k++)
				cout<<' ';                                                        
				else if(concept[i][j]==3)
				{
					int len;
					len=strlen(words);
					for(int k=0;k<len;k++)
					cout<<words[k];
					for(int k=0;k<14-len;k++)
					cout<<' ';
				}
				else
				{
					int count=0;
					cout<<c;
					int obj=c;
					while(obj/10!=0)
					{
						count++;
						obj=obj/10;
					}				
					for(int k=0;k<14-count-1;k++)
					cout<<' ';
				}
			}
			cout<<'*'<<endl;
		}
		for(j=0;j<b;j++)
		for(int k=0;k<15;k++)
		cout<<'*';
		cout<<'*'<<endl;
		cout<<endl<<endl;
	} 
}

void Table::addRow()  {a++;}
void Table::addColumn()  {b++;}
void Table::delRow(int i)
{
	if(i>a) cout<<"显示行数过小";
	else a-=i;
}
void Table::delColumn(int i)
{
	if(i>b) cout<<"显示列数过小";
	else b-=i;
}

void Table::set(int i,int j,int k)
{
	concept[i-1][j-1]=2;
	c=k;
}

void Table::set(int i,int j,char str[])
{
	concept[i-1][j-1]=3;
	if(strlen(str)<=14)
	for(i=0;i<strlen(str);i++)
	words[i]=str[i];
	else
	for(i=0;i<14;i++)
	words[i]=str[i];
	
}

int main() {
  Table tb;
  tb.show();
  tb.addRow();
  tb.show();
  tb.addColumn();
  tb.show();
  Table tb1(5,5);
  tb1.show();
  tb1.set(1,1,30);
  tb1.set(2,2,"hello");
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(1);
  tb1.show();
  return 0;
}
