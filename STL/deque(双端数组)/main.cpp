// 可以快速的进行头插，内部实际上是多个节点指针维护的
#include <iostream>
#include <deque>

using namespace std;

// 初始化
void test()
{
	deque<int> d;
	deque<int> d2(3);	//开辟三个元素
	deque<int> d3(3, 1);	//初始化3个元素 都是1
	deque<int> d4(d2);	//用一个deque初始化另一个
	deque<int> d5(d3.begin(), d3.end());	//用迭代器初始化
	deque<int> d6 = { 1,2,34,324,5,5 };	//直接初始化
	int arr[] = { 3,1,2,4,5,1,2,2,5,3 };
	deque<int> d7(arr, arr + 10);	//赋值数组区间
	deque<int> d8;
	d8.assign(3, 1);	//初始化3个元素 都是1
	d.assign(d3.begin(), d3.end());	//用迭代器初始化


	for (auto it = d7.begin(); it != d7.end(); ++it)
	{
		cout << *it << " ";	//3 1 2 4 5 1 2 2 5 3
	}
	cout << endl;

	//支持随机访问
	for (int i = 0; i < d6.size(); ++i)
	{
		cout << d6[i] << " ";	//1 2 34 324 5 5
	}
	cout << endl;

	//at 这东西就是更安全仅此而已
	for (int i = 0; i < d.size(); ++i)
	{
		cout << d.at(i) << " ";	//1 1 1
	}
}

// 增加元素
void test2()
{
	deque<int> d;
	deque<int> d2 = { 3,3,3 };

	//在开始迭代器位置插入1
	d.insert(d.begin(), 1);	//1

	//在开始迭代器后移1位处插入2个2
	d.insert(d.begin() + 1, 2, 2);	//122

	//在开始迭代器后移3位处插入d2的迭代器区间
	d.insert(d.begin() + 3, d2.begin(), d2.end());	//122333

	//前插
	d.push_front(0);	//0122333

	//后插
	d.push_back(4);		//01223334

	for (int i = 0; i < d.size(); ++i)
	{
		cout << d[i] << " ";	//0 1 2 2 3 3 3 4
	}
	cout << endl;
}

// 删除元素
void test3()
{
	deque<int> d = { 1,2,3,4,5,6,7,8,9,0 };

	//删除第一个元素 
	d.erase(d.begin());	//2 3 4 5 6 7 8 9 0 

	//删除迭代器区间 区间都是左闭右开
	d.erase(d.begin(), d.begin() + 3);	//5 6 7 8 9 0 

	//头删
	d.pop_front();	//6 7 8 9 0 

	//尾删
	d.pop_back();	//6 7 8 9

	for (int i = 0; i < d.size(); ++i)
	{
		cout << d[i] << " ";	//6 7 8 9
	}
	cout << endl;

	//删除所有元素
	d.clear();
	cout << d.size() << endl;	//0
}

// 其他函数
void test4()
{
	deque<int> d;

	//判断是否为空
	if (d.empty())
	{
		cout << "is empty" << endl;	//会执行本条语句
	}

	d = { 1,2,3,4,5,6,7,8,9 };

	//初始迭代器 指向第一个元素
	auto it_begin = d.begin();

	//尾部迭代器 指向最后一个元素的下一位置
	auto it_end = d.end();

	//逆向初始迭代器 指向最后一个元素
	auto it_rbegin = d.rbegin();

	//逆向尾部迭代器 指向第一个元素的上一个位置
	auto it_rend = d.rend();

	//返回第一个元素
	cout << d.front() << endl;	//1

	//返回最后一个元素
	cout << d.back() << endl;	//9

	//返回最大可容纳元素
	cout << d.max_size() << endl;	//1073741823

	//改变大小 小于原空间时会截断数据 大于原空间时多出的元素会初始化为0
	for (int i = 0; i < d.size(); ++i)
	{
		cout << d[i] << " ";	//1 2 3 4 5 6 7 8 9
	}
	cout << endl;
	cout << d.size() << endl;	//9
	d.resize(5);
	cout << d.size() << endl;	//5
	for (int i = 0; i < d.size(); ++i)
	{
		cout << d[i] << " ";	//1 2 3 4 5
	}
	cout << endl;

	//指定多出的元素初始化为1
	d.resize(10, 1);
	for (int i = 0; i < d.size(); ++i)
	{
		cout << d[i] << " ";	//1 2 3 4 5 1 1 1 1 1
	}
	cout << endl;

	//交换两个元素 会取较小空间
	deque<int> d2 = { 3,2,1 };
	d.swap(d2);
	for (int i = 0; i < d.size(); ++i)
	{
		cout << d[i] << " ";	//321
	}
	cout << endl;

	for (int i = 0; i < d.size(); ++i)
	{
		cout << d2[i] << " ";	//123
	}
	cout << endl;
}

int main()
{

	return 0;
}