//顺序容器选择
//vector是一段连续的内存块, 而deque是多个连续的内存块, list是数据分开存储
//vector查询性能最好, 尾端增加数据性能也很好, 可以高效的随机存取
//list插入, 删除性能最好, 查询差, 适合较多的插入删除操作并且不关心随机存取
//deque两则结合, 他是由链表和数组结合的产生的, 他比list查询好, 比vector插入删除好.当频繁的需要两端插入删除可以选择.

//关联容器选择
//都是树形结构, 内部是二叉树(红黑树)结构实现. 红黑树，大于左孩子小于右孩子
//set和map保证了元素的唯一性, multiset和multimap扩展了这一特性.元素是有序的集合默认升序.
//当需要知道一个值是否存在的时候使用set再合适不过
//set内部还是链表的形式, 插入快于vector, 查找和尾插慢于vector
//map和set一样内部还是链表的形式, 由链表的优点, 它提供键(key) - 值(value)对应的关系

//容器适配器选择
//priority_queue优先级队列适配器要求随机访问功能, 所以只有vector, deque
//stack先进后出, 可以任意一种顺序容器, 可以push_back, pop_back和back操作
//queue先进先出, 适配器要求pop_front, 所以只有deque, list

// 不支持随机访问的迭代器 不可以使用algorithm
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void display(int v)
{
	cout << v << " ";
}

// 基本使用
void test()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	// *it 就是<> 中的类型
	// v.end 指向最后一个元素的下一位置
	for (vector<int>::iterator it = v.begin(); it < v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 回调函数
	for_each(v.begin(), v.end(), display);
	cout << endl;
}

// 容器嵌套
void test2()
{
	vector<vector<int>> vv;
	vector<int> v;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < 11; ++i)
	{
		v.push_back(i);
		v2.push_back(2 * i);
		v3.push_back(3 * i);
	}

	vv.push_back(v);
	vv.push_back(v2);
	vv.push_back(v3);

	for (vector<vector<int>>::iterator vit = vv.begin(); vit < vv.end(); ++vit)
	{
		for (vector<int>::iterator it = vit->begin(); it < vit->end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}

int main(int argc, char** argv)
{
	test();
	test2();

	return 0;
}