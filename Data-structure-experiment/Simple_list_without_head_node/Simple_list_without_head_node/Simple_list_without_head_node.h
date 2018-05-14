#ifndef __SIMPLE_LIST_WITHOUT_HEAD_NODE_H__
#define __SIMPLE_LIST_WITHOUT_HEAD_NODE_H__


#include"node.h"

//定义无头结点的简单线性链表类

template<class ElemType>
class NOHEAD
{
public:
	NOHEAD();//无参数构造函数
	virtual~NOHEAD();//析构函数
	int Length() const;//求线性表的长度
	bool Empty() const;//判断线性表是否为空
	void Clear();//将线性表清空
	void Traverse(void(*Visit)(ElemType&));//遍历线性表
	StatusCode GetElem(int position, ElemType&e) const;//求指定位置元素
	StatusCode SetElem(int position, const ElemType&e);//设置指定位置的元素值
	StatusCode Delete(int position, ElemType&e);//删除元素
	StatusCode Insert(int position, const ElemType&e);//插入元素

private:
	Node<ElemType>*first;//指向首元素结构的指针
	Node<ElemType>*GetElemptr(int position) const;//返回第position个节点的指针
	void Init(); //初始化该线性表
};

template<class ElemType>
Node<ElemType>*NOHEAD<ElemType>::GetElemptr(int position) const
{
	Node<ElemType>* pt=first;
	int curposition = 1;//pt所指结点的位置
	while (pt != NULL && curposition < position)
	{	pt = pt->next;
		curposition++;
	}

	if (pt != NULL && curposition == position)
	{
		return pt;
	}

	else
	{
		retuen NULL;
	}

}
template<class ElemType>
void NOHEAD<ElemType>::Init()
{
	first = NULL;
}



template<class ElemType>
NOHEAD<ElemType>::~NOHEAD()
{
	Clear();
}


template<class ElemType>
int NOHEAD<ElemType>::Length()const
{
	int count = 0;//初始化统计元素个数
	for (Node<ElemType>*pt = first; pt != NULL; pt = pt->next)//对线性表的每个元素进行计数
	{
		count++;
	}
	return count;
}

template<class ElemType>
void NOHEAD<ElemType>::Clear()
{
	ElemType a;
	while (Length()>0)
	{
		Delete(1,a)
	}
}

template<class ElemType>
void NOHEAD<ElemType>::Traverse(void(*Visit)(ElemType &))
{
	for (Node<ElemType>*pt = first; pt != NULL; pt = pt->next)
	{
		(*Visit)(pt->data);
	}
}
template<class ElemType>
StatusCode NOHEAD<ElemType>::GetElem(int position, ElemType&e) const
{
	if (position<1 || position>Length())
	{
		return RANGE_ERROR;
	}
	else
	{
		Node<ElemType>*pt;
		pt = GetElemptr(position);
		e = pt->date;
		return ENTRY_FOUND;
	}
}

template<class ElemType>
StatusCode NOHEAD<ElemType>::SetElem(int position, const ElemType&e)
{
	if (position<1 || position>Length())
	{
		return RANGE_ERROR;
	}
	else
	{

		Node<ElemType>*pt;
		pt = GetElemptr(position);
		pt->date = e;
		return ENTRY_FOUND;
	}

}

template<class ElemType>
StatusCode NOHEAD<ElemType>::Delete(int position, ElemType&e)
{
	if (position<1 || position>Length())
	{
		return RANGE_ERROR;
	}
	else
	{

		Node<ElemType>*pt;
		if (position > 1)//删除非第1个元素
		{
			pt = GetElemptr(position - 1);
			Node<ElemType>*pm = pt->next;
			pt->next = pm->next;
			e = pm->data;
			delete pm;
		}

		else//删除第1个元素
		{
			pt = first;//暂存first
			first = first->next;//first指向后继
			delete pt;
		}

		return SUCCESS;
	}
}

template<class ElemType>
StatusCode NOHEAD<ElemType>::Insert(int position,const ElemType&e)
{
	if (position<1 || position>Length())
	{
		return RANGE_ERROR;
	}
	else
	{

		Node<ElemType>*pm;//指向被插入结点
		if (position > 1）//插入元素不是第1个元素
		{
			Node<ElemType>*pt = GetElemptr(position - 1);
			pt = GetElemptr(position - 1);
			pm =new Node<ElemType>(e,pt->next);
			pt->next = pm;
		}

		else//插入元素是第1个元素
		{
			pm = new Node<ElemType>(e,first);//生成新结点
			first = pm;//pm是新的第1个元素的结点
			delete pt;
		}

		return SUCCESS;
	}
}

template<class ElemType>
NOHEAD<ElemType>::NOHEAD
{
	Init();
}





#endif
