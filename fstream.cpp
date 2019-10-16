//-std=c++11
#include <iostream>
#include <fstream>
#include <string>
 
int main() {
  std::string filename = "Test.b";
  // 准备读取文件
  double d = 3.14;
  std::ofstream(filename, std::ios::binary).write(reinterpret_cast<char*>(&d), sizeof d)
     << 123 << "abc";
  // 打开文件以读取
  std::ifstream istrm(filename, std::ios::binary);
  if (!istrm.is_open()) {
    std::cout << "failed to open " << filename << '\n';
  } else {
    double d;
    istrm.read(reinterpret_cast<char*>(&d), sizeof d); // 二进制输入
    int n;
    std::string s;
    if (istrm >> n >> s)                               // 文本输入
      std::cout << "read back from file: " << d << ' ' << n << ' ' << s << '\n';
  }
}
