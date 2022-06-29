//对应数据结构中的队列, 有先进先出的特性.
//来自deque, 可用顺序容器list, deque.容器必须提供前插(push_front())运算

//队尾插入, 队首删除, 同样不能访问中间元素, 并且没有迭代器

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;

	//判空
	if (q.empty())
	{
		cout << "is empty" << endl;
	}

	//队尾插入元素
	q.push(1);
	q.emplace(2);

	//返回队首元素
	cout << q.front() << endl;	//1

	//返回队尾元素
	cout << q.back() << endl;	//2	

	//返回当前元素个数
	cout << q.size() << endl;	//2

	//删除队首元素
	q.pop();
	cout << q.size() << endl;	//1
	cout << q.front() << endl;	//2

	queue<int> q2;
	q2.emplace(1);
	q2.emplace(2);
	q2.emplace(3);
	q2.emplace(4);
	q2.emplace(5);

	//交换两个容器
	q.swap(q2);
	cout << q.size() << endl;	//5
	cout << q2.size() << endl;	//1

	return 0;
}