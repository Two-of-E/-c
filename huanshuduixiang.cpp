#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
//内建函数对象头文件
#include <functional>

using namespace std;

class MyPrint
{
public:
	void operator()(int num)
	{
		cout << "num" << num << endl;
		count++;

	}
	int count = 0;
};
//仿函数，是一个类
void test01()
{
	MyPrint myPrint;
	myPrint(111);
}
//函数对象超出普通函数概念，内部可以保存状态
void test02()
{
	MyPrint myPrint;
	myPrint(111);
	myPrint(111);
	myPrint(111);
	myPrint(111);
	cout << "mPrint使用次数：" << myPrint.count << endl;
}
//函数对象作为参数
void doPrint(MyPrint print, int num)
{
	print(num);
}

void test03()
{
	doPrint(MyPrint(), 20);
}

//谓词
class GreaterThen20
{
public:
	//一元谓词bool类型
	bool operator()(int val)
	{
		return val > 20;
	}
};
void test04()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	//第三个参数函数对象,匿名对象
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen20());
	if (pos != v.end())
	{
		cout << "找到大于20的数字为:  " << *pos << endl;

	}
	else
	{
		cout << "未找到" << endl;
	}

}

void test06()
{
	//取反仿函数
	negate<int> n;
	cout << n(10) << endl;
	//加法
	plus<int> p;
	cout << p(1, 1) << endl;

}
void test07()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	//greater(大于)类型的匿名对象
	sort(v.begin(), v.end(),greater<int>());

	for_each(v.begin(), v.end(), [](int val) {cout << val << "  ";});

}



int main()
{

	test07();
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
