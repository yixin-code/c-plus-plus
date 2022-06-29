//�б�(list)
//һ��˫��ѭ������, ���vector����ϵ�ռ�, list���Ӻܶ�, �����Կ��ٵĲ����ɾ��, ����������ʱȽ���.
//��Ϊ������ʵ��, ������������ɿռ��˷�.
#include <iostream>
#include <list>
#include <vector>

using namespace std;

// ���� ����
void test()
{
	//��ʵ�����ڵĺ��������,���캯��������vector��ȫһ��
	list<int> l;	//����һ���յ�list
	list<int> l2(3);	//����һ������3��Ԫ�ص�list
	list<int> l3(3, 1);	//����һ������3��Ԫ�ص�list,ÿ������ʼ��Ϊ1
	list<int> l4(l3);	//����һ��list,����l3������г�ʼ��
	list<int> l5(l4.begin(), l4.end());	//�õ��������г�ʼ��

	//Ҳ����Ϊ�����ֵ
	l.assign(l4.begin(), l4.end());
	l2.assign(3, 1);	//Ϊ�丳ֵ3��1

	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	list<int> l6(arr, arr + 10);	//ʹ�����������г�ʼ��

	//����
	//for (list<int>::iterator it = l5.begin(); it != l5.end(); ++it)
	for (auto it = l6.begin(); it != l6.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//����һ��������
	auto it = l6.begin();

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	auto it2 = v.begin();
	//it + 2;	//����֧���������
	it2 + 2;	//correct

	cout << *(it2 + 2) << endl;
}

// ������
void test2()
{
	list<int> l;
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	l.assign(arr, arr + 10);

	//���������
	auto it_end = l.end();
	//cout << *it_end << endl;	//������ ָ��������һ��Ԫ�ص���һλ��

	auto it_begin = l.begin();
	cout << *it_begin << endl;	//������ǵ�һ��Ԫ�� 1

	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	cout << endl;
	cout << endl;

	//���������
	auto rit_end = l.rend();
	//cout << *rit_end << endl;	//ͬ����� ָ���һ��Ԫ�ص���һλ��

	auto rit_begin = l.rbegin();
	cout << *rit_begin << endl;	//����������һ��Ԫ�� 0

	for (auto it = l.rbegin(); it != l.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// ����Ԫ��
void test3()
{
	list<int> l;
	int arr[] = { 1,2,3,4,5 };
	vector<int> v(arr, arr + 5);

	//���
	l.push_back(1);

	//ǰ��
	l.push_front(2); //2 1

	//���� ���뵽������λ�� ���ز��������λ��
	auto it = l.insert(l.begin(), 3);	//3 2 1
	cout << *it << endl;	//3

	//����3��1��������λ�� �޷���ֵ
	l.insert(l.begin(), 3, 1);	//111321

	//����������������ݵ�������λ��
	l.insert(l.begin(), arr, arr + 5);	//12345111321
	l.insert(l.begin(), v.begin(), v.end());	//1234512345111321

	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//1234512345111321
	}
	cout << endl;
}

// ν��

//������ʽν��
bool func(int& val)
{
	return val < 6;
}

//�º�����ʽν��
class functor
{
public:
	bool operator()(int& val)
	{
		return val < 6;
	}
};

bool func2(int val, int val2)
{
	return val > val2;
}

// ɾ��Ԫ��
void test4()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0 };
	list<int> l(arr, arr + 20);

	//ɾ��������ָ��λ��
	l.erase(l.begin());	//23456789012345

	//ɾ��ָ������������
	auto it = l.begin();
	it++;
	it++;
	//it + 1;	����������ʵĵ�����������1Ҳ�ǲ����Ե�
	l.erase(l.begin(), it);	//45678901234567890

	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";		//45678901234567890
	}
	cout << endl;

	//��ֵɾ��Ԫ��,ɾ��list�������ֵ��Ԫ��
	l.remove(4);	//567890123567890

	//������ɾ��,��Ҫν��
	//��Ч���ǵȼ۵�
	//l.remove_if(func);
	l.remove_if(functor());	//67896789

	//ɾ����һ��Ԫ��
	l.pop_front();	//7896789

	//ɾ�����һ��Ԫ��
	l.pop_back();	//789678

	//ɾ���ظ�Ԫ�� ֻ��ɾ�������ظ���
	l.unique();
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";		//789678
	}
	cout << endl;

	l.push_front(7);
	l.push_front(7);
	l.push_back(8);
	l.push_back(8);
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";		//7778967888
	}
	cout << endl;

	l.unique();
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";		//789678
	}
	cout << endl;

	//ɾ������С��ǰ�ߵ�Ԫ��
	l.unique(func2);
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";		//789
	}
	cout << endl;

	//ɾ������Ԫ��
	l.clear();
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool greaterThan(int val, int val2)
{
	return val > val2;
}

