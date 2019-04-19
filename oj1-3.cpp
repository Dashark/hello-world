#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Number
{
	public:
		Number(int num1);
		void converto(int num3);
//		void show();
		~Number();
	private:
		int num,k,j=0;
		int temp[100];
};
int main() {
    int n, n1, n2;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> n1 >> n2;
        Number no1(n1);     //n1是10进制正整数
        no1.converto(n2);  //n3是n2进制的n1的正整数
//        no1.show();     //输出结果
    }

}
Number::Number(int num1){
	num=num1;
}
void Number::converto(int num3){
	k=num3;
	j=0;
	while(num){
		temp[j]=num%k;
		j++;
		num/=k;
	}
	int mid;
	for(mid=j-1;mid>=0;mid--)
	{
		cout<<temp[mid];
	}
	cout<<endl;
}

Number::~Number(){}



