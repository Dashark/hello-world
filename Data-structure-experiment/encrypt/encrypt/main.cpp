#include"utility.h"
#include"encrypt.h"
#include"iostream"

int main()
{
	using namespace std;
	int choice = 1;
	char FO[256],CO[256];
	ENCRYPT MO;

	while (choice!=3)
	{
		cout << "1.加密——将已经输入的文本串进行加密后输出。" << endl;
		cout << "2.解密——将已经输入的已加密的文本解密后输出。" << endl;
		cout << "3.退出——退出运行。" << endl;
		cout << "请选择";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
		{
			cout << "请输入文本串：";
			cin >> FO;
			strcpy(CO, MO.Encode(FO).CStr());
			cout << "加密串：" << CO << endl<<endl;
			break;
		}
		case 2:
		{
			cout << "请输入加密串";
			cin >> FO;
			strcpy(CO, MO.Decode(FO).CStr());
			cout << "解密串：" << CO << endl<<endl;
			break;
		}
		}

	}
	cin.get();
	return 0;
}