#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int myCompare(const void* val, const void* val2)
{
	return *(long*)val < *(long*)val2;
}

void test()
{
	const long NUM = 111111;

	array<long, NUM> arr{};
	clock_t timeBegin = clock(); // 执行时的时间 毫秒
	for (int i = 0; i < arr.size(); ++i)
	{
		arr[i] = rand();
	}
	clock_t timeEnd = clock();
	cout << "time: " << timeEnd - timeBegin << endl;
	cout << "size: " << arr.size() << endl;
	cout << arr.data() << " " << &arr << endl;
	cout << "----------------------" << endl;

	long target = 13423;
	timeBegin = clock();
	//qsort(arr.data(), NUM, sizeof(long), myCompare);
	//long* res = (long*)bsearch(&target, (arr.data()), NUM, sizeof(long), myCompare);
	sort(arr.begin(), arr.end());
	auto res = find(arr.begin(), arr.end(), target);
	timeEnd = clock();
	cout << timeEnd - timeBegin << endl;
	cout << *res << endl;
};

int main()
{
	srand((unsigned int)time(NULL));
	test();

	return 0;
}