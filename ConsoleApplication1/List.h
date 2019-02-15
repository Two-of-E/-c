#pragma once

#include "Node.h"
class List
{
public:
	List();
	virtual ~List();
	void ClearList();
	bool listEmpty();
	int ListLength();
	bool GetElem(int i,Node *pNode);
	int LocateElem(Node *pNode);
	bool PrioElem(Node *pCurrentNode, Node *pPreNode);
	bool NextElem(Node *pCurrentNode, Node *pNextNode);
	void ListTraverse();
	bool ListInsert(int i, Node *pNode);
	bool ListDelete(int i, Node *pNode);
	bool ListInsertHead(Node *pNode);
	bool ListInsertTail(Node *pNode);


private:
	Node *m_pList;
    int m_iLength;

};

