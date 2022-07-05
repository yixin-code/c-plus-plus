#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

void test()
{
	const int NUM = 1111111;
	vector<int> v;
	clock_t timeNow = clock(); // 运行到此处的时间
	try
	{
		for (int i = 0; i < NUM; ++i)
		{
			v.emplace_back(rand());
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		abort(); // 终止程序
	}
	cout << "assign time " << clock() - timeNow << endl;
	cout << "size " << v.size() << endl;	

	int target = 5496;

	timeNow = clock();
	auto it = find(v.begin(), v.end(), target);
	if (it == v.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << *it << endl;
	}
	cout << "find time " << clock() - timeNow << endl;

	sort(v.begin(), v.end());
	timeNow = clock();
	if (binary_search(v.begin(), v.end(), target))
	{
		cout << "find" << endl;
	}
	else
	{
		cout << "not find" << endl;
	}
	cout << "binary_search time " << clock() - timeNow << endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	test();

	return 0;
}