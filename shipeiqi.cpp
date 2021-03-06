#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

class MyPrint:public binary_function<int,int,void>
{
public:
	void operator()(int v, int start) const
	{
		cout << v + start << endl;// 
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);

	}
	cout << "请输入num" << endl;
	int num;
	cin >> num;
	//适配器 
	for_each(v.begin(), v.end(), bind2nd(MyPrint(), num));//bind2nd(MyPrint(),num)
}

class GreaterThenFive:public unary_function<int,bool>
{
public:
	bool operator()(int v) const
	{
		return v>5;
	}
};

//取反适配器
void test02()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator pos = find_if(v.begin(), v.end(),not1( GreaterThenFive()));
	//vector<int>::iterator pos = find_if(v.begin(), v.end(),not1(bind2nd(greater<int>(),5)));
	if (pos != v.end())
	{
		cout << "找到小于5的数字为" << *pos;
	}
	else
	{
		cout << "未找到" << endl;
	}
}
//函数指针适配器
void MyPrint03(int v,int star)
{
	cout << v+ star << " ";
}
void test03()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	//将函数指针适配为函数对象
	for_each(v.begin(), v.end(),bind2nd(ptr_fun(MyPrint03),100));
}
//成员函数适配器
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	void showPerson()
	{
		cout << "姓名" <<m_Name << "年龄" <<m_Age << endl;
	}
	void plusAge()
	{
		this->m_Age += 100;
	}
	string m_Name;
	int m_Age;
};
//回掉函数
void MyPrintPerson(Person &p)
{
	cout << "姓名" << p.m_Name << "年龄" << p.m_Age << endl;
}
void test04()
{
	vector<Person> v;

	Person p1("aaa", 10);
	Person p2("bbb", 15);
	Person p3("ccc", 20);
	Person p4("ddd", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//for_each(v.begin(), v.end(), MyPrintPerson);
	//成员函数适配器
	for_each(v.begin(), v.end(),mem_fun_ref(&Person::showPerson));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::plusAge));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));

}

int main()
{
	test04();

	system("pause");
	return 0;
    //std::cout << "Hello World!\n"; 
}


