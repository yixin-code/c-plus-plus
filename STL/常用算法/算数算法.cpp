#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// 求和
void test5()
{
	vector<int> v{ 1,2,3,4,5,6 };
	// 第三个参数为起始值
	int sum = accumulate(v.begin(), v.end(), 10);
	cout << sum << endl; // 31
}



int main5()
{
	test5();

	return 0;
}