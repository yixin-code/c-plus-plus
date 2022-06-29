#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// ���캯��
void test()
{
	//����һ��int��������
	vector<int> v_int;
	//����һ��int��������,������һ�������ʼ��(��������)
	vector<int> v_int2(v_int);
	cout << v_int.size() << endl;	//0 vector��Ԫ��������С

	//����һ��double��������,��ʼ����СΪ11,����ֵ
	vector<double> v_double(11);
	cout << v_double.size() << endl;	//11

	//����һ��double��������,��ʼ����СΪ11,ֵΪ11.11(����11��11.11)
	vector<double> v_double2(11, 11.11);
	//����
	for (int i = 0; i < v_double2.size(); ++i)
	{
		cout << v_double2[i] << " ";	//11��11.11
	}
	cout << endl;

	//����һ��double��������,��ʼ��Ϊ3��11.11
	vector<double> v_double3(v_double2.begin(), v_double2.begin() + 2);
	for (int i = 0; i < v_double3.size(); ++i)
	{
		cout << v_double3[i] << " ";	//2��11.11
	}
	cout << endl;

	//��Ȼ���������ʼ��Ҳ����
	int arr[] = { 1,2,3,4,5 };
	vector<int> v_int3(arr, arr + 5);
	for (int i = 0; i < v_int3.size(); ++i)
	{
		cout << v_int3[i] << " ";	//1 2 3 4 5 
	}
	cout << endl;
}

// ���� ɾ�� �޸�Ԫ�ظ��� ���
void test2()
{
	vector<int> v_int;

	//�ڿ�ʼ������������1
	v_int.insert(v_int.begin(), 1);

	//�ڿ�ʼ��������һλ�ò���2��2
	v_int.insert(v_int.begin() + 1, 2, 2);

	int arr[] = { 3,3,3 };
	vector<int> v_int2(arr, arr + 3);
	//�ڵ���������ƶ�����λ�ò���3��3(��ʵ������vector������λ�ú����)
	//�����������䶼������ҿ�
	v_int.insert(v_int.begin() + 3, v_int2.begin(), v_int2.end());

	//β������
	v_int.push_back(4);
	v_int.push_back(4);
	v_int.push_back(4);
	v_int.push_back(4);

	//����������
	for (vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it)
	{
		cout << *it << " ";	//1223334444
	}
	cout << endl;

	//�ı�Ԫ�ظ���
	v_int.resize(6);
	for (vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it)
	{
		cout << *it << " ";	//122333
	}
	cout << endl;

	//�ı�Ԫ�ظ���,���ӵ���Ԫ�س�ʼ��Ϊ4
	v_int.resize(10, 4);
	for (vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it)
	{
		cout << *it << " ";	//1223334444
	}
	cout << endl;

	//βɾ ɾ��4��4
	v_int.pop_back();
	v_int.pop_back();
	v_int.pop_back();
	v_int.pop_back();
	for (vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it)
	{
		cout << *it << " ";	//122333
	}
	cout << endl;

	//ָ��������ɾ��
	v_int.erase(v_int.begin() + 5);	//ɾ���������һ��3
	for (vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it)
	{
		cout << *it << " ";	//12233
	}
	cout << endl;

	//ָ������������ɾ��
	v_int.erase(v_int.begin() + 1, v_int.end());
	for (vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it)
	{
		cout << *it << " ";	//1
	}
	cout << endl;

	//ɾ������Ԫ��
	v_int.clear();
	for (vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it)
	{
		cout << *it << " ";	//1
	}
	cout << endl;
}

// ����swap�޸�������С
void test3()
{
	vector<int> v(1111);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(3);

	// ��v��ʼ���������� Ȼ�󽻻��� ��ʼ����ʱ���ʹ��size������capacity
	vector<int>(v).swap(v);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

// ��С,����,�п�,������,������������,��������������
void test4()
{
	vector<int> v;
	v.size();            //Ԫ�ظ���
	v.max_size();        //���ܴ洢���Ԫ�ظ���
	v.resize(1);          //�ı�Ԫ�ظ���

	v.capacity();        //������Ԫ�ص�����
	v.reserve(1);         //�ı�����Ԫ�ص�����

	v.empty();           //�ж������Ƿ�Ϊ��

	//����һ��int���͵�vector������ָ������v��ʼλ��
	vector<int>::iterator it = v.begin();

	vector<int> v2;
	v.swap(v2);           //��������Ԫ��

	//��vector��������,��Ҫ����ͷ�ļ�algorithm
	sort(v.begin(), v.end());
}

// Ƕ��
void test5()
{
	//vector<int>(3,1) ������������� 
	//�����൱��int[2][3] ȫ����ʼ��Ϊ1
	vector<vector<int>> v(2, vector<int>(3, 1));

	//���� 
	//auto it = v.begin();
	vector<vector<int>>::iterator it = v.begin();
	//*it ���������<>��Ķ���

	cout << v.size() << endl;	//2
	cout << it->size() << endl;	//3

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < it->size(); ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(2);

	v.push_back(v2);

	it = v.begin();

	cout << v.size() << endl;	//3
	cout << it->size() << endl;	//3

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < it->size(); ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	//���������߼��ṹ,�����װ��Լ�����,������������v2�в��˺ö����ݵ�����ʾ��ֻ������(��Ϊ�������޶�������)
	//Ҫ�޸Ŀ���ʹ��resize
	//һ����Ҫ�õ�ʱ��Ҳ����ֱ��vector<vector<int>> v; ����ʹ��
	//Ȼ��������һ��vector��������,Ȼ��������뵽��ά��
	//������ʱ���õ�һ��������ȡֵ,�������±�Ϳ�����
	//�ⶫ����������ʵ����ָ����
}

int main()
{
	test3();

	return 0;
}