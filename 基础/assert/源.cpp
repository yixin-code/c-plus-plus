//assert���ԭ�Ͷ�����<assert.h>�У����������ȼ�����ʽexpression��ֵΪ��(��Ϊ0), ��ô��������stderr��ӡһ��������Ϣ��Ȼ��ͨ������abort����ֹ����
#include <iostream>
#include <assert.h>

using namespace std;

int main()
{
	int  i;
	i = 1; // ���iΪ0 ����
	assert(i++); 
	cout << i++ << endl;
	return 0;
}