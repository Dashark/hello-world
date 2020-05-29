#include <iostream>
#define Max(x,y)  (x > y ? x : y)
int main() {
  std::cout << "最大数：" << Max(7 + 0.7, 8 + 0.8) << std::endl; 
  std::cout << "最大数：" << Max(9, 8) << std::endl; 
  return 0;
} 
