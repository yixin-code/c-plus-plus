//对应数据结构中的栈, 有先进后出的特性.
//来自deque, , 可用顺序容器vector, list, deque.

//顶部插入删除, 不能访问中间元素.
//没有迭代器, 遍历可以弹出访问, 不支持下标操作

//stack<int> s;
//stack<int, deque<int>> s;    //两个等价的
//要从vector衍生stack可以
//stack<int, vector<int>> s;

#include <stack>
#include <iostream>

using namespace std;

int main()
{
	stack<int> s;

	//判断栈是否为空
	if (s.empty())
	{
		cout << "is empty" << endl;
	}

	//栈顶插入元素
	s.emplace(1);	//C++11
	s.push(2);

	//返回栈顶元素
	cout << s.top() << endl;	//2

	//栈中的元素个数
	cout << s.size() << endl;	//2

	//删除栈顶元素
	s.pop();

	cout << s.top() << endl;	//1

	//交换两个stack
	stack<int> s2;
	s2.emplace(4);
	s2.emplace(8);
	s2.emplace(9);
	s2.emplace(2);

	s.swap(s2);
	cout << s.size() << endl;	//4
	cout << s2.size() << endl;	//1

	return 0;
}
