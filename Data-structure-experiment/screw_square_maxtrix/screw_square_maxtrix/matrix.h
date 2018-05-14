#ifndef __MATRIX_H__
#define __MATRIX_H__

// 矩阵类模板
template<class ElemType>
class Matrix
{
protected:
//  矩阵的数据成员:
	ElemType *elems;		// 存储知阵元素
	int rows, cols;			// 矩阵行数和列数

public:
// 抽象数据类型方法声明及重载编译系统默认方法声明:
	Matrix(int rs, int cs);	// 构造一个rs行cs列的矩阵
	~Matrix();				// 析构函数模板
	int GetRows() const;	// 返回矩阵行数
	int GetCols() const;	// 返回矩阵列数
	ElemType &operator()(int i, int j);			// 重载函数运算符
	Matrix(const Matrix<ElemType> &copy);		// 复制构造函数模板
	Matrix<ElemType> &operator =(const Matrix<ElemType> &copy); // 重载赋值运算符
};

// 三对角类模板的实现部分
template <class ElemType>
Matrix<ElemType>::Matrix(int rs, int cs)
// 操作结果：构造一个rs行cs列的矩阵
{
	if (rs < 1 && cs < 1)	
		throw Error("行数或列数无效!");	// 抛出异常
	rows = rs;				// rs为行数
	cols = cs;				// cs为列数
	elems = new ElemType[rows * cols];	// 分配存储空间
}

template <class ElemType>
Matrix<ElemType>::~Matrix()
// 操作结果：释放矩阵所占用空间
{
	if (elems != NULL) delete []elems; 
}

template <class ElemType>
int Matrix<ElemType>::GetRows() const
// 操作结果：返回矩阵行数
{
	return rows;
}

template <class ElemType>
int Matrix<ElemType>::GetCols() const
// 操作结果：返回矩阵列数
{
	return cols;
}

template <class ElemType>
ElemType &Matrix<ElemType>::operator()(int i, int j)
// 操作结果：重载函数运算符
{
	if (i < 1 || i > rows || j < 1 || j > cols)	
		throw Error("下标出界!");			// 抛出异常
	return elems[(i - 1) * cols + j - 1];	// 返回元素
}

template <class ElemType>
Matrix<ElemType>::Matrix(const Matrix<ElemType> &copy)
// 操作结果：由矩阵copy构造新矩阵——复制构造函数模板
{
	rows = copy.rows;		// 复制行数
	cols = copy.cols;		// 复制列数
	elems = new ElemType[rows * cols];	// 为数据元素分配存储空间
	for (int i = 0; i < rows * cols; i++)
	{	// 复制数据元素值
		elems[i] = copy.elems[i];
	}
}

template <class ElemType>
Matrix<ElemType> &Matrix<ElemType>::operator =(const Matrix<ElemType> &copy)
// 操作结果：将矩阵copy赋值给当前矩阵——重载赋值运算符
{
	if (&copy != this)
	{
		if (elems != NULL) delete []elems;	// 释放数据元素空间

		rows = copy.rows;		// 复制行数
		cols = copy.cols;		// 复制列数
		elems = new ElemType[rows * cols];	// 为数据元素分配存储空间
		for (int i = 0; i < rows * cols; i++)
		{	// 复制数据元素值
			elems[i] = copy.elems[i];
		}
	}
	return *this;
}

#endif