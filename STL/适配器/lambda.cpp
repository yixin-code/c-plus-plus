	// 将两个参数绑定为一个参数bind2nd绑定第二个参数, bind1st绑定第一个参数
	// C++11中，直接使用bind用法相同， bind更灵活 可以绑定多个参数
	// 其实lambda最好用
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

void test1()
{
	vector<int> v = { 1,2,3,4,4,5,3,6,43,5,4 };
	string str;
	cin >> str;
	for_each(v.begin(), v.end(), [=](int &val) {
		cout << str << " " << val << endl;
		});
}

int main1()
{
	test1();

	return 0;
}