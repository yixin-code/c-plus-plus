// 五个员工，进入部门
// 显示信息
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Staff.h"

using namespace std;

void createStaff(vector<Staff>& v)
{
	string str = "ABCDE";
	string name = "staff_";

	for (int i = 0; i < 5; ++i)
	{
		Staff s;
		s.setName(name + str[i]);
		s.setSalary(rand() % 10000 + 10000);
		v.push_back(s);
	}

	// test
	// auto 如果是引用需要添加&
	for (auto& val : v)
	{
		cout << val.getName() << " " << val.getSalary() << endl;
	}
}

enum department
{
	RAD, ART, TEST
};

void assignStaff(vector<Staff>& v, multimap<int, Staff>& m)
{
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		int num = rand() % 3;
		m.insert(make_pair(num, *it));
	}

	// test
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second.getName() << " "
			<< it->second.getSalary() << endl;
	}
}

void display(multimap<int, Staff>& m)
{
	//RAD, ART, TEST

	cout << "RAD:" << endl;
	auto it = m.find(RAD);
	size_t num = m.count(RAD);
	while (num)
	{
		cout << it->second.getName() << " " << it->second.getSalary() << endl;
		it++;
		num--;
	}

	cout << "ART:" << endl;
	it = m.find(ART);
	num = m.count(ART);
	while (num)
	{
		cout << it->second.getName() << " " << it->second.getSalary() << endl;
		it++;
		num--;
	}

	cout << "TEST:" << endl;
	it = m.find(TEST);
	num = m.count(TEST);
	while (num)
	{
		cout << it->second.getName() << " " << it->second.getSalary() << endl;
		it++;
		num--;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	vector<Staff> v;
	multimap<int, Staff> m;
	createStaff(v);
	assignStaff(v, m);
	display(m);

	return 0;
}