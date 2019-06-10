//Warning
//Error
//Exception(“Ï≥£) 
float something() {
	float x=0, y=0;
	if(y != 0)
	  float z = x / y;
	else
	   throw 8;
	return z;
}
int main() {
	try {
		float z = something();
	}
	catch(int n) {
		if(n==8)
		   std::cout << "Zero division" << std::endl;
	}
	catch(...) {
	}
}
