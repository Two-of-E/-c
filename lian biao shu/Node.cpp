#include "pch.h"
#include "Node.h"
using namespace std;

Node::Node()
{
	index = 0;
	data = 0;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
}


Node::~Node()
{
}

Node *Node::SearchNdoe(int nodeIndex)
{
	if (this->index == nodeIndex)
	{
		return this;

	}
	Node *temp = NULL;
	if (this->pLChild != NULL)
	{
		if (this->pLChild->index == nodeIndex)
		{
			return this->pLChild;
		}
		else
		{
			temp = this->pLChild->SearchNdoe(nodeIndex);
			if (temp != NULL)
			{
				return temp;
			}
		}
	}
	if (this->pRChild != NULL)
	{
		if (this->pRChild->index == nodeIndex)
		{
			return this->pRChild;
		}
		else
		{
			temp = this->pRChild->SearchNdoe(nodeIndex);
			if (temp != NULL)
			{
				return temp;
			}
		}
	}
	return NULL;
}
void Node::DeleteNode()
{
	//��������˵ݹ飬�������������ӽ��ֱ�����н�㶼ָ��NULLΪֹ
	if (this->pLChild != NULL)
	{
		this->pLChild->DeleteNode();
	}
	if (this->pRChild != NULL)
	{
		this->pRChild->DeleteNode();
	}
	if (this->pParent != NULL)
	{
		if (this->pParent->pLChild == this)
		{
			this->pParent->pLChild = NULL;
		}
		if (this->pParent->pRChild == this)
		{
			this->pParent->pRChild = NULL;
		}
	}

	delete this;
}
//ǰ�����
//����thisָ����еݹ�
void Node::PreorderTraversal()
{
	cout << this->index << "  " << this->data << endl;
	if (this->pLChild != NULL)
	{
		this->pLChild->PreorderTraversal();
	}
	if (this->pRChild != NULL)
	{
		this->pRChild->PreorderTraversal();
	}
}
//����
void Node::InorderTraversal()
{
	
	if (this->pLChild != NULL)
	{
		this->pLChild->InorderTraversal();
	}
	cout << this->index << "  " << this->data << endl;
	if (this->pRChild != NULL)
	{
		this->pRChild->InorderTraversal();
	}
}
//����
void Node::PostorderTraversal()
{
	if (this->pLChild != NULL)
	{
		this->pLChild->PostorderTraversal();
	}
	
	if (this->pRChild != NULL)
	{
		this->pRChild->PostorderTraversal();
	}
	cout << this->index << "  " << this->data << endl;

}
