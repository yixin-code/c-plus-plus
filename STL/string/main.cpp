#include <iostream>
#include <string>

using namespace std;

// 构造函数
void test()
{
	string str = "hello";
	cout << str << endl;	//hello

	string str2("hello");
	cout << str2 << endl;	//hello

	string str3(5, 'a');
	cout << str3 << endl;	//aaaaa 5个a

	string str4("hello world", 5);
	cout << str4 << endl;	//hello	从"hello world"中取前5

	string str5("hello world", 6, 5);
	cout << str5 << endl;	//world	从第6个开始取5个

	// 迭代器
	string str6(str.begin(), str.end());
	cout << str6 << endl;	//hello

	//逆向迭代器
	string str7(str.rbegin(), str.rend());
	cout << str7 << endl;	//olleh
}

// 追加
void test2()
{
	string str = "abc";

	str.append("de");
	cout << str << endl;	//abcde

	str.append("abcdefghijkl", 5, 2);
	cout << str << endl;	//abcdefg	从第5个开始截取2个

	str.append("hijklm", 2);
	cout << str << endl;	//abcdefghi	截取2个

	str.append(10, 'x');
	cout << str << endl;	//abcdefghixxxxxxxxxx 追加10个x

	//迭代器追加
	str.append(str.begin(), str.end());
	cout << str << endl;	//abcdefghixxxxxxxxxxabcdefghixxxxxxxxxx
}

// 重新分配
void test3()
{
	string str = "abc";

	str.assign("asd");
	cout << str << endl;	//asd

	str.assign("asdfgh", 3);
	cout << str << endl;	//asd 取3个

	str.assign("qwerasdgh", 4, 3);
	cout << str << endl;	//asd 从第4个开始取3个

	str.assign(10, 'a');
	cout << str << endl;	//aaaaaaaaaa	10个a
}

// 空间大小
void test4()
{
	string str = "asd";

	//字符串中字符,字符数量
	cout << str.size() << endl;	//3
	cout << str.length() << endl;	//3	这两个是等价的

	//字符串空间大小
	cout << str.capacity() << endl;	//15(不小于size的大小)

	//改变字符串长度(新空间长度具体内容不确定)
	str.resize(10);
	cout << str << endl;	//abcdefg
	cout << str.size() << endl;	//10
	cout << str.capacity() << endl;	//15

	//新空间可以填充字符
	str.resize(20, 'a');
	cout << str << endl;	//asd       aaaaaaaaaa	7个空格
	cout << str.size() << endl;	//20
	cout << str.capacity() << endl;	//31

	//改变空间
	str.reserve(40);
	cout << str.capacity() << endl;	//47

	//字符串能保存的最大字符数
	cout << str.max_size() << endl;
}

// char转string
void test5()
{
	string str = "hello world";

	//string转char*
	const char* cstr = str.c_str();
	cout << cstr << endl;	//hello world
	const char* cstr2 = str.data();
	cout << cstr2 << endl;	//hello world

	//string转char数组	实际上是拷贝
	char str3[20] = "abcde";
	str.copy(str3, str.size());
	cout << str3 << endl;	//hello world

	str.copy(str3, 5, 6);
	cout << str3 << endl;	//world	world	取5个字符从第6个开始 后面的空间不会发生改变
}

// 插入
void test6()
{
	string str = "asd";

	str.insert(str.begin(), '0');
	cout << str << endl;	//0asd	在迭代器前插入一个字符

	str.insert(2, "111");
	cout << str << endl;	//0a111sd 在第2个字符后插入一个字符串

	str.insert(6, "123456", 3, 2);
	cout << str << endl;	//0a111s45d	在str的第6个字符后 插入字符串第3个字符后的2字符

	str.insert(5, "222", 2);
	cout << str << endl;	//0a11122s45d	在第5个字符后插入字符串的前两个字符

	str.insert(7, 2, '3');
	cout << str << endl;	//0a1112233s45d	在第7个字符后插入2个字符

	str.insert(str.begin(), 2, '6');
	cout << str << endl;	//660a1112233s45d 在迭代器前插入两个字符

	str.insert(str.begin(), str.begin(), str.end());
	cout << str << endl;	//660a1112233s45d660a1112233s45d 从迭代器前插入 从迭代器开始 到迭代器结束
}

// 删除
void test7()
{
	string str = "1234567890aaaaaaa";

	str.erase(str.begin());
	cout << str << endl;	//234567890aaaaaaa	删除当前迭代器位置字符,返回下一字符迭代器

	str.erase(str.begin(), str.begin() + 5);
	cout << str << endl;	//7890aaaaaaa 删除迭代器区间字符

	str.erase(4, 3);
	cout << str << endl;	//7890aaaa	从第4个字符后开始删除3个字符

	str.erase(4);
	cout << str << endl;	//7890	从第4个字符开始全部删除

	str.erase();
	cout << "-" << str << "-" << endl;	//--	全部删除
}

