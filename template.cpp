#include <iostream>
template<class T>
T Max(T x, T y) {
  return x > y ? x : y;
}
int main() {
  std::cout << "最大数：" << Max(7.0, 8.8) << std::endl; 
  std::cout << "最大数：" << Max(9, 8) << std::endl; 
  return 0;
} 
