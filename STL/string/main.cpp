#include <iostream>
#include <string>

using namespace std;

// ���캯��
void test()
{
	string str = "hello";
	cout << str << endl;	//hello

	string str2("hello");
	cout << str2 << endl;	//hello

	string str3(5, 'a');
	cout << str3 << endl;	//aaaaa 5��a

	string str4("hello world", 5);
	cout << str4 << endl;	//hello	��"hello world"��ȡǰ5

	string str5("hello world", 6, 5);
	cout << str5 << endl;	//world	�ӵ�6����ʼȡ5��

	// ������
	string str6(str.begin(), str.end());
	cout << str6 << endl;	//hello

	//���������
	string str7(str.rbegin(), str.rend());
	cout << str7 << endl;	//olleh
}

// ׷��
void test2()
{
	string str = "abc";

	str.append("de");
	cout << str << endl;	//abcde

	str.append("abcdefghijkl", 5, 2);
	cout << str << endl;	//abcdefg	�ӵ�5����ʼ��ȡ2��

	str.append("hijklm", 2);
	cout << str << endl;	//abcdefghi	��ȡ2��

	str.append(10, 'x');
	cout << str << endl;	//abcdefghixxxxxxxxxx ׷��10��x

	//������׷��
	str.append(str.begin(), str.end());
	cout << str << endl;	//abcdefghixxxxxxxxxxabcdefghixxxxxxxxxx
}

// ���·���
void test3()
{
	string str = "abc";

	str.assign("asd");
	cout << str << endl;	//asd

	str.assign("asdfgh", 3);
	cout << str << endl;	//asd ȡ3��

	str.assign("qwerasdgh", 4, 3);
	cout << str << endl;	//asd �ӵ�4����ʼȡ3��

	str.assign(10, 'a');
	cout << str << endl;	//aaaaaaaaaa	10��a
}

// �ռ��С
void test4()
{
	string str = "asd";

	//�ַ������ַ�,�ַ�����
	cout << str.size() << endl;	//3
	cout << str.length() << endl;	//3	�������ǵȼ۵�

	//�ַ����ռ��С
	cout << str.capacity() << endl;	//15(��С��size�Ĵ�С)

	//�ı��ַ�������(�¿ռ䳤�Ⱦ������ݲ�ȷ��)
	str.resize(10);
	cout << str << endl;	//abcdefg
	cout << str.size() << endl;	//10
	cout << str.capacity() << endl;	//15

	//�¿ռ��������ַ�
	str.resize(20, 'a');
	cout << str << endl;	//asd       aaaaaaaaaa	7���ո�
	cout << str.size() << endl;	//20
	cout << str.capacity() << endl;	//31

	//�ı�ռ�
	str.reserve(40);
	cout << str.capacity() << endl;	//47

	//�ַ����ܱ��������ַ���
	cout << str.max_size() << endl;
}

// charתstring
void test5()
{
	string str = "hello world";

	//stringתchar*
	const char* cstr = str.c_str();
	cout << cstr << endl;	//hello world
	const char* cstr2 = str.data();
	cout << cstr2 << endl;	//hello world

	//stringתchar����	ʵ�����ǿ���
	char str3[20] = "abcde";
	str.copy(str3, str.size());
	cout << str3 << endl;	//hello world

	str.copy(str3, 5, 6);
	cout << str3 << endl;	//world	world	ȡ5���ַ��ӵ�6����ʼ ����Ŀռ䲻�ᷢ���ı�
}

// ����
void test6()
{
	string str = "asd";

	str.insert(str.begin(), '0');
	cout << str << endl;	//0asd	�ڵ�����ǰ����һ���ַ�

	str.insert(2, "111");
	cout << str << endl;	//0a111sd �ڵ�2���ַ������һ���ַ���

	str.insert(6, "123456", 3, 2);
	cout << str << endl;	//0a111s45d	��str�ĵ�6���ַ��� �����ַ�����3���ַ����2�ַ�

	str.insert(5, "222", 2);
	cout << str << endl;	//0a11122s45d	�ڵ�5���ַ�������ַ�����ǰ�����ַ�

	str.insert(7, 2, '3');
	cout << str << endl;	//0a1112233s45d	�ڵ�7���ַ������2���ַ�

	str.insert(str.begin(), 2, '6');
	cout << str << endl;	//660a1112233s45d �ڵ�����ǰ���������ַ�

	str.insert(str.begin(), str.begin(), str.end());
	cout << str << endl;	//660a1112233s45d660a1112233s45d �ӵ�����ǰ���� �ӵ�������ʼ ������������
}

