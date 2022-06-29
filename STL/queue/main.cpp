//��Ӧ���ݽṹ�еĶ���, ���Ƚ��ȳ�������.
//����deque, ����˳������list, deque.���������ṩǰ��(push_front())����

//��β����, ����ɾ��, ͬ�����ܷ����м�Ԫ��, ����û�е�����

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;

	//�п�
	if (q.empty())
	{
		cout << "is empty" << endl;
	}

	//��β����Ԫ��
	q.push(1);
	q.emplace(2);

	//���ض���Ԫ��
	cout << q.front() << endl;	//1

	//���ض�βԪ��
	cout << q.back() << endl;	//2	

	//���ص�ǰԪ�ظ���
	cout << q.size() << endl;	//2

	//ɾ������Ԫ��
	q.pop();
	cout << q.size() << endl;	//1
	cout << q.front() << endl;	//2

	queue<int> q2;
	q2.emplace(1);
	q2.emplace(2);
	q2.emplace(3);
	q2.emplace(4);
	q2.emplace(5);

	//������������
	q.swap(q2);
	cout << q.size() << endl;	//5
	cout << q2.size() << endl;	//1

	return 0;
}