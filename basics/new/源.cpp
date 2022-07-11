//�ڶ��Ͻ���һ��������new�������ڴ���Ϊ������ù��캯����
//ֻ�����ڴ棬����operator new������������ù��캯����
//operator new�������غ�����ʹ��new��������new������������㶨�Ƶ�operator new��
//��һ���Ѿ����ָ����ڴ��ｨ��һ��������placement new�� (��Ҫ���newͷ�ļ�)
#include <iostream>
#include <string>
#include <new> // placement new

using namespace std;

// new operator
// �����ڴ� ���ù��캯����ʼ��
void test()
{
	string* str = new string("hello world");

	cout << *str << endl;

	delete str;
}

// operator new
// ���������ڴ�ĺ�����Ϊnew���������á��ܹ������أ������ƣ�
// ԭ�� void * operator new(size_t size);
void test2()
{
	//int* num = new int[sizeof(int)]; �������ǵȼ۵�
	int* num = (int *)operator new(sizeof(int));

	*num = 10;

	cout << *num << endl;

	delete num;
}

// placement new
// placement new�������operator new��������һ���ѷ��䵫δ�����δ��ʼ�����ڴ�
// �������Ѿ���ȡ���ڴ����½�һ�����󣬱����������ڴ�Ҫ��
void test3()
{
	int* arr = new int[99];
	// ��arr�ռ����½�һ��string����
	string* str = new(arr) string("hello world");

	cout << *str << endl;

	delete[] arr;
}

int main()
{
	test();
	test2();
	test3();

	return 0;
}