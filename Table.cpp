#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Table
{
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
					if(table[i][j].second==-1){printf("NULL");}
					else if(table[i][j].second==0){printf("%d",table[i][j].first.INT);}
					else if(table[i][j].second==1){printf("%lf",table[i][j].first.DOUBLE);}
					else if(table[i][j].second==2){printf("%s",table[i][j].first.STR);}
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
				Union tmp;
				table[i].push_back(make_pair(tmp,-1));
			}
			return 0;
		}
		
		int addRow()
		{
			vector<pair<Union,int> > tmp;
			Union tmp2;
			int len=0;
			if((int)table.size()>0)
				len=(int)table[0].size();
			while(len--)
				tmp.push_back(make_pair(tmp2,-1));
			table.push_back(tmp);
			return 0;
		}
		
		int set(int x,int y,int val)
		{
			if(exist(x,y))
				return 1;
			x--;
			y--;
			table[x][y].second=0;
			table[x][y].first.INT=val;
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
		
		int set(int x,int y,char val[])
		{
			if(exist(x,y))
				return 1;
			x--;
			y--;
			table[x][y].second=2;
			int len=strlen(val);
			const int MAXLEN=100;
			memset(table[x][y].first.STR,0,sizeof(table[x][y].first.STR));
			strncpy(table[x][y].first.STR,val,min(len,MAXLEN));
			return 0;
		}
		
		int set(int x,int y,double val)
		{
			if(exist(x,y))
				return 1;
			x--;
			y--;
			table[x][y].second=1;
			table[x][y].first.DOUBLE=val;
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
		
	private:
		union Union{
			int INT;
			double DOUBLE;
			char STR[100];
		};
		vector<vector<pair<Union,int> > > table;
		//int means the type of variable
		//-1 --> unused
		//0 --> int
		//1 --> double
		//2 --> str
};

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
  tb1.set(2,2,(char *)"hello");
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(1);
  tb1.show();
  return 0;
}
