# 8th Week
- OOD：矩阵
  - 方法：加、减、点乘、叉乘
  - 属性：随便
- 动作：学生讲解作业（属于评估）

## Activities
1. 学生讲解矩阵代码
2. 分析矩阵的属性定义：数组，容器，Eigen实现
3. Eigen的继承：Curiously recurring template pattern （CRTP），奇特的递归模板模式
   1. 颠倒继承（Upside Down Inheritance），它的效果与“传统继承是通过派生类向基类添加功能”的应用正好相反的。
   2. 不使用虚函数但是达到了多态的效果，大量应用于各种库中，比如Eigen库，WTL库。它没有虚函数的开销。
4. 展示Eigen中Matrix的数据结构：实际上展示不下去，没法做
5. 实际中看文档，读代码，照样使用Eigen库编程。
6. 通过读源代码，学习一些新技术。