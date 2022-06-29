// 五名选手，十个评委打分
// 去掉最低最高分，取平均分
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include "Person.h"

using namespace std;

void player(vector<Person>& v)
{
	for (int i = 0; i < 5; ++i)
	{
		string str = "ABCDE";
		Person p(str.substr(i, 1), 0);
		v.push_back(p);
	}
}

void score(vector<Person>& v)
{
	for (auto it = v.begin(); it < v.end(); ++it)
	{
		deque<int> d;
		for (int i = 0; i < 10; ++i)
		{
			int num = rand() % 51 + 50;
			d.push_back(num);
		}

		//test
		for (auto it = d.begin(); it < d.end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;

		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (auto it = d.begin(); it < d.end(); ++it)
		{
			sum += *it;
		}

		int average = sum / d.size();
		it->m_score = average;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	vector<Person> v;
	player(v);
	score(v);
	// test
	for (auto it = v.begin(); it < v.end(); ++it)
	{
		cout << it->m_name << " " << it->m_score << endl;
	}

	return 0;
}