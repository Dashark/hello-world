#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
class Parallelogram {
	public:
		int show()
		{
			printf("height:%d length:%d\n",h,l);
			return 0;
		}

		int area()
		{
			return h*l;
		}

		int height()
		{
			return h;
		}

		int length()
		{
			return l;
		}


		Parallelogram(int _h,int _l)
		{
			h=_h;
			l=_l;
		}

		Parallelogram()
		{
			h=l=0;
		}
	private:
		int h,l;
};
int main() {
	Parallelogram pg(2,3);
	pg.show();
	pg.area();
	pg.height();
	pg.length();
	return 0;
}
