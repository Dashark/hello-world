#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


//fft-start
const double delta=0.001;
const int MAXLEN=4000010;
char str1[MAXLEN],str2[MAXLEN];

struct Complex{
	double real,image;
	Complex(double _real,double _image){real=_real,image=_image;}
	Complex(){}
};

Complex *a=new Complex[MAXLEN];
Complex *b=new Complex[MAXLEN];
Complex *fourier_tmp=new Complex[MAXLEN];

Complex operator + (const Complex &A,const Complex &B) {return Complex(A.real+B.real,A.image+B.image);}

Complex operator - (const Complex &A,const Complex &B) {return Complex(A.real-B.real,A.image-B.image);}

Complex operator * (const Complex &A,const Complex &B) {return Complex(A.real*B.real-A.image*B.image,A.image*B.real+A.real*B.image);}

Complex operator / (const Complex &A,const int B) {return Complex(A.real/B,A.image/B);}

void recursive_fft(Complex *a, int n,int fft)
{
	if(n==1)
		return ;
	Complex wn;
	wn.real=cos(2*M_PI/n);
	wn.image=sin(2*M_PI/n)*fft;
	for(int i=0;i<n;i++)
		if(i&1)
			fourier_tmp[(i>>1)]=a[i];
		else
			fourier_tmp[(i>>1)+(n>>1)]=a[i];
	for(int i=0;i<n;i++)
		a[i]=fourier_tmp[i];
	recursive_fft(a+(n>>1),n>>1,fft);
	recursive_fft(a,n>>1,fft);
	Complex w(1,0);
	for(int i=0;i<(n>>1);i++)
	{
		fourier_tmp[i]=a[i+(n>>1)]+w*a[i];
		fourier_tmp[i+(n>>1)]=a[i+(n>>1)]-w*a[i];
		w=w*wn;
	}
	for(int i=0;i<n;i++)
		a[i]=fourier_tmp[i];
	return ;
}

int output(Complex *a,int len)
{
	bool first=true;
	for(int i=len-1;i>=0;i--)
	{
		if(fabs(a[i].real)>delta)
			first=false;
		if(!first)
			printf("%.0lf",fabs(a[i].real));
	}
	if(first)
		printf("0");
	printf("\n");
	return 0;
}

int fft_sample()
{
	scanf("%*d");
	while(~scanf("%s%s",str1,str2))
	{
		int len1=strlen(str1),len2=strlen(str2);
		int len=1;
		while(len<max(len1,len2))
			len<<=1;
		len<<=1;
		for(int i=0;i<len1;i++)
			a[i]=Complex(str1[len1-i-1]-'0',0);
		for(int i=len1;i<len;i++)
			a[i]=Complex(0,0);
		for(int i=0;i<len2;i++)
			b[i]=Complex(str2[len2-i-1]-'0',0);
		for(int i=len2;i<len;i++)
			b[i]=Complex(0,0);
		recursive_fft(a,len,1);
		recursive_fft(b,len,1);
		for(int i=0;i<len;i++)
			a[i]=a[i]*b[i];
		recursive_fft(a,len,-1);
		for(int i=0;i<len;i++)
		{
			a[i]=a[i]/len;
			a[i].real=fabs(a[i].real);
		}
		for(int i=0;i<len-1;i++)
		{
			a[i+1].real+=(int)(a[i].real+0.5)/10;
			a[i].real=(int)(a[i].real+0.5)%10;
		}
		output(a,len);
	}
	return 0;
}
//fft-end

class Clock {
	public:
		Clock(){}
		~Clock(){}
		
		void tick()
		{
			time_t t=time(0);
			tm* tt=localtime(&t);
			hour=tt->tm_hour;
			minute=tt->tm_min;
			second=tt->tm_sec;
		}
		
		void show()
		{
			printf("%02d:%02d:%02d\n",hour,minute,second);
			return;
		}
		
		void adjust(int h,int m,int s)
		{
			hour=h,minute=m,second=s;
			return;
		}
	private:
		int hour,minute,second;
};

int main() {
  Clock ck;
  ck.tick();
  ck.show();
  ck.adjust(16,45,00);
  ck.show();
  return 0;
}