// 查找 find
void test8()
{
	string str = "111 222 333 222 111";

	unsigned int pos = str.find("222", 7);
	if (pos != string::npos)
	{
		cout << pos << endl;	//12 从第7个字符开始查找字符串 返回的是第一次出现位置的下标 如果没有找到返回string::npos
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find("111 15544", 0, 3);
	if (pos != string::npos)
	{
		cout << pos << endl;	//0 从第0个字符开始查找字符串的前3个字符,第一次出现的位置
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find('2', 0);
	if (pos != string::npos)
	{
		cout << pos << endl;	//4 从第0个字符开始查找字符,第一次出现的位置
	}
	else
	{
		cout << "not find" << endl;
	}

	//逆向查找
	pos = str.rfind("222", 7);
	if (pos != string::npos)
	{
		cout << pos << endl;	//4 从第7个字符开始查找字符串 返回的是最后一次出现位置的下标 如果没有找到返回string::npos
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.rfind("111 15544", 19, 3);
	if (pos != string::npos)
	{
		cout << pos << endl;	//16 从第0个字符开始查找字符串的前3个字符,最后一次出现的位置
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.rfind('2', 4);
	if (pos != string::npos)
	{
		cout << pos << endl;	//4 从第5个字符开始查找字符,最后一次出现的位置
	}
	else
	{
		cout << "not find" << endl;
	}
}

// 查找第一次出现的位置 find_first_of(
void test9()
{
	//查找第一次匹配的字符
	string str = "1234567890";

	unsigned int pos = str.find_first_of("6864", 3);
	if (pos != string::npos)
	{
		cout << pos << endl;	//3	从第3个字符开始查找返回第一次匹配字符的位置
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_first_of("792811", 0, 4);
	if (pos != string::npos)
	{
		cout << pos << endl;	//1	从第0个字符开始查找返回第一次匹配字符的位置,最多搜索4个字符
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_first_of('5', 0);
	if (pos != string::npos)
	{
		cout << pos << endl;	//4	从第0个字符开始查找返回第一次匹配字符的位置
	}
	else
	{
		cout << "not find" << endl;
	}

	//查找第一次不匹配的字符
	pos = str.find_first_not_of("6864", 3);
	if (pos != string::npos)
	{
		cout << pos << endl;	//4	从第3个字符开始查找返回第一次不匹配字符的位置
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_first_not_of("792811", 0, 4);
	if (pos != string::npos)
	{
		cout << pos << endl;	//0	从第0个字符开始查找返回第一次不匹配字符的位置,最多搜索4个字符
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_first_not_of('1', 0);
	if (pos != string::npos)
	{
		cout << pos << endl;	//1	从第0个字符开始查找返回第一次不匹配字符的位置
	}
	else
	{
		cout << "not find" << endl;
	}
}

// 查找最后一次匹配
void test10()
{
	//find_last_not_of(在字符串中查找, 最后一次匹配的字符)
	string str = "1234567890";

	unsigned int pos = str.find_last_of("47896", 7);
	if (pos != string::npos)
	{
		cout << pos << endl;	//7	从第7个字符开始查找返回第一次匹配字符的位置 从后向前查找(查找到第7个正方向)
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_last_of("1264", 5, 4);
	if (pos != string::npos)
	{
		cout << pos << endl;	//5	从第5个字符开始查找返回第一次匹配字符的位置,搜索5个字符 从后向前查找
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_last_of('1', 7);
	if (pos != string::npos)
	{
		cout << pos << endl;	//0	从第7个字符开始查找返回第一次匹配字符的位置 从后向前查找
	}
	else
	{
		cout << "not find" << endl;
	}


	//find_last_not_of(在字符串中查找, 最后一次不匹配的字符)
	pos = str.find_last_not_of("47896", 7);
	if (pos != string::npos)
	{
		cout << pos << endl;	//4	从第7个字符开始查找返回第一次不匹配字符的位置 从后向前查找(查找到第7个正方向)
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_last_not_of("1264", 5, 4);
	if (pos != string::npos)
	{
		cout << pos << endl;	//4	从第5个字符开始查找返回第一次不匹配字符的位置,搜索5个字符 从后向前查找
	}
	else
	{
		cout << "not find" << endl;
	}

	pos = str.find_last_not_of('1', 7);
	if (pos != string::npos)
	{
		cout << pos << endl;	//7	从第7个字符开始查找返回第一次不匹配字符的位置 从后向前查找
	}
	else
	{
		cout << "not find" << endl;
	}
}

// 截取
void test11()
{
	string str = "123456789";

	cout << str.substr(4, 3) << endl;	//567	从第4个字符开始节取3个
	cout << str.substr(4) << endl;
}

// 替换
void test12()
{
	string str = "1234567890";
	cout << str.replace(1, 2, "2233") << endl;	//122334567890	从第1个字符开始替换2个字符替换成字符串

	//1223334444567890	从第4个字符开始替换1个字符,替换成字符串从第0个字符开始到第5个
	cout << str.replace(4, 1, "3344444", 0, 5) << endl;

	//12233344445555567890	从第10个字符开始低缓1个字符,替换成五个字符
	cout << str.replace(10, 1, 5, '5') << endl;

	//hello world	从迭代器开始到结束替换成字符串
	cout << str.replace(str.begin(), str.end(), "hello world") << endl;

	//hello	从迭代器开始到结束替换成字符串中的前五个字符
	cout << str.replace(str.begin(), str.end(), "hello world", 5) << endl;

	//hello	从迭代器开始到结束替换成五个字符
	cout << str.replace(str.begin(), str.end(), 5, 'a') << endl;
}

// 交换判空比较
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
	cout << str.at(111) << endl; // 会抛异常
}

// 从邮箱截取名
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

// 大小写转换
void test16()
{
	string str = "sdklfjasdk";
	int len = str.size();

	// 小写转大写
	for (int i = 0; i < len; ++i)
	{
		//str[i] = str[i] - 32;
		str[i] = toupper(str[i]);
	}
	cout << str << endl;

	// 大写转小写
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