#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

void display3(int val, int num)
{
	cout << val + num << " ";
}

int main3()
{
	vector<int> v = { 1,2,4,5,6,7,8,9,6,4 };
	int num = 11;
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(display3), num));

	return 0;
}