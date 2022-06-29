// ���Կ��ٵĽ���ͷ�壬�ڲ�ʵ�����Ƕ���ڵ�ָ��ά����
#include <iostream>
#include <deque>

using namespace std;

// ��ʼ��
void test()
{
	deque<int> d;
	deque<int> d2(3);	//��������Ԫ��
	deque<int> d3(3, 1);	//��ʼ��3��Ԫ�� ����1
	deque<int> d4(d2);	//��һ��deque��ʼ����һ��
	deque<int> d5(d3.begin(), d3.end());	//�õ�������ʼ��
	deque<int> d6 = { 1,2,34,324,5,5 };	//ֱ�ӳ�ʼ��
	int arr[] = { 3,1,2,4,5,1,2,2,5,3 };
	deque<int> d7(arr, arr + 10);	//��ֵ��������
	deque<int> d8;
	d8.assign(3, 1);	//��ʼ��3��Ԫ�� ����1
	d.assign(d3.begin(), d3.end());	//�õ�������ʼ��


	for (auto it = d7.begin(); it != d7.end(); ++it)
	{
		cout << *it << " ";	//3 1 2 4 5 1 2 2 5 3
	}
	cout << endl;

	//֧���������
	for (int i = 0; i < d6.size(); ++i)
	{
		cout << d6[i] << " ";	//1 2 34 324 5 5
	}
	cout << endl;

	//at �ⶫ�����Ǹ���ȫ���˶���
	for (int i = 0; i < d.size(); ++i)
	{
		cout << d.at(i) << " ";	//1 1 1
	}
}

// ����Ԫ��
void test2()
{
	deque<int> d;
	deque<int> d2 = { 3,3,3 };

	//�ڿ�ʼ������λ�ò���1
	d.insert(d.begin(), 1);	//1

	//�ڿ�ʼ����������1λ������2��2
	d.insert(d.begin() + 1, 2, 2);	//122

	//�ڿ�ʼ����������3λ������d2�ĵ���������
	d.insert(d.begin() + 3, d2.begin(), d2.end());	//122333

	//ǰ��
	d.push_front(0);	//0122333

	//���
	d.push_back(4);		//01223334

	for (int i = 0; i < d.size(); ++i)
	{
		cout << d[i] << " ";	//0 1 2 2 3 3 3 4
	}
	cout << endl;
}

// ɾ��Ԫ��
void test3()
{
	deque<int> d = { 1,2,3,4,5,6,7,8,9,0 };

	//ɾ����һ��Ԫ�� 
	d.erase(d.begin());	//2 3 4 5 6 7 8 9 0 

	//ɾ������������ ���䶼������ҿ�
	d.erase(d.begin(), d.begin() + 3);	//5 6 7 8 9 0 

	//ͷɾ
	d.pop_front();	//6 7 8 9 0 

	//βɾ
	d.pop_back();	//6 7 8 9

	for (int i = 0; i < d.size(); ++i)
	{
		cout << d[i] << " ";	//6 7 8 9
	}
	cout << endl;

	//ɾ������Ԫ��
	d.clear();
	cout << d.size() << endl;	//0
}

// ��������
void test4()
{
	deque<int> d;

	//�ж��Ƿ�Ϊ��
	if (d.empty())
	{
		cout << "is empty" << endl;	//��ִ�б������
	}

	d = { 1,2,3,4,5,6,7,8,9 };

	//��ʼ������ ָ���һ��Ԫ��
	auto it_begin = d.begin();

	//β�������� ָ�����һ��Ԫ�ص���һλ��
	auto it_end = d.end();

	//�����ʼ������ ָ�����һ��Ԫ��
	auto it_rbegin = d.rbegin();

	//����β�������� ָ���һ��Ԫ�ص���һ��λ��
	auto it_rend = d.rend();

	//���ص�һ��Ԫ��
	cout << d.front() << endl;	//1

	//�������һ��Ԫ��
	cout << d.back() << endl;	//9

	//������������Ԫ��
	cout << d.max_size() << endl;	//1073741823

	//�ı��С С��ԭ�ռ�ʱ��ض����� ����ԭ�ռ�ʱ�����Ԫ�ػ��ʼ��Ϊ0
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

	//ָ�������Ԫ�س�ʼ��Ϊ1
	d.resize(10, 1);
	for (int i = 0; i < d.size(); ++i)
	{
		cout << d[i] << " ";	//1 2 3 4 5 1 1 1 1 1
	}
	cout << endl;

	//��������Ԫ�� ��ȡ��С�ռ�
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