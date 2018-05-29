#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include"tree.h"
using namespace std;



tree::tree(int size,int *proot) {
	m_ptree = new int[size];
	m_isize = size;
	for (int i = 0; i < size; i++) {
		m_ptree[i] = 0;

	}
	m_ptree[0] = *proot;
}
tree::~tree() {
	m_isize = 0;
	delete[]m_ptree;
	m_ptree = NULL;


}
int *tree::searchnode(int nodeindex) {
	if (nodeindex < 0 || nodeindex >= m_isize) {
	
		return NULL;
	}
	else if (m_ptree[nodeindex] == 0) {
		return NULL;

	}
	else 
	{
		return &m_ptree[nodeindex];
	}

}
bool tree::addnode(int nodeindex, int direction, int *pnode) {//direction 0 left 1 right;
	if (nodeindex < 0 || nodeindex >= m_isize) {

		return false;
	}
	else if (m_ptree[nodeindex] == 0) {
		return false;

	}
	else
	{
		if (direction == 0)
		{
			if ( nodeindex*2+1 >= m_isize) {

				return false;
			}
			else if (m_ptree[nodeindex*2+1] != 0) {
				return false;

			}
			else if(m_ptree[nodeindex * 2 + 1] == 0)
			m_ptree[nodeindex * 2 + 1]=*pnode;

		}
		if (direction == 1) {
			if (nodeindex * 2 + 2 >= m_isize) {

				return false;
			}
			else if (m_ptree[nodeindex * 2 + 2] != 0) {
				return false;

			}
			else if (m_ptree[nodeindex * 2 + 2] == 0)
				m_ptree[nodeindex * 2 + 2] = *pnode;

		}
		return true;
	}
}
bool tree::deletenode(int nodeindex, int *pnode) {
	if (nodeindex < 0 || nodeindex >= m_isize) {

		return NULL;
	}
	else if (m_ptree[nodeindex] == 0) {
		return NULL;

	}
	else
	{
		*pnode = m_ptree[nodeindex];
		m_ptree[nodeindex]=0;
		return true;
	}
}
void tree::treetraverse() {
	for (int i = 0; i < m_isize; i++) {
		cout << m_ptree[i] << " ";
	}
}