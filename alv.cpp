#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int ElementType;
typedef struct ALVNode *Position;
typedef Position ALVTree;
typedef struct ALVNode
{
    ElementType Data;
    ALVTree Left;
    ALVTree Right;
    int height;
} ALVNode;

int max(int a, int b)
{
    return a > b ? a : b;
}

int getHeight(ALVTree p)
{
    return p == nullptr ? 0 : p->height;
}

ALVTree singleRightRotation(ALVTree A)
{
    ALVTree B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    A->height = max(getHeight(A->Left), getHeight(A->Right)) + 1;
    B->height = max(getHeight(B->Left), getHeight(B->Right)) + 1;
    return B;
}

ALVTree singleLeftRotation(ALVTree A)
{
    ALVTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->height = max(getHeight(A->Left), getHeight(A->Right)) + 1;
    B->height = max(getHeight(B->Left), getHeight(B->Right)) + 1;
    return B;
}

ALVTree doubleLeftRightRotation(ALVTree A)
{
    A->Left = singleRightRotation(A->Left);
    return singleLeftRotation(A);
}

ALVTree doubleRightLeftRotation(ALVTree A)
{
    A->Right = singleLeftRotation(A->Right);
    return singleRightRotation(A);
}

ALVTree Insert(ALVTree T, ElementType X)
{
    if (!T)
    {
        T = (ALVTree)malloc(sizeof(struct ALVNode));
        T->height = 0;
        T->Data = X;
        T->Left = NULL;
        T->Right = NULL;
    }
    else if (X > T->Data)
    {
        T->Right = Insert(T->Right, X);
        if ((getHeight(T->Left) - getHeight(T->Right)) == -2)
        {
            if (T->Right->Data < X)
                singleRightRotation(T);
            else
                doubleRightLeftRotation(T);
        }
    }
    else if (X < T->Data)
    {
        T->Left = Insert(T->Left, X);
        if (getHeight(T->Left) - getHeight(T->Right) == 2)
        {
            if (X < T->Left->Data)
                singleLeftRotation(T);
            else
                doubleLeftRightRotation(T);
        }
    }
    T->height = max(getHeight(T->Left), getHeight(T->Right))+1;
    return T;
}
