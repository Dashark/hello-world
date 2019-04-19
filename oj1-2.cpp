#include <iostream>
using namespace std;
///第1行是一个整数n，表示随后有n组数据。
//每组数据占一行，包括三种队形的队尾人数a，b，c，用空格隔开。
//已知队伍总人数不小于10，不大于100。
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class HanXin{
	public:
		HanXin();//初始化为0 
		void line3(int n1);
		void line5(int n2);
		void line7(int n3);
		void showMany();//读入a，b，c并计算输出people
		~HanXin();//析构 
	private:
		int people,x,y,z;
		int a,b,c;//3，5，7 
};
int main() {
    int n,n1,n2,n3;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> n1 >> n2 >> n3;
        HanXin hx;  //韩信
        hx.line3(n1);  //3人一排
        hx.line5(n2);   //5人一排
        hx.line7(n3);   //7人一排
        hx.showMany();
    }
    return 0;
}
HanXin::HanXin(){
	people=10;
	a=0,b=0,c=0;
}
HanXin::~HanXin(){}
void HanXin::line3(int n1){
	a=n1;
}
void HanXin::line5(int n2){
	b=n2;
}
void HanXin::line7(int n3){
	c=n3;
}
void HanXin::showMany(){
	for(int i=10;i<=100;i++,people++)
	{
		if((people%3==a)&&(people%5==b)&&(people%7==c)) 
		{
	    	cout<<people<<endl;
		    break;
		}
		else if(i==100) cout<<"Impossible"<<endl;
	}
}





