#pragma once
template<class T>
class MyList
{
public:
	struct Node;
	typedef Node* Nodeptr;
	struct Node
	{
		T m_value;
		Nodeptr m_next, m_prev;
	};
private:
	Nodeptr* m_head;

};

