#include "pch.h"
#include "List.h"
using namespace std;
int main()
{
	Node node1;
	node1.data.name = "tester1";
	node1.data.phone = "123456";

	Node node2;
	node2.data.name = "tester2";
	node2.data.phone = "234567";

	List *pList = new List();

	pList->ListInsertTail(&node1);
	pList->ListInsertTail(&node2);



	Node temp;

	pList->ListTraverse();
	 
	delete pList;
	pList = NULL;

	system("pause");
	return 0;
}

