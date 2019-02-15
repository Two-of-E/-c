#pragma once
class Node
{
public:
	Node();
	virtual ~Node();
	Node *SearchNdoe(int nodeIndex);
	void DeleteNode();
	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();
	
	int index;
	int data;

	Node *pLChild;
	Node *pRChild;
	Node *pParent;

};

