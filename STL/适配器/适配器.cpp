#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

// bind1st bind2nd
class Print : public binary_function<int, int, void>
{
public:
	void operator()(int val, int num) const
	{
		cout << val + num << " ";
	}
};

// È¡·´ not1 not2
class Negation : public unary_function<const int&, bool>
{
public:
	bool operator()(const int &val) const
	{
		return val > 5;
	}
};

void test2()
{
	vector<int> v = { 1,1,2,3,4,5,5,4,5,5,46,4,4,9 };

	int num = 11;
	for_each(v.begin(), v.end(), bind2nd(Print(), num));
	cout << endl;

	auto it = find_if(v.begin(), v.end(), not1(Negation()));
	if (it == v.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find " << *it << endl;
	}
}

int main2()
{
	test2();

	return 0;
}