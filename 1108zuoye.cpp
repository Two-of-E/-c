#include "pch.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

enum{RENLI,YANFA,MEISHU};

class Worker
{
public:
	string m_Name;
	int m_Money;
};

void creatWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0;i < 5;i++){
		string name = "员工";
		name += nameSeed[i];

		int money = rand() % 10000 + 10000;

		Worker w;
		w.m_Money = money;
		w.m_Name = name;

		v.push_back(w);
	}
}

void setGroup(vector<Worker>&v,multimap<int,Worker>&m) 
{
	for (vector<Worker>::iterator it = v.begin();it != v.end();it++) 
	{
		int depertmentId = rand() % 3;
		m.insert(make_pair(depertmentId, *it));
	}

}

void showGroup(multimap<int, Worker> m)
{
	cout << "人力部门员工如下：  " << endl;
	multimap<int,Worker>::iterator pos = m.find(RENLI);
	int index = 0;
	int num = m.count(RENLI);
	for (;pos != m.end(), index < num;pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "工资:" << pos->second.m_Money << endl;

	}
	cout << "---------------------" << endl;

	cout << "研发部门员工如下：  " << endl;
	pos = m.find(YANFA);
	index = 0;
	num = m.count(YANFA);
	for (;pos != m.end(), index < num;pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "工资:" << pos->second.m_Money << endl;

	}
	cout << "---------------------" << endl;

	cout << "美术部门员工如下：  " << endl;
	pos = m.find(MEISHU);
	index = 0;
	num = m.count(MEISHU);
	for (;pos != m.end(), index < num;pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "工资:" << pos->second.m_Money << endl;

	}
	cout << "---------------------" << endl;

}
int main()
{
	srand((unsigned int)time(NULL));

	vector<Worker> v;

	creatWorker(v);

	//设置分组
	multimap<int, Worker>m;
	setGroup(v,m);
	
	showGroup(m);

	//for (vector<Worker>::iterator it = v.begin();it != v.end();it++)
	//{
	//	cout << "姓名：  " << it->m_Name << "工资：  " << it->m_Money << endl;

	//}



	system("pause");
	return 0;
}
