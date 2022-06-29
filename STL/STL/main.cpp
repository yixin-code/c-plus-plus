//˳������ѡ��
//vector��һ���������ڴ��, ��deque�Ƕ���������ڴ��, list�����ݷֿ��洢
//vector��ѯ�������, β��������������Ҳ�ܺ�, ���Ը�Ч�������ȡ
//list����, ɾ���������, ��ѯ��, �ʺϽ϶�Ĳ���ɾ���������Ҳ����������ȡ
//deque������, ����������������ϵĲ�����, ����list��ѯ��, ��vector����ɾ����.��Ƶ������Ҫ���˲���ɾ������ѡ��.

//��������ѡ��
//�������νṹ, �ڲ��Ƕ�����(�����)�ṹʵ��. ���������������С���Һ���
//set��map��֤��Ԫ�ص�Ψһ��, multiset��multimap��չ����һ����.Ԫ��������ļ���Ĭ������.
//����Ҫ֪��һ��ֵ�Ƿ���ڵ�ʱ��ʹ��set�ٺ��ʲ���
//set�ڲ������������ʽ, �������vector, ���Һ�β������vector
//map��setһ���ڲ������������ʽ, ��������ŵ�, ���ṩ��(key) - ֵ(value)��Ӧ�Ĺ�ϵ

//����������ѡ��
//priority_queue���ȼ�����������Ҫ��������ʹ���, ����ֻ��vector, deque
//stack�Ƚ����, ��������һ��˳������, ����push_back, pop_back��back����
//queue�Ƚ��ȳ�, ������Ҫ��pop_front, ����ֻ��deque, list

// ��֧��������ʵĵ����� ������ʹ��algorithm
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void display(int v)
{
	cout << v << " ";
}

// ����ʹ��
void test()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	// *it ����<> �е�����
	// v.end ָ�����һ��Ԫ�ص���һλ��
	for (vector<int>::iterator it = v.begin(); it < v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	// �ص�����
	for_each(v.begin(), v.end(), display);
	cout << endl;
}

// ����Ƕ��
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