#include <iostream>
#include "list.hpp"

int main()
{
	list<int> l;

	for (int i = 0; i < 5; ++i)
	{
		l.push_back(i + 1);
	}

	for (int i = 6; i < 11; ++i)
	{
		l.insert(l.end(), i);
	}

	list<int>::iterator it = l.begin();

	cout << "É¾³ýÇ° " << *it << endl;

	it = l.erase(l.begin());  // ?????

	cout << "É¾³ýºó" << *it << endl;

	l.insert(l.begin(), 1, 1);

	while (it != l.end())
	{
		cout << *it << " ";
		//++it;
		it++;
	}
	cout << endl;

	return 0;
}
