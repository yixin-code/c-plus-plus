#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 构造函数
void test()
{
	//声明一个int类型向量
	vector<int> v_int;
	//声明一个int类型向量,并用另一个对齐初始化(拷贝构造)
	vector<int> v_int2(v_int);
	cout << v_int.size() << endl;	//0 vector中元素数量大小

	//声明一个double类型向量,初始化大小为11,不是值
	vector<double> v_double(11);
	cout << v_double.size() << endl;	//11

	//声明一个double类型向量,初始化大小为11,值为11.11(就是11个11.11)
	vector<double> v_double2(11, 11.11);
	//遍历
	for (int i = 0; i < v_double2.size(); ++i)
	{
		cout << v_double2[i] << " ";	//11个11.11
	}
	cout << endl;

	//声明一个double类型向量,初始化为3个11.11
	vector<double> v_double3(v_double2.begin(), v_double2.begin() + 2);
	for (int i = 0; i < v_double3.size(); ++i)
	{
		cout << v_double3[i] << " ";	//2个11.11
	}
	cout << endl;

	//当然了用数组初始化也可以
	int arr[] = { 1,2,3,4,5 };
	vector<int> v_int3(arr, arr + 5);
	for (int i = 0; i < v_int3.size(); ++i)
	{
		cout << v_int3[i] << " ";	//1 2 3 4 5 
	}
	cout << endl;
}

// 插入 删除 修改元素个数 清空
void test2()
{
	vector<int> v_int;

	//在开始迭代器处插入1
	v_int.insert(v_int.begin(), 1);

	//在开始迭代器下一位置插入2个2
	v_int.insert(v_int.begin() + 1, 2, 2);

	int arr[] = { 3,3,3 };
	vector<int> v_int2(arr, arr + 3);
	//在迭代器向后移动三次位置插入3个3(其实就是在vector第三个位置后插入)
	//迭代器的区间都是左闭右开
	v_int.insert(v_int.begin() + 3, v_int2.begin(), v_int2.end());

	//尾部插入
	v_int.push_back(4);
	v_int.push_back(4);
	v_int.push_back(4);
	v_int.push_back(4);

	//迭代器遍历
	for (vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it)
	{
		cout << *it << " ";	//1223334444
	}
	cout << endl;

	//改变元素个数
	v_int.resize(6);
	for (vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it)
	{
		cout << *it << " ";	//122333
	}
	cout << endl;

	//改变元素个数,增加的新元素初始化为4
	v_int.resize(10, 4);
	for (vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it)
	{
		cout << *it << " ";	//1223334444
	}
	cout << endl;

	//尾删 删除4个4
	v_int.pop_back();
	v_int.pop_back();
	v_int.pop_back();
	v_int.pop_back();
	for (vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it)
	{
		cout << *it << " ";	//122333
	}
	cout << endl;

	//指定迭代器删除
	v_int.erase(v_int.begin() + 5);	//删除的是最后一个3
	for (vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it)
	{
		cout << *it << " ";	//12233
	}
	cout << endl;

	//指定迭代器区间删除
	v_int.erase(v_int.begin() + 1, v_int.end());
	for (vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it)
	{
		cout << *it << " ";	//1
	}
	cout << endl;

	//删除所有元素
	v_int.clear();
	for (vector<int>::iterator it = v_int.begin(); it != v_int.end(); ++it)
	{
		cout << *it << " ";	//1
	}
	cout << endl;
}

// 利用swap修改容量大小
void test3()
{
	vector<int> v(1111);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(3);

	// 用v初始化匿名对象， 然后交换， 初始化的时候会使用size而不是capacity
	vector<int>(v).swap(v);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

// 大小,容量,判空,迭代器,交换两个容器,对容器进行排序
void test4()
{
	vector<int> v;
	v.size();            //元素个数
	v.max_size();        //所能存储最大元素个数
	v.resize(1);          //改变元素个数

	v.capacity();        //能容纳元素的数量
	v.reserve(1);         //改变容纳元素的数量

	v.empty();           //判断容器是否为空

	//定义一个int类型的vector迭代器指向容器v开始位置
	vector<int>::iterator it = v.begin();

	vector<int> v2;
	v.swap(v2);           //交换两个元素

	//对vector进行排序,需要加入头文件algorithm
	sort(v.begin(), v.end());
}

// 嵌套
void test5()
{
	//vector<int>(3,1) 这个是匿名对象 
	//整体相当于int[2][3] 全部初始化为1
	vector<vector<int>> v(2, vector<int>(3, 1));

	//遍历 
	//auto it = v.begin();
	vector<vector<int>>::iterator it = v.begin();
	//*it 就是最里层<>里的东西

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

	//但是这是逻辑结构,很容易把自己玩懵,例如上面我在v2中插了好多数据但是显示的只有三个(因为我上面限定了三个)
	//要修改可以使用resize
	//一般真要用的时候也都是直接vector<vector<int>> v; 这样使用
	//然后在声明一个vector插入数据,然后将这个插入到二维上
	//遍历的时候拿到一个迭代器取值,中括号下标就可以了
	//这东西本质上其实还是指针嘛
}

int main()
{
	test3();

	return 0;
}