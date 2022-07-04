#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 合并两个有序容器
void test3()
{
	vector<int> v = { 0,1,2,3,4 };
	vector<int> v2 = { 5,6,7,8,9 };
	vector<int> v3(10);
	merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	for (auto& val : v3)
	{
		cout << val << " ";    //0123456789
	}
	cout << endl;

	vector<int> v4 = { 4,3,2,1,0 };
	vector<int> v5 = { 9,8,7,6,5 };
	vector<int> v6(10); // 目标容器需要开辟空间
	merge(v4.begin(), v4.end(), v5.begin(), v5.end(), v6.begin(), [](int val, int val2) {return val > val2; });
	for (auto& val : v6)
	{
		cout << val << " ";    //9876543210
	}
	cout << endl;
}

// 排序
void test32()
{
	vector<int> v = { 5,1,5,7,5,3,8,2 };
	sort(v.begin(), v.end());
	for (auto val : v)
	{
		cout << val << " ";	//1 2 3 5 5 5 7 8
	}
	cout << endl;

	vector<int> v2 = { 5,1,5,7,5,3,8,2 };
	sort(v2.begin(), v2.end(), [](int val, int val2) {return val > val2; });
	for (auto val : v2)
	{
		cout << val << " ";	//8 7 5 5 5 3 2 1
	}
	cout << endl;
}

// 打乱顺序(洗牌)
void test34()
{
	srand((unsigned int)time(NULL));
		
	vector<int> v = { 1,2,3,4,5,6,7,8,9 };

	random_shuffle(v.begin(), v.end());
	for (auto val : v)
	{
		cout << val << " ";
	}
	cout << endl;
}

// 反转
void test35()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9 };

	reverse(v.begin(), v.end());

	for (auto val : v)
	{
		cout << val << " ";	//9 8 7 6 5 4 3 2 1
	}
	cout << endl;
}

int main3()
{
	test34();

	return 0;
}