//map�ṩ�����һ��һ���ݴ�������.
//Ԫ������key��value��������ɵĶ���.key��Ψһ��.
//����һ��key, ����ȷ����Ե�value.
//mapҲ�й�������, ֻ�������ķ�ʽ��key��������.
//map��һ������Ĳ�����key�ظ�������, Ĭ��Ϊ����.
//multimap��һ�����������key�ظ�������, Ĭ��Ϊ����.
#include <iostream>
#include <string>
#include <map>

using namespace std;

void test()
{
	//����һ���յ�map
	map<int, string> m;

	//ֱ�Ӹ�ֵ
	map<int, string> m2 = {
		{1,"a"},
		{2,"b"},
		{3,"c"}
	};

	//���ƹ��캯��
	map<int, string> m3(m2);

	//ʹ�õ�������ֵ
	map<int, string> m4(m3.begin(), m3.end());

	//��ֵ���캯��
	m = m4;

	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
}

// ����Ԫ��
void test2()
{
	map<int, int> m;

	//���Զ���������
	map<int, int> m2{
		{ 4,44 },
		{ 1,11 },
		{ 3,33 },
		{ 2,22 },
		{ 5,55 },
	};

	//���յ�����λ�ò���,����ָ�����Ԫ�صĵ�����
	auto it = m.insert(m.begin(), pair<int, int>(6, 66));
	cout << it->first << " " << it->second << endl;
	cout << endl;

	//��֧���������
	//auto it = m.begin();
	//it + 3;    //error

	//����һ������������
	m.insert(m2.begin(), m2.end());
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;

	//ֱ�Ӳ��� value�����ظ�
	m.insert(make_pair(11, 11));

	//��Ч���� keyֵ�����ظ�
	m.insert(make_pair(1, 434));

	m.emplace(1, 1);

	//������ʹ��value_type
	//map<int, int>::key_type; //key
	//map<int, int>::mapped_type;	//value
	//map<int, int>::value_type;	//pair<int,int>
	m.insert(map<int, int>::value_type(9, 99));

	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
}

// ɾ��
void test3()
{
	map<int, int> m = {
			{1,11},
			{2,22},
			{3,33},
			{4,44},
			{5,55},
			{6,66},
			{7,22},
			{8,22},
			{9,22}
	};

	//��λ��ɾ��
	m.erase(m.begin());
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;

	//������������ɾ��
	auto it = m.begin();
	it++;
	it++;
	it++;
	m.erase(m.begin(), it);
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;

	//��keyɾ�� ��multimap����ɾ������key
	m.erase(5);
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;

	multimap<int, int> mm = {
		{1,11},
		{2,22},
		{3,33},
		{4,44},
		{5,55},
		{5,55},
		{5,55},
		{5,55},
		{5,55},
		{5,55},
		{6,66},
		{7,22},
		{8,22},
		{9,22}
	};
	mm.erase(5);
	for (auto it = mm.begin(); it != mm.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;

	//ɾ������Ԫ��
	m.clear();
}

class greaterThan
{
public:
	bool operator()(int val, int val2) const
	{
		return val > val2;
	}
};

void test4()
{
	map<int, int> m = {
		{1,11},
		{2,22},
		{3,33},
		{4,44},
		{6,66},
		{7,22},
		{8,22},
		{9,22},
		{11,111}
	};

	// ���� ���ص�����
	auto it = m.find(3);

	map<int, int> m2;

	//��ʼ������ ָ���һ��Ԫ��
	auto it_begin = m.begin();

	//ĩβ������ ָ�����һ��Ԫ�ص���һλ��
	auto it_end = m.end();

	//�����ʼ������ ָ�����һ��Ԫ��
	auto it_rbegin = m.rbegin();

	//�����β������ ָ���һ��Ԫ�ص���һλ��
	auto it_rend = m.rend();

	//�ж��Ƿ�Ϊ��
	if (m2.empty())
	{
		cout << "is empty" << endl;
	}

	//equal_range����һ����������������map������,��һ��ָ��key��ȵ�Ԫ��,�ڶ���ָ��key����һ��Ԫ��
	//���key�����ڷ��ص��� >key ������Ԫ��
	//���key�������һ��key,������
	//��ʵ������������ҵ� ��ȵ������� ���޿������ ���޲���
	//��˵�˻�����˼���� ��һ��ָ�� >=key �ڶ���ָ�� >key
	pair<map<int, int>::iterator, map<int, int>::iterator> ret = m.equal_range(6);
	cout << ret.first->first << " " << ret.first->second << endl;	//6 66
	cout << ret.second->first << " " << ret.second->second << endl;	//7 22
	cout << endl;

	//lower_bound �����ϵ���Ǻ�equal_range ��һ��Ԫ��һ��
	auto it = m.lower_bound(6);
	cout << it->first << " " << it->second << endl << endl;	//6 66

	//upper_bound �����ϵ���Ǻ�equal_range �ڶ���Ԫ��һ��
	auto it2 = m.upper_bound(6);
	cout << it2->first << " " << it2->second << endl << endl;	//7 22

	//�Ƚ�����key 
	map<int, int>::key_compare mkcomp = m.key_comp();
	if (mkcomp(2, 4))
	{
		cout << "2 less than 4" << endl;
	}
	cout << endl;

	//�Ƚ�����Ԫ��(����pair)
	map<int, int>::value_compare mvcomp = m.value_comp();
	auto pval = m.begin();
	auto it_pair = m.begin();
	it_pair++;
	it_pair++;
	it_pair++;
	auto &pval2 = it_pair;
	if (mvcomp(*pval, *pval2))
	{
		cout << "pval less than pval2" << endl;
	}
	cout << endl;

	//�ı�����ʽ
	map<int, int, greaterThan> m3 = {
		{1,11},
		{2,22},
		{3,33},
		{4,44},
		{6,66},
		{7,22},
		{8,22},
		{9,22},
		{11,111}
	};

	map<int, int, greaterThan>::key_compare mcomp2 = m3.key_comp();
	if (mcomp2(5, 2))
	{
		cout << "5 greater than 2" << endl;
	}
	cout << endl;

	//�������Ԫ�ظ���
	cout << m.max_size() << endl << endl;

	//��ǰԪ�ظ���
	cout << m.size() << endl << endl;

	//��������map
	map<int, int> m4 = {
		{4,2},
		{3,1},
		{5,6}
	};
	m4.swap(m);
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
	cout << endl;

	for (auto it = m4.begin(); it != m4.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	test3();

	return 0;
}
