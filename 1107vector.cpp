#include "pch.h"
using namespace std;



void text01()
{
	vector<int> v;
	for (int i = 0;i < 10;i++){

		v.push_back(i);
		cout << v.capacity() << endl;
	}
}
//巧用swap,节省vector的内存
void text03()
{
	vector<int> v;
	for (int i = 0;i < 100000;i++)
	{
		v.push_back(i);
	}
	v.resize(3);
	cout << "v的容量" << v.capacity() << endl;
	cout << "V的大小" << v.size() << endl;
	/*伪代码
	x = vector<int>(v)//利用初始化匿名对象（不用管匿名对象内存的释放）
	swap(x,v)
	*/
	vector<int>(v).swap(v);
	cout << "v的容量" << v.capacity() << endl;
	cout << "V的大小" << v.size() << endl;


}
//用num看换了多少次地址 
void text04()
{
	vector<int> v;

	v.reserve(100000);//预留空间，较大案例会用

	int *p = NULL;
	int num = 0;
	for (int i = 0;i < 100000;i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << num << endl;
}

int main()
{
	text04();



	system("pause");
	return 0;
}








