#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "utility.h"					// 实用程序软件包
#include "node.h"						// 结点类模板

// 线性链表类模板
template <class ElemType>
class LinkList 
{
protected:
//  链表实现的数据成员:
	Node<ElemType> *head;				// 头结点指针
	mutable int curPosition;			// 当前位置的序号
	mutable Node<ElemType> * curPtr;	// 指向当前位置的指针
	int count;							// 元素个数

// 辅助函数模板:
	Node<ElemType> *GetElemPtr(int position) const;	// 返回指向第position个结点的指针
	void Init();						// 初始化线性表

public:
//  抽象数据类型方法声明及重载编译系统默认方法声明:
	LinkList();							// 无参数的构造函数模板
	virtual ~LinkList();				// 析构函数模板
	int Length() const;				    // 求线性表长度			 
	bool Empty() const;					// 判断线性表是否为空
	void Clear();						// 将线性表清空
	void Traverse(void (*visit)(const ElemType &)) const;	// 遍历线性表
	int GetCurPosition() const;								// 返回当前位置
	StatusCode GetElem(int position, ElemType &e) const;	// 求指定位置的元素	
	StatusCode SetElem(int position, const ElemType &e);	// 设置指定位置的元素值
	StatusCode Delete(int position, ElemType &e);			// 删除元素		
	StatusCode Insert(int position, const ElemType &e);	// 插入元素
	LinkList(const LinkList<ElemType> &copy); // 复制构造函数模板
	LinkList<ElemType> &operator =(const LinkList<ElemType> &copy); // 重载赋值运算符
};


// 链表类模板的实现部分

template<class ElemType>
Node<ElemType> *LinkList<ElemType>::GetElemPtr(int position) const
// 操作结果：返回指向第position个结点的指针
{
	if (curPosition > position)
	{	// 当前位置在所查找位置之后,只能从表头开始操作
		curPosition = 0;
		curPtr = head;
	}

	for (; curPosition < position; curPosition++)
		curPtr = curPtr->next;			// 查找位置position

	return curPtr;
}

template <class ElemType>
void LinkList<ElemType>::Init()
// 操作结果：初始化线性表
{
	head = new Node<ElemType>;		// 构造头指针
	curPtr = head;	curPosition = 0;// 初始化当前位置
	count = 0;						// 初始化元素个数
}

