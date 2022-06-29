#include <iostream>
#include <string>

using namespace std;

void test()
{
	pair<string, int> p("asdf", 11);
	cout << p.first << " " << p.second << endl;
	pair<string, int> p2 = make_pair("sfjl", 11);
	cout << p2.first << " " << p2.second << endl;
}

int main()
{
	test();

	return 0;
}