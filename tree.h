#ifndef TREE_H
#define TREE_H

class tree
{
public:
	tree(int size,int *proot);
	~tree();
	int *searchnode(int nodeindex);
	bool addnode(int nodeindex, int direction, int *pnode);
	bool deletenode(int nodeindex, int *pnode);
	void treetraverse();

private:
	int *m_ptree;
	int m_isize;

};




#endif 