void test5()
{
	list<int> l;

	//�ж��б��Ƿ�Ϊ��
	if (l.empty())
	{
		cout << "is empty" << endl;
	}

	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	l.insert(l.begin(), arr, arr + 9);

	//�������һ��Ԫ��
	cout << l.back() << endl;	//9

	//���ص�һ��Ԫ��
	cout << l.front() << endl;	//1

	//���Ԫ������(����)
	cout << l.max_size() << endl;

	//list�е�ǰԪ�ظ���
	cout << l.size() << endl;	//9

	//�ı�Ԫ�ظ���
	l.resize(5);
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//12345
	}
	cout << endl;
	cout << l.size() << endl;	//5

	//���䲿����1����ʼ��
	l.resize(10, 1);
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//1234511111
	}
	cout << endl;
	cout << l.size() << endl;	//10

	//����	Ĭ������ ����ʹ��ν�ʸı�
	l.sort();
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//1111112345
	}
	cout << endl;

	//����
	l.sort(greaterThan);
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//5432111111
	}
	cout << endl;

	//�ϲ� ����������������б� 
	list<int> l2 = { 2,3,4,5,6,6,2,34,5,2 };
	l2.sort();
	l.sort();

	//Ĭ��Ҳ������ Ҫ��ԭ������˳����ͬ �ϲ�֮��l2Ϊ��
	l.merge(l2);
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//1 1 1 1 1 1 2 2 2 2 3 3 4 4 5 5 5 6 6 34
	}
	cout << endl;
	cout << l2.size() << endl;	//0

	//����ϲ�ͬ����Ҫν��
	l2 = { 5,2,3,4,5,1,2,9 };
	l.sort(greaterThan);
	l2.sort(greaterThan);
	l.merge(l2, greaterThan);
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//34 9 6 6 5 5 5 5 5 4 4 4 3 3 3 2 2 2 2 2 2 1 1 1 1 1 1 1
	}
	cout << endl;
	cout << l2.size() << endl;	//0

	//ƴ������list l2�����Ԫ��
	l2 = { 5,2,3,4,5,1,2,9 };

	//�ڵ�����λ��,��������l2
	l.splice(l.begin(), l2);
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//5 2 3 4 5 1 2 9 34 9 6 6 5 5 5 5 5 4 4 4 3 3 3 2 2 2 2 2 2 1 1 1 1 1 1 1
	}
	cout << endl;
	cout << l2.size() << endl;	//0

	//�ڵ�����λ��,��������l2�е�������Ԫ��
	l2 = { 5,2,3,4,5,1,2,9 };
	l.splice(l.begin(), l2, l2.begin());
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//5 5 2 3 4 5 1 2 9 34 9 6 6 5 5 5 5 5 4 4 4 3 3 3 2 2 2 2 2 2 1 1 1 1 1 1 1
	}
	cout << endl;

	//�ڵ�����λ��,�����б��һ������������
	l.clear();
	l = { 2,43,24,1342,4 };
	l2 = { 5,2,3,4,5,1,2,9 };

	l.splice(l.begin(), l2, l2.begin(), l2.end());
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//5 2 3 4 5 1 2 9 2 43 24 1342 4
	}
	cout << endl;

	//listԪ�ص�ת
	l.reverse();
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//5 2 3 4 5 1 2 9 2 43 24 1342 4
	}
	cout << endl;

	//��������list
	l2 = { 1,4,5,2,5,6,1 };
	l.swap(l2);
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//1 4 5 2 6 1
	}
	cout << endl;

	for (list<int>::iterator it = l2.begin(); it != l2.end(); ++it)
	{
		cout << *it << " ";	//5 2 3 4 5 1 2 9 2 43 24 1342 4
	}
	cout << endl;
}

int main()
{

	return 0;
}