// ɾ��
void test7()
{
	string str = "1234567890aaaaaaa";

	str.erase(str.begin());
	cout << str << endl;	//234567890aaaaaaa	ɾ����ǰ������λ���ַ�,������һ�ַ�������

	str.erase(str.begin(), str.begin() + 5);
	cout << str << endl;	//7890aaaaaaa ɾ�������������ַ�

	str.erase(4, 3);
	cout << str << endl;	//7890aaaa	�ӵ�4���ַ���ʼɾ��3���ַ�

	str.erase(4);
	cout << str << endl;	//7890	�ӵ�4���ַ���ʼȫ��ɾ��

	str.erase();
	cout << "-" << str << "-" << endl;	//--	ȫ��ɾ��
}

// ���� find
void test8()
{
	string str = "111 222 333 222 111";

	unsigned int pos = str.find("222", 7);
	if (pos != string::npos)
	{
		cout << pos << endl;	//12 �ӵ�7���ַ���ʼ�����ַ��� ���ص��ǵ�һ�γ���λ�õ��±� ���û���ҵ�����string::npos
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find("111 15544", 0, 3);
	if (pos != string::npos)
	{
		cout << pos << endl;	//0 �ӵ�0���ַ���ʼ�����ַ�����ǰ3���ַ�,��һ�γ��ֵ�λ��
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find('2', 0);
	if (pos != string::npos)
	{
		cout << pos << endl;	//4 �ӵ�0���ַ���ʼ�����ַ�,��һ�γ��ֵ�λ��
	}
	else
	{
		cout << "not find" << endl;
	}

	//�������
	pos = str.rfind("222", 7);
	if (pos != string::npos)
	{
		cout << pos << endl;	//4 �ӵ�7���ַ���ʼ�����ַ��� ���ص������һ�γ���λ�õ��±� ���û���ҵ�����string::npos
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.rfind("111 15544", 19, 3);
	if (pos != string::npos)
	{
		cout << pos << endl;	//16 �ӵ�0���ַ���ʼ�����ַ�����ǰ3���ַ�,���һ�γ��ֵ�λ��
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.rfind('2', 4);
	if (pos != string::npos)
	{
		cout << pos << endl;	//4 �ӵ�5���ַ���ʼ�����ַ�,���һ�γ��ֵ�λ��
	}
	else
	{
		cout << "not find" << endl;
	}
}

// ���ҵ�һ�γ��ֵ�λ�� find_first_of(
void test9()
{
	//���ҵ�һ��ƥ����ַ�
	string str = "1234567890";

	unsigned int pos = str.find_first_of("6864", 3);
	if (pos != string::npos)
	{
		cout << pos << endl;	//3	�ӵ�3���ַ���ʼ���ҷ��ص�һ��ƥ���ַ���λ��
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_first_of("792811", 0, 4);
	if (pos != string::npos)
	{
		cout << pos << endl;	//1	�ӵ�0���ַ���ʼ���ҷ��ص�һ��ƥ���ַ���λ��,�������4���ַ�
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_first_of('5', 0);
	if (pos != string::npos)
	{
		cout << pos << endl;	//4	�ӵ�0���ַ���ʼ���ҷ��ص�һ��ƥ���ַ���λ��
	}
	else
	{
		cout << "not find" << endl;
	}

	//���ҵ�һ�β�ƥ����ַ�
	pos = str.find_first_not_of("6864", 3);
	if (pos != string::npos)
	{
		cout << pos << endl;	//4	�ӵ�3���ַ���ʼ���ҷ��ص�һ�β�ƥ���ַ���λ��
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_first_not_of("792811", 0, 4);
	if (pos != string::npos)
	{
		cout << pos << endl;	//0	�ӵ�0���ַ���ʼ���ҷ��ص�һ�β�ƥ���ַ���λ��,�������4���ַ�
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_first_not_of('1', 0);
	if (pos != string::npos)
	{
		cout << pos << endl;	//1	�ӵ�0���ַ���ʼ���ҷ��ص�һ�β�ƥ���ַ���λ��
	}
	else
	{
		cout << "not find" << endl;
	}
}

// �������һ��ƥ��
void test10()
{
	//find_last_not_of(���ַ����в���, ���һ��ƥ����ַ�)
	string str = "1234567890";

	unsigned int pos = str.find_last_of("47896", 7);
	if (pos != string::npos)
	{
		cout << pos << endl;	//7	�ӵ�7���ַ���ʼ���ҷ��ص�һ��ƥ���ַ���λ�� �Ӻ���ǰ����(���ҵ���7��������)
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_last_of("1264", 5, 4);
	if (pos != string::npos)
	{
		cout << pos << endl;	//5	�ӵ�5���ַ���ʼ���ҷ��ص�һ��ƥ���ַ���λ��,����5���ַ� �Ӻ���ǰ����
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_last_of('1', 7);
	if (pos != string::npos)
	{
		cout << pos << endl;	//0	�ӵ�7���ַ���ʼ���ҷ��ص�һ��ƥ���ַ���λ�� �Ӻ���ǰ����
	}
	else
	{
		cout << "not find" << endl;
	}


	//find_last_not_of(���ַ����в���, ���һ�β�ƥ����ַ�)
	pos = str.find_last_not_of("47896", 7);
	if (pos != string::npos)
	{
		cout << pos << endl;	//4	�ӵ�7���ַ���ʼ���ҷ��ص�һ�β�ƥ���ַ���λ�� �Ӻ���ǰ����(���ҵ���7��������)
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_last_not_of("1264", 5, 4);
	if (pos != string::npos)
	{
		cout << pos << endl;	//4	�ӵ�5���ַ���ʼ���ҷ��ص�һ�β�ƥ���ַ���λ��,����5���ַ� �Ӻ���ǰ����
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_last_not_of('1', 7);
	if (pos != string::npos)
	{
		cout << pos << endl;	//7	�ӵ�7���ַ���ʼ���ҷ��ص�һ�β�ƥ���ַ���λ�� �Ӻ���ǰ����
	}
	else
	{
		cout << "not find" << endl;
	}
}

// ��ȡ
void test11()
{
	string str = "123456789";

	cout << str.substr(4, 3) << endl;	//567	�ӵ�4���ַ���ʼ��ȡ3��
	cout << str.substr(4) << endl;
}

// �滻
void test12()
{
	string str = "1234567890";
	cout << str.replace(1, 2, "2233") << endl;	//122334567890	�ӵ�1���ַ���ʼ�滻2���ַ��滻���ַ���

	//1223334444567890	�ӵ�4���ַ���ʼ�滻1���ַ�,�滻���ַ����ӵ�0���ַ���ʼ����5��
	cout << str.replace(4, 1, "3344444", 0, 5) << endl;

	//12233344445555567890	�ӵ�10���ַ���ʼ�ͻ�1���ַ�,�滻������ַ�
	cout << str.replace(10, 1, 5, '5') << endl;

	//hello world	�ӵ�������ʼ�������滻���ַ���
	cout << str.replace(str.begin(), str.end(), "hello world") << endl;

	//hello	�ӵ�������ʼ�������滻���ַ����е�ǰ����ַ�
	cout << str.replace(str.begin(), str.end(), "hello world", 5) << endl;

	//hello	�ӵ�������ʼ�������滻������ַ�
	cout << str.replace(str.begin(), str.end(), 5, 'a') << endl;
}

// �����пձȽ�
void test13()
{
	string str = "";
	if (str.empty())
	{
		cout << "str is empty" << endl;
	}

	string str2 = "12345";
	string str3 = "abcde";

	cout << str2 << " " << str3 << endl;

	str2.swap(str3);

	cout << str2 << " " << str3 << endl;

	if (str2.compare(str3) == 0)
	{
		cout << "str2 == str3" << endl;
	}
	else if(str2.compare(str3) > 0)
	{
		cout << "str2 > str3" << endl;
	}
	else
	{
		cout << "str2 < str3" << endl;
	}
}

void test14()
{
	string str = "sjfljsdklj";
	cout << str.at(111) << endl; // �����쳣
}

// �������ȡ��
void test15()
{
	string str = "yixincode@163.com";
	int pos = str.find('@');
	if (pos == string::npos)
	{
		cout << "not find" << endl;
	}
	else
	{
		string str2 = str.substr(0, pos);
		cout << str2 << endl;
	}
}

// ��Сдת��
void test16()
{
	string str = "sdklfjasdk";
	int len = str.size();

	// Сдת��д
	for (int i = 0; i < len; ++i)
	{
		//str[i] = str[i] - 32;
		str[i] = toupper(str[i]);
	}
	cout << str << endl;

	// ��дתСд
	for (int i = 0; i < len; ++i)
	{
		//str[i] = str[i] + 32;
		str[i] = tolower(str[i]);
	}
	cout << str << endl;
}

int main(int argc, char** argv)
{
	//test11();
	//test15();
	test16();

	return 0;
}