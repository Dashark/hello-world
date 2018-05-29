#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<stdio.h>
#include"tree.h"
using namespace std;


//数组实现 用零代表无子节点


/*int tree[n] 3 5 8 2 6 7 9

		3[0]
	5[1]	8[2]
2[3]	6[4]	9[5]	7[6]
*/

int main() {
	int root = 3;
	tree *ptree = new tree(10,&root);
	int node1 = 5;
	int node2 = 8;
	int node3 = 2;
	int node4 = 6;

	ptree->addnode(0, 0, &node1);
	ptree->addnode(0, 1, &node2);
	ptree->addnode(1, 0, &node3);
	ptree->addnode(1, 1, &node4);
	
	int node5 = 9;
	int node6 = 7;

	ptree->addnode(2, 0, &node5);
	ptree->addnode(2, 1, &node6);
	int node = 0;
	//ptree->deletenode(6, &node);
	cout << endl;
	cout << node << endl;
	ptree->treetraverse();
	int *p=ptree->searchnode(2);
	cout << endl;
	cout << *p << endl;
	delete ptree;
	
	getchar();
	return 0;
}