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
//Ѱ�ҽ��,ͨ������Node��ĺ���
//param:   nodeIndex �������λ�õı��
Node *Tree::SearchNdoe(int nodeIndex)
{
	return m_pRoot->SearchNdoe(nodeIndex);
}

/*
���ã���ӽ��
����:	nodeIndex	������
		direction	���ҷ��� 0��1��
		*pNode		Ҫ��ӵĽڵ�
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
����:	ɾ�����
����:	nodeIndex	������
		
		*pNode		ɾ���Ľڵ�
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
//ǰ�����
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


