#include <iostream>
#include <vector>
/** 
  * 定义素数对象
  */
class Prime {
public:
  Prime(int n) : num_(n) {
  }
  Prime(const Prime &obj) : num_(obj.num_) {
  }
  ~Prime() {
  }
  bool isPrime() const {  //常函数 
    return false;
  }
  Prime& operator= (const Prime &obj) {
    // this->num_ = obj.num_;
    return *this;
  }
private:
  const unsigned int num_;  //素数的属性是常量 
}; 
/**
  * 这是一个统计素数数量的程序
  * 使用了STL的容器/模板技术/函数对象
  */ 
int main() {
  //构造素数对象的集合 
  std::vector<Prime> nums;
  Prime p(2);       //用2构造一个对象 
  nums.push_back(p); //把对象放入集合。   问：上下2个对象是同一个对象吗？ 
  // delete p;  // 我怎么通知nums，对象被干掉了？ 
  //遍历素数对象集合，统计素数数量并输出 
  int count = 0;
  for (std::vector<Prime>::iterator it = nums.begin(); it != nums.end(); ++it) {
    if (it->isPrime())  //判断对象是否为素数 。   it对象“等价”p对象 
      count += 1;
  }
  std::cout << "How many : " << count << std::endl;
  return 0;
} 
