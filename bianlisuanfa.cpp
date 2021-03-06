#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

void myPrint(int v)
{
	cout << v << endl;

}
struct myPrint02
{
	
	void operator()(int v)
	{
		cout << v << endl;
		m_Count++;
	}
	int m_Count;
};
//1.for_each
void test01()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);

	}
	for_each(v.begin(), v.end(), myPrint);
}
//2.for_each保存内部记录
void test02()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);

	}
	myPrint02 print2 = for_each(v.begin(), v.end(), myPrint02());
	cout << print2.m_Count << endl;

}
//3.for_each可以绑定参数进行输出

struct myPrint03:public binary_function<int,int,void>
{

	void operator()(int v,int start) const
	{
		cout << v+start << endl;
	}
};
void test03()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);

	}
	for_each(v.begin(), v.end(), bind2nd(myPrint03(),10000));
}

//
class TransForm
{
public:
	int operator()(int val)
	{
		return val;
	}
};

void test04()
{
	vector<int> v;//作为元容器
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);

	}
	vector<int> v1;//目标容器
	//为v1开辟内存
	v1.resize(v.size());
	transform(v.begin(), v.end(), v1.begin(), TransForm());

	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " ";});
}
//转移两个容器相加到一个容器上
class TransForm02
{
public:
	int operator()(int val,int val2)
	{
		return val+val2;
	}
};

void test05()
{
	vector<int> v;//作为元容器
	vector<int> v2;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);

	}
	for (int i = 0;i < 10;i++)
	{
		v2.push_back(i+100);

	}
	vector<int> v1;//目标容器
	//为v1开辟内存
	v1.resize(v.size());
	transform(v.begin(), v.end(),v2.begin(), v1.begin(), TransForm02());

	for_each(v1.begin(), v1.end(),[](int val) {cout << val << " ";});
}

int main()
{
	test05();


	system("pause");
	return 0;
}

