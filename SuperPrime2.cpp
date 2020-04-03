#include <iostream>
class Set {
  public:
  	Set(int from, int to) {
	}
  	~Set() {
	}
  	int count() {
	}
  	int sum() {
	}
  private:
  	int set[1000];
};
int main() {
  Set ss(100, 999);
  std::cout << "How Many: " << ss.count() << std::endl;
  std::cout << "Sum is " << ss.sum() << std::endl;
  return 0;
}
