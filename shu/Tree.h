#pragma once
class Tree
{
public:
	Tree(int size,int *pRoot);
	virtual ~Tree();

	int *SearchNode(int nodeIndex); 
	bool AddNode(int nodeIndex, int direction, int *pNode);
	bool DeletNode(int nodeIndex, int *pNode);
	void TreeTraverse();
private:
	int *m_pTree;
	int m_iSize;
};

