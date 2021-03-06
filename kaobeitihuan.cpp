#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <functional>
#include <ctime>
#include <iterator>
using namespace std;

//copy
void test01()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	vector<int> vTarget;
	vTarget.resize(v.size());
	
	copy(v.begin(), v.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " ";});

}

class MyCompare
{
public:
	bool operator()(int v)
	{
		return v > 3;
	}
};
//replace
void test02()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	//需求把3替换成300
	replace(v.begin(), v.end(), 3, 300);
	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});
	cout << endl;
	replace_if(v.begin(),v.end(), MyCompare(),300);
	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});
}

//swap交换
void test03()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	vector<int>v2;
	v2.push_back(200);
	v2.push_back(300);
	v2.push_back(400);
	v2.push_back(500);
	swap(v,v2);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ""));
}

int main()
{
	test03();
	system("pause");
	return 0;
}

