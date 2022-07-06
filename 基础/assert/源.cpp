//assert宏的原型定义在<assert.h>中，其作用是先计算表达式expression的值为假(即为0), 那么它就先向stderr打印一条出错信息，然后通过条用abort来终止程序；
#include <iostream>
#include <assert.h>

using namespace std;

int main()
{
	int  i;
	i = 1; // 如果i为0 错误
	assert(i++); 
	cout << i++ << endl;
	return 0;
}