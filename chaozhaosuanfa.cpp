#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <functional>
using namespace std;
//find算法进行查找
void test01()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos != v.end())
	{
		cout << "找到了数据： " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;

	}
	bool operator == (const Person&p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}
	string m_Name;
	int m_Age;
};

//利用find查找自定义数据类型
void test02()
{
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator pos = find(v.begin(), v.end(), p2);

	if (pos != v.end())
	{
		cout << "找到了名字： " << (*pos).m_Name << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

}

class Mycompare:public binary_function<Person*,Person*,bool>
{
public:
	bool operator()(Person * p1,Person * p2) const
	{
		if (p1->m_Name == p2->m_Name && p1->m_Age == p2->m_Age)
		{
			return true;
		}
		return false;
	}
};

void test03()
{
	vector<Person *> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	Person * p = new Person("bbb", 20);
	vector<Person*>::iterator pos = find_if(v.begin(), v.end(), bind2nd(Mycompare(),p));
	if (pos != v.end())
	{
		cout << "找到了名字： " << (**pos).m_Name << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

//adjacent_find查找相邻相同元素
void test04()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	v.push_back(9);
	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos != v.end())
	{
		cout << "zhaodao"<< endl;
	}
	else
	{
		cout << "wei" << endl;
	}
}
//binary_serch 二分查找法，在无序序列中不可用
void test05()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 4);
	if (ret)
	{
		cout << "找到" << endl;

	}
	else {
		cout << "没找到" << endl;
	}
}

class GreaterThenFour
{
public:
	bool operator()(int v)
	{
		return v >= 4;
	}
};

//count 统计元素出现的次数
void test06()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);

	int num = count(v.begin(), v.end(), 4);
	cout << num << endl;

	int sum = count_if(v.begin(), v.end(), GreaterThenFour());
	cout << sum << endl;

}

int main()
{
	test06();


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
