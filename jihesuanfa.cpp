#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <functional>
#include <ctime>
#include <iterator>
#include <numeric>
using namespace std;

//set_intersection交集
//set_union并集
//set_difference差集,按照参数放入顺序确定是谁差谁
void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
		v2.push_back(3 + i);
	}
	vector<int> vTarget;
	vTarget.resize(min(v1.size(), v2.size()));
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	
	copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));

}


int main()
{
	test01();
	system("pause");
	return 0;
}

