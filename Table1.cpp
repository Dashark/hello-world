#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Cell {
	public:
		Cell(){type=-1;}
		~Cell(){}
		
		int set(int val)
		{
			type=0;
			value.INT=val;
			return 0;
		}
		
		int set(char val[])
		{
			type=2;
			int len=strlen(val);
			const int MAXLEN=100;
			memset(value.STR,0,sizeof(value.STR));
			strncpy(value.STR,val,min(len,MAXLEN));
			return 0;
		}
		
		int set(double val)
		{
			type=1;
			value.DOUBLE=val;
			return 0;
		}
		
		int show()
		{
			if(type==-1){printf("NULL");}
			else if(type==0){printf("%d",value.INT);}
			else if(type==1){printf("%lf",value.DOUBLE);}
			else if(type==2){printf("%s",value.STR);}
			return 0;
		}
		
	private:
		union Union{
			int INT;
			double DOUBLE;
			char STR[100];
		};
		
		int type;
		Union value;
};

class Table {
	public:
		Table(){}
		
		Table(int x,int y)
		{
			for(int i=1;i<=x;i++)
				addRow();
			for(int i=1;i<=y;i++)
				addColumn();
		}
		
		int show()
		{
			printf("Table are printed below:\n");
			for(int i=0;i<(int)table.size();i++)
			{
				for(int j=0;j<(int)table[i].size();j++)
				{
					table[i][j].show();
					printf("\t");
				}
				printf("\n");
			}
			return 0;
		}
		
		int addColumn()
		{
			for(int i=0;i<(int)table.size();i++)
			{
				Cell cell;
				table[i].push_back(cell);
			}
			return 0;
		}
		
		int addRow()
		{
			vector<Cell> tmp;
			Cell tmp2;
			int len=0;
			if((int)table.size()>0)
				len=(int)table[0].size();
			while(len--)
				tmp.push_back(tmp2);
			table.push_back(tmp);
			return 0;
		}
		
		int delRow(int x)
		{
			table.erase(table.begin()+(x-1));
			return 0;
		}
		
		int delColumn(int y)
		{
			for(int i=0;i<(int)table.size();i++)
			{
				table[i].erase(table[i].begin()+(y-1));
			}
			return 0;
		}
		
		int exist(int x,int y)
		{
			if(x<1 || x>(int)table.size())
				return 1;
			if((int)table.size()==0)
				return 1;
			if(y<1 || y>(int)table[0].size())
				return 1;
			return 0;
		}
		
		int set(int x,int y,int val)
		{
			if(exist(x,y))
				return 1;
			x--;y--;
			table[x][y].set(val);
			return 0;
		}
		
		int set(int x,int y,char val[])
		{
			if(exist(x,y))
				return 1;
			x--;y--;
			table[x][y].set(val);
			return 0;
		}
		
		int set(int x,int y,double val)
		{
			if(exist(x,y))
				return 1;
			x--;y--;
			table[x][y].set(val);
		}
		
	private:
		vector<vector<Cell> > table;
};

int main()
{
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
