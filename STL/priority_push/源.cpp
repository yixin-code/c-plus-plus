//一个带优先级的队列, 可以按照某种优先级顺序进行删除.
//来自vector, 可用顺序容器vector, deque, 容器必须提供随机访问功能.
//提供了top访问下一个元素, 默认从大到小顺序进行删除.

//最大元素是队首, 可以排序, 默认升序.
//没有front和back

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> q;

	//判空
	if (q.empty())
	{
		cout << "is empty" << endl;
	}

	//添加元素
	q.push(4);
	q.push(5);
	q.push(1);
	q.push(9);
	q.emplace(2);

	//返回最大元素
	cout << q.top() << endl;	//4

	//返回元素个数
	cout << q.size() << endl;	//2

	//删除最大元素
	q.pop();

	cout << q.top() << endl;	//2

	return 0;
}