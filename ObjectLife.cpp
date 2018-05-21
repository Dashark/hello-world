//use the Stock class
#include<iostream>
#include"ConstructExpress.cpp"
int main() {
	{
		using std::cout;
		cout << "Using constructors to create new objiects\n";
		Stock stock1("NanoSmart",12,20.0);
		stock1.show();
	}
	return 0;
}
