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

## 结果
自我感觉效果好，交互太少，以上内容根本没讲完。CRTP只讲了开头。

# 9th Week

作业：在上周矩阵的基础上，计算欧氏距离，周末再给。

周末忘记给作业，学生说没时间做。

CRTP的多态效果，与标准的多态比较。

Matrix的运算符重载，特别是()的重载。

## Activities
1. 多态的演示代码。优缺点。
2. CRTP的演示代码，实现相同的多态。扩展static_cast
3. Eigen库中CRTP应用。
4. Matrix中的运算符重载。
5. ()的重载

## 结果
课程的内容有点混乱。

# 10th Week

作业：匈牙利算法

本周日补五一的课程，计划有点混乱了。

有个学生跑别的班听基础内容了，好像我讲得内容有点超越学生的认知了。

## Activities
1. Eigen里代码的继承关系与展示，Matrix 和 Array
2. 先找Eigen文档里关于 Matrix 和 Array 的说明
3. 清理 Eigen 的源代码，Copy 出来单独展示与说明
4. 画一个 PlantUML 的简要模型

# 11th Week

多重继承与 Mix in-class 编程