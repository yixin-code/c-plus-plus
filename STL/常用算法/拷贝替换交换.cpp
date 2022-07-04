#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 拷贝
void test4()
{
	vector<int> v2 = { 3,2,4,5,6,7,8,9 };
	int arr[] = { 1,2,3,4,5,6 };
	vector<int> v(v2.size());

	copy(v2.begin(), v2.end(), v.begin());
	for (auto& val : v)
	{
		cout << val << " ";
	}
	cout << endl;

	v.resize(sizeof(int[6]) / sizeof(int));
	copy(arr, arr + 6, v.begin());
	for (auto& val : v)
	{
		cout << val << " ";
	}
	cout << endl;
}

// 条件拷贝
void test41()
{
	vector<int> v;
	vector<int> v2 = { 1,2,3,4,5,6,7 };
	v.resize(v2.size());

	auto it = copy_if(v2.begin(), v2.end(), v.begin(), [](int val) {return val % 2; });
	v.resize(distance(v.begin(), it));	//重新分配元素个数
	for (auto& val : v)
	{
		cout << val << " ";	//1357
	}
	cout << endl;
}

// 替换
void test42()
{
	vector<int> v = { 1,2,5,6,7,3,2,1,6,8 };

	replace(v.begin(), v.end(), 1, 1111);

	for (auto val : v)
	{
		cout << val << " ";	//1111 2 5 6 7 3 2 1111 6 8
	}
	cout << endl;
}

// 条件替换
void test43()
{
	vector<int> v = { 1,2,5,6,7,3,2,1,6,8 };

	replace_if(v.begin(), v.end(), [](int val) {return val < 5; }, 1111);

	for (auto val : v)
	{
		cout << val << " ";	//1111 1111 5 6 7 1111 1111 1111 6 8
	}
	cout << endl;
}

// 交换
void test44()
{
	vector<int> v = { 11,22,33,44,55 };
	vector<int> v2 = { 1,2,3,4,5 };

	swap(v, v2);
	for (auto val : v)
	{
		cout << val << " ";	//1 2 3 4 5
	}
	cout << endl;

	for (auto val : v2)
	{
		cout << val << " ";	//11 22 33 44 55
	}
	cout << endl;
}

int main4()
{


	return 0;
}