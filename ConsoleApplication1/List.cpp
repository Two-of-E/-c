#include "pch.h"
#include "List.h"
using namespace std;

List::List()
{
	m_pList = new Node;
	//m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;
}


List::~List()
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

void List::ClearList()
{
	Node *currnetNode = m_pList->next;
	while (currnetNode != NULL)
	{
		Node *temp = currnetNode->next;
		delete currnetNode;
		currnetNode = temp;

    }
	m_pList->next = NULL;
	
}
bool List::listEmpty()
{
	if (m_iLength == 0)
		return  true;
	else
		return false;
}
int List::ListLength()
{
	return m_iLength;
}
// �ҵ���i���ڵ㣬�����������ݿ�����pNode�
bool List::GetElem(int i, Node *pNode)
{
	if (i < 0 || i >= m_iLength)
	{
		return false;
	}

	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	for (int k = 0;k <= i;k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;

}
//�鿴�ڵ�����pNode����������ͬ�Ľڵ㣬����У����ڵ��λ�򷵻س���
int List::LocateElem(Node *pNode)
{
	Node *currentNode = m_pList;
	int count = 0;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		if (currentNode->data == pNode->data)
		{
			return count;
		}
		count++;
	}

	return -1;

}
//�ҵ�����ڵ��ǰ��
bool List::PrioElem(Node *pCurrentNode, Node *pPreNode)
{
	Node *currentNode = m_pList;
	Node *tempNode = NULL;

	while (currentNode->next != NULL)
	{
		tempNode = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data)
		{
			if (tempNode == m_pList)
			{
				return false;
			}
			pPreNode->data = tempNode->data;
			return true;
		}

	}
	return false;
}
//�ҵ�����ڵ�ĺ���
bool List::NextElem(Node *pCurrentNode, Node *pNextNode)
{
	Node *currentNode = m_pList;
	

	while (currentNode->next != NULL)
	{
		
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data)
		{
			if (currentNode->next == m_pList)
			{
				return false;
			}
			pNextNode->data = currentNode->next->data;
			return true;
		}

	}
	return false;
}
//��������,��������ӡ����

void List::ListTraverse()
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}
//�ڵ�i���ڵ�������ڵ㡣
bool List::ListInsert(int i, Node *pNode)
{
	if (i<0 || i>m_iLength)
	{
		return false;
	}
	Node *currentNode = m_pList;
	for (int k = 0;k < i;k++)
	{
		currentNode = currentNode->next;

	}
	Node *newNode = new Node;
	if (newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	return true;
}
//ɾ����i���ڵ�
bool List::ListDelete(int i, Node *pNode)
{
	if (i < 0 || i >= m_iLength)
	{
		return false;
	}

	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	for (int k = 0;k <= i;k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	currentNodeBefore->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;
	return true;

}
bool List::ListInsertHead(Node *pNode)
{
	Node *temp = m_pList->next;
	Node *newNode = new Node;
	if (newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;

	return true;
}
bool List::ListInsertTail(Node *pNode)
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}

	Node *newNode = new Node;
	if (newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = NULL;

	currentNode->next = newNode;
	m_iLength++;
	return true;
}
