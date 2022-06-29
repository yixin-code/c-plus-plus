//��Ӧ���ݽṹ�е�ջ, ���Ƚ����������.
//����deque, , ����˳������vector, list, deque.

//��������ɾ��, ���ܷ����м�Ԫ��.
//û�е�����, �������Ե�������, ��֧���±����

//stack<int> s;
//stack<int, deque<int>> s;    //�����ȼ۵�
//Ҫ��vector����stack����
//stack<int, vector<int>> s;

#include <stack>
#include <iostream>

using namespace std;

int main()
{
	stack<int> s;

	//�ж�ջ�Ƿ�Ϊ��
	if (s.empty())
	{
		cout << "is empty" << endl;
	}

	//ջ������Ԫ��
	s.emplace(1);	//C++11
	s.push(2);

	//����ջ��Ԫ��
	cout << s.top() << endl;	//2

	//ջ�е�Ԫ�ظ���
	cout << s.size() << endl;	//2

	//ɾ��ջ��Ԫ��
	s.pop();

	cout << s.top() << endl;	//1

	//��������stack
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
