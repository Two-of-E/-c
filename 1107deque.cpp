// 1107deque.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

using namespace std;
//回掉函数和仿函数修改排序顺序
//回掉函数，将函数排序设为降序，即前面的数大于后面的数
bool myCompare(int v1, int v2)
{
	return v1 > v2;
}
//仿函数,函数不可以做为类型所以要自定义数据类型
class myCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	string m_Name;
	int m_Age;
};

class myComparePerson
{
public:
	bool operator()(const Person &p1,const Person &p2)
	{
		return  p1.m_Age > p2.m_Age;  
	  }
};

void test05()
{
	set<Person, myComparePerson> s1;

	Person p1("1", 100);
	Person p2("2", 10);
	Person p3("3", 90);
	Person p4("4", 1000);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);

	for (set<Person, myComparePerson>::iterator it = s1.begin();it != s1.end();it++)
	{
		cout << "姓名：" << (*it).m_Name << "年龄" << (*it).m_Age << endl;
	}

}


void test03()
{
	deque<int>d;
	d.push_back(5);
	d.push_back(15);
	d.push_back(2);
	d.push_back(40);
	d.push_back(7);
	sort(d.begin(), d.end(),myCompare);//STL自带排序算法

	


}

int main()
{
	test05();



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
