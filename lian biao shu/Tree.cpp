#include "pch.h"
#include "Tree.h"


Tree::Tree()
{
	m_pRoot = new Node();
}


Tree::~Tree()
{
	//DeleteNode(0, NULL);
	m_pRoot->DeleteNode();
}
//寻找结点,通过调用Node里的函数
//param:   nodeIndex 结点所在位置的编号
Node *Tree::SearchNdoe(int nodeIndex)
{
	return m_pRoot->SearchNdoe(nodeIndex);
}

/*
作用：添加结点
参数:	nodeIndex	结点序号
		direction	左右方向 0左1右
		*pNode		要添加的节点
*/
bool Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
	Node *temp = SearchNdoe(nodeIndex);
	if (temp == NULL)
	{
		return false;
	}

	Node *node = new Node();
	if (node == NULL)
	{
		return false;
	}
	node->index = pNode->index;
	node->data = pNode->data;
	node->pParent = temp;

	if (direction == 0)
	{
		temp->pLChild = node;
	}
	if (direction == 1)
	{
		temp->pRChild = node;
	}
	
	return true;
}
/*
作用:	删除结点
参数:	nodeIndex	结点序号
		
		*pNode		删除的节点
*/
bool Tree::DeleteNode(int nodeIndex, Node *pNode)
{
	Node *temp = SearchNdoe(nodeIndex);
	if (temp == NULL)
	{
		return false;
	}
	if (pNode != NULL)
	{
		pNode->data = temp->data;
	}

	temp->DeleteNode();
	return true;
}
//前序遍历
void Tree::PreorderTraversal()
{
	m_pRoot->PreorderTraversal();
}

void Tree::InorderTraversal()
{
	m_pRoot->InorderTraversal();
}

void Tree::PostorderTraversal()
{
	m_pRoot->PostorderTraversal();
}


