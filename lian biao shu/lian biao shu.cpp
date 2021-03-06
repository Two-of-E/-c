#include "pch.h"
#include "Tree.h"

using namespace std;

int main()
{
	Tree *tree = new Tree();

	Node *node1 = new Node();
	node1->data = 5;
	node1->index = 1;

	Node *node2 = new Node();
	node2->data = 8;
	node2->index = 2;

	Node *node3 = new Node();
	node3->data = 2;
	node3->index = 3;

	Node *node4 = new Node();
	node4->data = 6;
	node4->index = 4;

	Node *node5 = new Node();
	node5->data = 9;
	node5->index = 5;

	Node *node6 = new Node();
	node6->data = 7;
	node6->index = 6;


	tree->AddNode(0, 0, node1);
	tree->AddNode(0, 1, node2);

	tree->AddNode(1, 0, node3);
	tree->AddNode(1, 1, node4);

	tree->AddNode(2, 0, node5);
	tree->AddNode(2, 1, node6);

	tree->DeleteNode(2, NULL);

	tree->PostorderTraversal();


	delete tree;
	system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
