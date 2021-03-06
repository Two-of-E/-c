#include "pch.h"

using namespace std;
//迭代器,遍历
//普通数组
void test01()
{
	int array[5] = { 1,3,5,6,7 };

	int *p = array;
	for (int i = 0;i < 5;i++)
	{
		cout << *(p + i) << endl;
	}
}

void myPrint(int v)
{
	cout << v << endl;
}

//vector
void test02()
{
	vector <int> v;//声明容器

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	//遍历容器中的数据

	/*vector<int>::iterator itBegin = v.begin();//指向容器的起始位置

	vector<int>::iterator itEnd = v.end();//指向容器最后一个位置的下个位置

	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}*/
	//for (int i = 0;i < 10;i++)
	
	/*for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << endl;
	}*/

	for_each(v.begin(), v.end(), myPrint);

}
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;

};

void test03()
{
	vector<Person> v;
	Person p1("大头儿子", 10);
	Person p2("小头爸爸", 32);
	Person p3("隔壁王叔", 30);
	Person p4("围裙妈妈", 28);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		cout << it->m_Name << "   " << it->m_Age << endl;

	}
}
//存放自定义数据类型的指针
//it指针的指针
void test04()
{
	vector<Person*> v;
	Person p1("大头儿子", 10);
	Person p2("小头爸爸", 32);
	Person p3("隔壁王叔", 30);
	Person p4("围裙妈妈", 28);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	for (vector<Person*>::iterator it = v.begin();it != v.end();it++)
	{
		cout << (*it)->m_Name << "   " << (*it)->m_Age << endl;

	}
}



int main() 
{
	//test01();
	test03();


	system("pause");
	return 0;
}




