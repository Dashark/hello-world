#include<iostream>//没解决控制平行四边形斜边方向的问题，只能默认向右，不想搞了
#include<math.h>
using namespace std;
class Parallelogram 
{
	public:
		void show();
    	int area();
    	int height();
    	int length();
    private:
		int a,h;//底边与高
		int b;//控制形状
		/*
		******
  		  ******
                    ******
                      ****** 
              比如此处b=2，每行间隔2个空格*/
		char dir[10]; 
		  	
};


void Parallelogram::show()
{
	cout<<"请依次输入底边长，高度，以及决定形状的间隔，每个数据以空格隔开（间隔数不能超过5）："<<endl;
	cin>>a>>h>>b;//
	//gets(dir);
	//if(dir=="right")
	{
		if(b>5){printf("输入的间隔数不符合要求但可以给出平行四边形的数据\n");}
		else for(int i=0;i<h;i++)
		{
			for(int i=0;i<a;i++)
			{
			if(i==a-1){printf("*\n");
			}
			else printf("*");
			}
			for(int f=0;f<=i;f++)
			{
			if(b==1){printf(" ");//形状 
			}
			if(b==2){printf("  ");
			}
			if(b==3){printf("   ");
			}
			if(b==4){printf("    ");
			}
			if(b==5){printf("     ");
			}
			else printf("");
			}
			
		}
		
	}
	
	if(dir=="left")
	{
		for(int i=h;i>0;i--)
		{
			
			for(int f=i;f>0;f--)
			{
			if(b=1){printf(" ");//形状 
			}
			if(b=2){printf("  ");
			}
			if(b=3){printf("   ");
			}
			if(b=4){printf("    ");
			}
			if(b=5){printf("     ");
			}
			else printf("");
			}
			for(int i=0;i<a;i++)
			{
			if(i=a){printf("*\n");
			}
			else printf("*");
			}	
		}
	}
	
}

int Parallelogram::area()
{
	int s;
	s=a*h;
	printf("面积为：%d  ",s); 
}


int Parallelogram::height()
{
	printf("高为：%d  ",h);
}

int Parallelogram::length()
{
	double m,l;
	m=sqrt(h*h+(h*(b-1)*h*(b-1)));
	l=2*(m+a);
	printf("边长为：%lf",l); 
}
int main() {
  Parallelogram pg;
  pg.show();
  pg.area();
  pg.height();
  pg.length();
  return 0;
}
