	// ������������Ϊһ������bind2nd�󶨵ڶ�������, bind1st�󶨵�һ������
	// C++11�У�ֱ��ʹ��bind�÷���ͬ�� bind����� ���԰󶨶������
	// ��ʵlambda�����
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