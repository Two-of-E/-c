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
// 找到第i个节点，并将结点的内容拷贝到pNode里。
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
//查看节点中与pNode的数据域相同的节点，如果有，将节点的位序返回出来
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
//找到所需节点的前驱
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
//找到所需节点的后驱
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
//遍历函数,将函数打印出来

void List::ListTraverse()
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}
//在第i个节点后面插入节点。
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
//删除第i个节点
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
