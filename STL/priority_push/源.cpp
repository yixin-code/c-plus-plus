//һ�������ȼ��Ķ���, ���԰���ĳ�����ȼ�˳�����ɾ��.
//����vector, ����˳������vector, deque, ���������ṩ������ʹ���.
//�ṩ��top������һ��Ԫ��, Ĭ�ϴӴ�С˳�����ɾ��.

//���Ԫ���Ƕ���, ��������, Ĭ������.
//û��front��back

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> q;

	//�п�
	if (q.empty())
	{
		cout << "is empty" << endl;
	}

	//���Ԫ��
	q.push(4);
	q.push(5);
	q.push(1);
	q.push(9);
	q.emplace(2);

	//�������Ԫ��
	cout << q.top() << endl;	//4

	//����Ԫ�ظ���
	cout << q.size() << endl;	//2

	//ɾ�����Ԫ��
	q.pop();

	cout << q.top() << endl;	//2

	return 0;
}