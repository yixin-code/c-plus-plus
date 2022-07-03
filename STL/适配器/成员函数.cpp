// 
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

class Person
{
public:
	Person() {}
	Person(int num,string name) {
		this->m_age = num;
		this->name = name;
	}
	void display()
	{
		cout << this->name << " " << this->m_age << endl;
	}
	void add()
	{
		this->m_age++;
	}
private:
	int m_age;
	string name;
};

int main()
{
	Person p(11, "aaa");
	Person p2(22, "bbb");
	Person p3(33, "ccc");

	vector<Person> v = { p, p2, p3 };

	for_each(v.begin(), v.end(), mem_fun_ref(&Person::display));
	cout << endl;
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::add));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::display));

	// c++ 11
	for_each(v.begin(), v.end(), mem_fn(&Person::display));
	cout << endl;
	
	return 0;
}
