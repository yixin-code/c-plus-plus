//set�Ǽ��ļ���, ����Ҫ֪��һ��ֵ�Ƿ���ڵ�ʱ��ʹ��set�ٺ��ʲ���.
//set���ܽ����±����.
//set��Ψһ�ڵ�ֵ��Ψһ��, multiset�е�ֵ���Բ�Ψһ
#include <iostream>
#include <set>

using namespace std;

bool funcComp(int val, int val2)
{
	return val > val2;
}

class Comp
{
public:
	bool operator()(const int val, const int val2)const
	{
		return val > val2;
	}
};

// ����
void test()
{
	//�޲ι��캯��
	set<int> s;

	//���鷶Χ�вι���
	int arr[] = { 1,2,3,4,5,6 };
	set<int> s2(arr, arr + 6);

	//���ƹ���
	set<int> s3(s2);

	//�������вι���
	set<int> s4(s3.begin(), s3.end());

	//�ı����������,Ĭ������
	//ֱ�Ӹ�ֵ
	//C++ ��������ȫ���C�����⣬ ��C++�������ʵʵ����C++�Ķ���
	set<int, Comp> s5 = { 1,2,3,4,5,6 };
	bool(*p)(int, int) = funcComp;
	set<int, bool(*)(int, int)> s6(p); // ��Ҫ������
	s6 = { 1,2,3,4,5,6,7,8,9 };

	for (auto it = s6.begin(); it != s6.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// ����Ԫ��
void test2()
{
	set<int> s;
	set<int> s2 = { 5,32,45,324,543,5,435,4325 };

	//����һ��Ԫ�ط���ָ�����Ԫ�صĵ�����
	auto ret = s.insert(s.begin(), 9);
	cout << *ret << endl << endl;	//9

	//����һ��Ԫ�ط���һ������,��һ��Ԫ��Ϊָ�����Ԫ�صĵ�����,�ڶ���Ԫ����boolֵ�ж��Ƿ����ɹ�
	auto ret2 = s.insert(7);
	cout << *ret2.first << " " << ret2.second << endl << endl;	//7 1

	//����һ������������,�޷���ֵ
	s.insert(s2.begin(), s2.end());

	//C++11  ����Ч�ʸ���
	//����һ��Ԫ�ط���һ������,��һ��Ԫ��Ϊָ�����Ԫ�صĵ�����,�ڶ���Ԫ����boolֵ�ж��Ƿ����ɹ�
	auto ret3 = s.emplace(2);
	cout << *ret3.first << " " << ret3.second << endl << endl;	//2 1

	//C++11 ����һ��Ԫ�ط���ָ�����Ԫ�صĵ�����
	auto ret4 = s.emplace_hint(s.begin(), 6);
	cout << *ret4 << endl << endl;	//6
}

// ɾ�� 
void test3()
{
	set<int> s = { 3,4,5,1,23,5,325,5,6,32,1,1,434,4 };
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//��������λ��ɾ��
	//auto it = s.begin();
	//it + 3;	//��֧��������� Ҳ��֧���±����
	//s[4];	
	s.erase(s.begin());

	//������������ɾ��
	auto it = s.begin();
	++it;
	++it;
	++it;
	s.erase(s.begin(), it);

	//��keyɾ�� ɾ�����з��ϵ�Ԫ��,����ɾ����Ԫ�ظ���(set�в����ظ�key����ֻ�ܷ���1��0)
	auto i = s.erase(1);
	cout << i << endl << endl;

	for (auto it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//���Ԫ��
	s.clear();
}

// ����
void test4()
{
	set<int> s = { 4,2,1,5,6,8,9 };

	//����,�ҵ�����ָ�����Ԫ�صĵ�����,û���ҵ����ؽ���������
	auto it = s.find(5);
	if (it != s.end())
	{
		//*it = 10;	//error
		cout << *it << endl << endl;	//5
	}

	multiset<int> ms = { 1,2,3,4,2,3,2,3,5,65,5,5,5,5,5 };
	auto it2 = ms.find(5);
	if (it2 != ms.end())
	{
		//*it2 = 10;	//error
		cout << *it2 << endl << endl;	//5
	}

	// û���ҵ����ؽ���������
	//���� >= �� > ����Ԫ�صĵ����� һ������(������û��3)
	auto ret = s.equal_range(3);
	cout << *ret.first << " " << *ret.second << endl;	//4 4
	ret = s.equal_range(4);
	cout << *ret.first << " " << *ret.second << endl << endl;	//4 5

	//���� >= Ԫ�صĵ�����
	auto ret2 = s.lower_bound(3);
	cout << *ret2 << endl; //4
	ret2 = s.lower_bound(4);
	cout << *ret2 << endl << endl; //4

	//���� > Ԫ�صĵ�����
	auto ret3 = s.upper_bound(3);
	cout << *ret3 << endl; //4
	ret3 = s.upper_bound(4);
	cout << *ret3 << endl << endl; //5
}

void test5()
{
	set<int> s;

	//�ж�set�Ƿ�Ϊ��
	if (s.empty())
	{
		cout << "is empty" << endl << endl;
	}

	//����һ��Ԫ�ص�Ԫ�ظ���
	s = { 1,2,4,5,6,3 };
	multiset<int> s2 = { 1,1,2,2,3,3,4,4,5,5 };
	cout << s.count(7) << endl;	//0
	cout << s.count(5) << endl << endl;	//1

	cout << s2.count(7) << endl;	//0
	cout << s2.count(5) << endl << endl;	//2

	//�������Ԫ������
	cout << s2.max_size() << endl;

	//���ص�ǰԪ�ظ���
	cout << s2.size() << endl;	//6

	//��������set
	set<int> s3 = { 1,2,3 };
	s3.swap(s);
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl << endl;

	for (auto it = s3.begin(); it != s3.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl << endl;

	//Ԫ�ؼ���бȽ�Ĭ������
	set<int> s4 = { 34,24,643,14 };
	cout << s4.key_comp()(1, 2) << endl;	//1
	cout << s4.key_comp()(14, 34) << endl;	//1
	cout << s4.key_comp()(2, 1) << endl;	//0

	cout << s4.value_comp()(1, 2) << endl;	//1
	cout << s4.value_comp()(14, 24) << endl;	//1
	cout << s4.value_comp()(34, 14) << endl;	//0
}

int main()
{


	return 0;
}
