//������� C++ String ���ڴ��еĲ��֣�
//����	X86(�ֽ���)	X64���ֽ�����
//Allocator	4	8
//ԭʼ�ַ��� Data λ��(С��15���ַ�������ջ�ϣ����ڿ����ڶ���)	15 + 1  ������15���ַ���һ����������\0��	15 + 1  ������15���ַ���һ����������\0��
//�ַ����� Size	4	8
//��ǰ���� Capacity	4	8
//�ܼ�	28	40
#include <iostream>

using namespace std;

int main()
{
	string str;
	cout << sizeof(str) << endl; // 40
	cout << sizeof(string) << endl; // 40

	return 0;
}