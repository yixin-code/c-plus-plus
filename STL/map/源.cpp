//map提供优秀的一对一数据处理能力.
//元素是由key和value两部分组成的队组.key是唯一的.
//给定一个key, 就能确定相对的value.
//map也叫关联数组, 只是索引的方式是key不是整数.
//map是一个有序的不允许key重复的容器, 默认为升序.
//multimap是一个有序的允许key重复的容器, 默认为升序.
#include <iostream>
#include <string>
#include <map>

using namespace std;

void test()
{
	//创建一个空的map
	map<int, string> m;

	//直接赋值
	map<int, string> m2 = {
		{1,"a"},
		{2,"b"},
		{3,"c"}
	};

	//复制构造函数
	map<int, string> m3(m2);

	//使用迭代器赋值
	map<int, string> m4(m3.begin(), m3.end());

	//赋值构造函数
	m = m4;

	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
}

// 增加元素
void test2()
{
	map<int, int> m;

	//会自动进行排序
	map<int, int> m2{
		{ 4,44 },
		{ 1,11 },
		{ 3,33 },
		{ 2,22 },
		{ 5,55 },
	};

	//按照迭代器位置插入,返回指向这个元素的迭代器
	auto it = m.insert(m.begin(), pair<int, int>(6, 66));
	cout << it->first << " " << it->second << endl;
	cout << endl;

	//不支持随机访问
	//auto it = m.begin();
	//it + 3;    //error

	//插入一个迭代器区间
	m.insert(m2.begin(), m2.end());
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;

	//直接插入 value可以重复
	m.insert(make_pair(11, 11));

	//无效插入 key值不能重复
	m.insert(make_pair(1, 434));

	m.emplace(1, 1);

	//还可以使用value_type
	//map<int, int>::key_type; //key
	//map<int, int>::mapped_type;	//value
	//map<int, int>::value_type;	//pair<int,int>
	m.insert(map<int, int>::value_type(9, 99));

	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
}

// 删除
void test3()
{
	map<int, int> m = {
			{1,11},
			{2,22},
			{3,33},
			{4,44},
			{5,55},
			{6,66},
			{7,22},
			{8,22},
			{9,22}
	};

	//按位置删除
	m.erase(m.begin());
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;

	//按迭代器区间删除
	auto it = m.begin();
	it++;
	it++;
	it++;
	m.erase(m.begin(), it);
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;

	//按key删除 在multimap中是删除所有key
	m.erase(5);
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;

	multimap<int, int> mm = {
		{1,11},
		{2,22},
		{3,33},
		{4,44},
		{5,55},
		{5,55},
		{5,55},
		{5,55},
		{5,55},
		{5,55},
		{6,66},
		{7,22},
		{8,22},
		{9,22}
	};
	mm.erase(5);
	for (auto it = mm.begin(); it != mm.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;

	//删除所有元素
	m.clear();
}

class greaterThan
{
public:
	bool operator()(int val, int val2) const
	{
		return val > val2;
	}
};

void test4()
{
	map<int, int> m = {
		{1,11},
		{2,22},
		{3,33},
		{4,44},
		{6,66},
		{7,22},
		{8,22},
		{9,22},
		{11,111}
	};

	// 查找 返回迭代器
	auto it = m.find(3);

	map<int, int> m2;

	//初始迭代器 指向第一个元素
	auto it_begin = m.begin();

	//末尾迭代器 指向最后一个元素的下一位置
	auto it_end = m.end();

	//逆向初始迭代器 指向最后一个元素
	auto it_rbegin = m.rbegin();

	//你想结尾迭代器 指向第一个元素的上一位置
	auto it_rend = m.rend();

	//判断是否为空
	if (m2.empty())
	{
		cout << "is empty" << endl;
	}

	//equal_range返回一个对组里面是两个map迭代器,第一个指向key相等的元素,第二个指向key的下一个元素
	//如果key不存在返回的是 >key 的两个元素
	//如果key大于最后一个key,程序奔溃
	//其实这个函数就是找到 相等的上下限 上限可以相等 下限不能
	//再说人话的意思就是 第一个指向 >=key 第二个指向 >key
	pair<map<int, int>::iterator, map<int, int>::iterator> ret = m.equal_range(6);
	cout << ret.first->first << " " << ret.first->second << endl;	//6 66
	cout << ret.second->first << " " << ret.second->second << endl;	//7 22
	cout << endl;

	//lower_bound 这个关系就是和equal_range 第一个元素一样
	auto it = m.lower_bound(6);
	cout << it->first << " " << it->second << endl << endl;	//6 66

	//upper_bound 这个关系就是和equal_range 第二个元素一样
	auto it2 = m.upper_bound(6);
	cout << it2->first << " " << it2->second << endl << endl;	//7 22

	//比较两个key 
	map<int, int>::key_compare mkcomp = m.key_comp();
	if (mkcomp(2, 4))
	{
		cout << "2 less than 4" << endl;
	}
	cout << endl;

	//比较两个元素(两个pair)
	map<int, int>::value_compare mvcomp = m.value_comp();
	auto pval = m.begin();
	auto it_pair = m.begin();
	it_pair++;
	it_pair++;
	it_pair++;
	auto &pval2 = it_pair;
	if (mvcomp(*pval, *pval2))
	{
		cout << "pval less than pval2" << endl;
	}
	cout << endl;

	//改变排序方式
	map<int, int, greaterThan> m3 = {
		{1,11},
		{2,22},
		{3,33},
		{4,44},
		{6,66},
		{7,22},
		{8,22},
		{9,22},
		{11,111}
	};

	map<int, int, greaterThan>::key_compare mcomp2 = m3.key_comp();
	if (mcomp2(5, 2))
	{
		cout << "5 greater than 2" << endl;
	}
	cout << endl;

	//最大容纳元素个数
	cout << m.max_size() << endl << endl;

	//当前元素个数
	cout << m.size() << endl << endl;

	//交换两个map
	map<int, int> m4 = {
		{4,2},
		{3,1},
		{5,6}
	};
	m4.swap(m);
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
	cout << endl;

	for (auto it = m4.begin(); it != m4.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	test3();

	return 0;
}
