#pragma once
#include "Person.h"
class Node
{
public:
	Node();
	virtual ~Node();

	Person data;
	Node *next;
	void printNode();

};

