#include"Prime.cpp"

template<class Type>
void func(Type a) 
{
	//a.findPrime(100 , 999);
	cout << "素数为：" << endl; 
	a.showPrime();
}
int main(){
	
	Prime a(100,999);  //强制的 
	func(a);
	
	superPrime b(100,999);
	func(b);
	
	return 0;
}