template <class ElemType>
LinkList<ElemType>::LinkList()
// 操作结果：构造一个空链表
{
	Init();
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
// 操作结果：销毁线性表
{
	Clear();			// 清空线性表
	delete head;		// 释放头结点所指空间
}

template <class ElemType>
int LinkList<ElemType>::Length() const
// 操作结果：返回线性表元素个数
{
	return count;
}

template <class ElemType>
bool LinkList<ElemType>::Empty() const
// 操作结果：如线性表为空，则返回true，否则返回false
{
	return head->next == NULL;
}

template <class ElemType>
void LinkList<ElemType>::Clear()
// 操作结果：清空线性表
{

	ElemType tmpElem;	// 临时元素值
	while (Length() > 0)
	{	// 表性表非空，则删除第1个元素
		Delete(1, tmpElem);
	}
}

template <class ElemType>
void LinkList<ElemType>::Traverse(void (*visit)(const ElemType &)) const 
// 操作结果：依次对线性表的每个元素调用函数(*visit)
{
	for (Node<ElemType> *tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
	{	// 用tmpPtr依次指向每个元素
		(*visit)(tmpPtr->data);	// 对线性表的每个元素调用函数(*visit)
	}
}

template <class ElemType>
int LinkList<ElemType>::GetCurPosition() const
// 操作结果：返回当前位置
{
	return curPosition;
}

template <class ElemType>
StatusCode LinkList<ElemType>::GetElem(int position, ElemType &e) const
// 操作结果：当线性表存在第position个元素时，用e返回其值，返回ENTRY_FOUND,
//	否则返回NOT_PRESENT
{
	if (position < 1 || position > Length())
	{	// position范围错
		return NOT_PRESENT;				// 元素不存在
	}
	else
	{	// position合法
		Node<ElemType> *tmpPtr;
		tmpPtr = GetElemPtr(position);	// 取出指向第position个结点的指针	
		e = tmpPtr->data;				// 用e返回第position个元素的值
		return ENTRY_FOUND;
	}
}

template <class ElemType>
StatusCode LinkList<ElemType>::SetElem(int position, const ElemType &e)
// 操作结果：将线性表的第position个位置的元素赋值为e,
//	position的取值范围为1≤position≤Length(),
//	position合法时返回SUCCESS,否则返回RANGE_ERROR
{
	if (position < 1 || position > Length())
	{	// position范围错
		return RANGE_ERROR;
	}
	else
	{	// position合法
		Node<ElemType> *tmpPtr;
		tmpPtr = GetElemPtr(position);	// 取出指向第position个结点的指针
		tmpPtr->data = e;				// 设置第position个元素的值
		return SUCCESS;
	}
}

template <class ElemType>
StatusCode LinkList<ElemType>::Delete(int position, ElemType &e)
// 操作结果：删除线性表的第position个位置的元素, 并用e返回其值,
//	position的取值范围为1≤position≤Length(),
//	position合法时返回SUCCESS,否则返回RANGE_ERROR
{
	if (position < 1 || position > Length())
	{	// position范围错
		return RANGE_ERROR;
	}
	else
	{	// position合法
		Node<ElemType> *tmpPtr;
		tmpPtr = GetElemPtr(position - 1);		// 取出指向第position-1个结点的指针
		Node<ElemType> *nextPtr = tmpPtr->next;	// nextPtr为tmpPtr的后继
		tmpPtr->next = nextPtr->next;			// 删除结点
		e = nextPtr->data;						// 用e返回被删结点元素值	
		if (position == Length())
		{	// 删除尾结点,当前结点变为头结点
			curPosition = 0;					// 设置当前位置的序号
			curPtr = head;						// 设置指向当前位置的指针
		}
		else
		{	// 删除非尾结点,当前结点变为第position个结点
			curPosition = position;				// 设置当前位置的序号
			curPtr = tmpPtr->next;				// 设置指向当前位置的指针
		}
		count--;								// 删除成功后元素个数减1 
		delete nextPtr;							// 释放被删结点
		return SUCCESS;
	}
}

template <class ElemType>
StatusCode LinkList<ElemType>::Insert(int position, const ElemType &e)
// 操作结果：在线性表的第position个位置前插入元素e
//	position的取值范围为1≤position≤Length()+1
//	position合法时返回SUCCESS, 否则返回RANGE_ERROR
{
	if (position < 1 || position > Length() + 1)
	{	// position范围错
		return RANGE_ERROR; // 位置不合法
	}
	else
	{	// position合法
		Node<ElemType> *tmpPtr;
		tmpPtr = GetElemPtr(position - 1);	// 取出指向第position-1个结点的指针
		Node<ElemType> *newPtr;
		newPtr = new Node<ElemType>(e, tmpPtr->next);// 生成新结点
		tmpPtr->next = newPtr;				// 将tmpPtr插入到链表中
		curPosition = position;				// 设置当前位置的序号
		curPtr = newPtr;					// 设置指向当前位置的指针
		count++;							// 插入成功后元素个数加1 
		return SUCCESS;
	}
}

template <class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &copy)
// 操作结果：由线性表copy构造新线性表——复制构造函数模板
{
	int copyLength = copy.Length();		// copy的长度
	ElemType e;
	Init();								// 初始化线性表

	for (int curPosition = 1; curPosition <= copyLength; curPosition++)
	{	// 复制数据元素
		copy.GetElem(curPosition, e);	// 取出第curPosition个元素
		Insert(Length() + 1, e);		// 将e插入到当前线性表
	}
}

template <class ElemType>
LinkList<ElemType> &LinkList<ElemType>::operator =(const LinkList<ElemType> &copy)
// 操作结果：将线性表copy赋值给当前线性表——重载赋值运算符
{
	if (&copy != this)
	{
		int copyLength = copy.Length();		// copy的长度
		ElemType e;
		Clear();							// 清空当前线性表

		for (int curPosition = 1; curPosition <= copyLength; curPosition++)
		{	// 复制数据元素
			copy.GetElem(curPosition, e);	// 取出第curPosition个元素
			Insert(Length() + 1, e);		// 将e插入到当前线性表
		}
	}
	return *this;
}

#endif