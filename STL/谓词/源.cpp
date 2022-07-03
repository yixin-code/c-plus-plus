// 返回是bool类型的反函数
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Print
{
public:
	void operator()(vector<int>& v)
	{
		for (auto& val : v)
		{
			cout << val << " ";
		}
		cout << endl;
	}
};

class GreaterThan
{
public:
	bool operator()(int num)
	{
		return num > 5;
	}
};

void test()
{
	Print print;
	vector<int> v{ 1,3,4,5,2,34,2 };

	print(v);

	sort(v.begin(), v.end());

	print(v);

	sort(v.begin(), v.end(), [](int v, int v2) {return v > v2; });

	print(v);

	auto it = find_if(v.begin(), v.end(), GreaterThan());

	//auto rit = v.rbegin();
		
	while (it != (v.begin()))
	{
		cout << *it << " ";
		--it;
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	test();

	return 0;
}