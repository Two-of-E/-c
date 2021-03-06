#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <functional>
#include <ctime>
using namespace std;
//merge算法容器元素合并，并储存到另一个容器中，两个容器必须同为降序或是升序

void test01()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);

	}

	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), [](int v) {cout << v << "  ";});

}

//sort
void test02()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	v.push_back(1);

	sort(v.begin(), v.end());

	for_each(v.begin(), v.end(), [](int v) {cout << v << "  ";});
	cout << endl;

	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int v) {cout << v << "  ";});
	cout << endl;

}
//random_shuffle()洗牌算法

void test03()
{
	vector<int>v2;
	for (int i = 0;i < 10;i++)
	{
	v2.push_back(i + 1);
	}

	random_shuffle(v2.begin(), v2.end());
	for_each(v2.begin(), v2.end(), [](int val) {cout << val << "  ";});
}
//reverse 反转函数
void test04()
{
	vector<int>v2;
	for (int i = 0;i < 10;i++)
	{
		v2.push_back(i + 1);
	}
	reverse(v2.begin(), v2.end());
	for_each(v2.begin(), v2.end(), [](int val) {cout << val << "  ";});
}

int main()
{
	srand((unsigned int)time(NULL));

	test04();
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
