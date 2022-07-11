#pragma once
#include <assert.h>
#include <iostream>
#include "xmemory.hpp"

using namespace std;

// STL��_��ʼ�����ڲ�ʹ�õĳ�Ա
template<class _Ty, class _A = myallocator<_Ty> >
class list
{
public:
	struct _Node; // ǰ������

	// ��ȡ
	//typedef _Node* _Nodeptr;
	using _Nodeptr				= _Node*;
	using size_type				= size_t;
	using difference_type		= int; 
	using value_type			= _Ty;
	using pointer_type			= _Ty*;
	using reference_type		= _Ty&;
	using const_pointer_type	= const _Ty*;
	using const_reference_type	= const _Ty&;

	typedef list<_Ty, _A> _Myt;

	// ������
	class iterator;
	class const_iterator;

	typedef iterator _It;

	class const_iterator
	{
	public:
		const_iterator(){}
		const_iterator(_Nodeptr _P) : _Ptr(_P){}
		const_iterator(const const_iterator &_X) : _Ptr(_X._Ptr){}

		bool operator==(const const_iterator& _X)const
		{
			return this->_Ptr == _X._Ptr;
		}
		bool operator!=(const const_iterator& _X)const
		{
			// �������ص�==, �����߼�����
			// ���غ������������
			return !(*this == _X);
		}
		// ǰ��
		const_iterator operator++()
		{
			this->_Ptr = _Acc::_Next(this->_Ptr); // this->_Ptr = this->_Ptr->_Next
			return *this;
		}
		const_iterator operator++(int)
		{
			const_iterator _Temp = *this;
			++(*this);
			return _Temp;
		}
		const_iterator operator--()
		{
			this->_Ptr = _Acc::_Prev(this->_Ptr);
			return *this;
		}
		const_iterator operator--(int)
		{
			const_iterator _Temp = *this;
			--(*this);
			return _Temp;
		}

		const_reference_type operator*()const
		{
			return _Acc::_Value(this->_Ptr);
		}

		_Nodeptr _Mynode()const
		{
			return this->_Ptr;
		}
	protected:
		_Nodeptr _Ptr;
	};

	class iterator : public const_iterator
	{
	public:
		iterator(){}
		iterator(_Nodeptr _P) : const_iterator(_P){}
		iterator(const iterator& _X) : const_iterator(_X._Ptr) {}

		reference_type operator*()
		{
			return _Acc::_Value(this->_Ptr);
		}
		bool operator==(const iterator& _X)const
		{
			return this->_Ptr == _X._Ptr;
		}
		bool operator!=(const iterator& _X)const
		{
			// �������ص�==, �����߼�����
			// ���غ������������
			return !(*this == _X);
		}
		// ǰ��
		iterator operator++()
		{
			this->_Ptr = _Acc::_Next(this->_Ptr); // this->_Ptr = this->_Ptr->_Next
			return *this;
		}
		iterator operator++(int)
		{
			iterator _Temp = *this;
			++(*this);
			return _Temp;
		}
		iterator operator--()
		{
			this->_Ptr = _Acc::_Prev(this->_Ptr);
			return *this;
		}
		iterator operator--(int)
		{
			iterator _Temp = *this;
			--(*this);
			return _Temp;
		}

		_Nodeptr _Mynode()
		{
			return this->_Ptr;
		}
	};

	struct _Node
	{
#if 0
		_Ty _Value;
		_Node* _Next;
		_Node* _Prev;
#else
		value_type	_Value;
		_Nodeptr	_Next;
		_Nodeptr	_Prev;
#endif
	};

	// _Acc ֻ��һ�����ֶ��ѣ�ʲô����Ҫ��д��δ�����ˡ�
	struct _Acc
	{
		typedef _Nodeptr& _Nodepref; // ָ�������
		typedef reference_type _Vref; // ֵ������

		// ����ɾ�̬�����뵽�ĺ���Ҳֻ�й�����һ��ԭ����
		static _Nodepref _Next(_Nodepref _P)
		{
			return ((_Nodepref)(*_P)._Next); // _P->_Next �ȼ� ֻ�Ǹ���ȫЩ
		}
		static _Nodepref _Prev(_Nodepref _P)
		{
			return ((_Nodepref)(*_P)._Prev);
		}
		static _Vref _Value(_Nodepref _P)
		{
			return (_Vref)(*_P)._Value;
		}
	};

public:
	// ��������Ҫ����ͷ�ڵ�
	// explicit ��ֹ��ʿ����ת��
	// ���Խ�����ڵ�Ĺ����������з�װ
	// ��ʼ�� _Head ʱ����� _Buynode ��������ֵ��ֵ�� _Head
	explicit list() : _Size(0), _Head(_Buynode())
	{
#if 0
		this->_Head = (_Nodeptr)malloc(sizeof(_Node));
		assert(_Head != NULL);
		this->_Head->_Next = this->_Head;
		this->_Head->_Prev = this->_Head;
#endif
	}

	// ���켸���� list<int> l(10,1)
	explicit list(size_type _N, const_reference_type _V = _Ty()) : _Head(this->_Buynode()), _Size(0)
	{
		this->insert(this->begin(), _N, _V);
	}

	// ָ�����乹��
	explicit list(const_pointer_type _F, const_pointer_type _L) : _Head(this->_Buynode()), _Size(0)
	{
		this->insert(this->begin(), _F, _L);
	}

	// ���������乹��
	explicit list(_It _F, _It _L) : _Head(this->_Buynode()), _Size(0)
	{
		this->insert(this->begin(), _F, _L);
	}

	// ������ʱ��ɾ�����нڵ�
	// ��ɾ��ͷ�ڵ�
	~list()
	{
		erase(begin(), end());
		_Freenode(_Head);
		_Head = NULL;
		this->_Size = 0;
	}

public:
	// ������insertʵ��
#if 0
	void push_back(const_reference_type _V)
	{
#if 0
		_Nodeptr _S = _Buynode();
		_S->_Next = this->_Head;
		// �½ڵ��ǰһ�ڵ���δ�����½ڵ�����һ���ڵ�
		// _Head->_Prev ����δ�����½ڵ�ʱ�����һ���ڵ�
		_S->_Prev = this->_Head->_Prev;
		// this->_Head->_Prev->_Next ��δ�����½ڵ�ʱ���һ���ڵ����һ�ڵ�
		this->_Head->_Prev->_Next = _S;
		// ��Ҫʹ�� _Head �������ڵ����Ա������ֵ
		this->_Head->_Prev = _S;
		this->_Head->_Value = _V;
#elif 0
		// ������
		_Nodeptr _S = _Buynode(this->_Head, this->_Head->_Prev);
		// this->_Head->_Prev->_Next ��δ�����½ڵ�ʱ���һ���ڵ����һ�ڵ�
		this->_Head->_Prev->_Next = _S;
		// ��Ҫʹ�� _Head �������ڵ����Ա������ֵ
		this->_Head->_Prev = _S;
		this->_Head->_Value = _V;
#else
		// ������ 2
		_Nodeptr _S = _Buynode(_Head, _Acc::_Prev(this->_Head));
		_Acc::_Next(_Acc::_Prev(this->_Head)) = _S;
		_Acc::_Prev(this->_Head) = _S;
		_Acc::_Value(_S) = _V;
#endif

		this->_Size++;
	}
#endif

	// STL ���в��붼����λ��ǰ����
	iterator insert(iterator _P, const _Ty& _X = _Ty())
	{
#if 0
		_Nodeptr _Ptr = _P._Mynode();
		_Nodeptr _S = _Buynode(_Ptr, _Acc::_Prev(_Ptr));
		// ������λ�õ�ǰһ�ڵ㸳ֵΪ _S
		_Acc::_Prev(_Ptr) = _S;
		// ����ڵ��ǰһ�ڵ����һ�ڵ�Ϊ _S
		_Acc::_Next(_Acc::_Prev(_S)) = _S;

		_Acc::_Value(_S) = _X;
		this->_Size++;
		return iterator(_S);
#else
		// _S Ϊ������ָ�� �ڵ��ָ��
		_Nodeptr _S = _P._Mynode();
		// �½ڵ�ǰ�����ָ��
		// _S �ڵ��ǰ�� ָ�� �½ڵ� ����ָ��
		_Acc::_Prev(_S) = _Buynode(_S, _Acc::_Prev(_S));
		// �� _S ָ���½ڵ�
		_S = _Acc::_Prev(_S);
		// �½ڵ���
		_Acc::_Next(_Acc::_Prev(_S)) = _S;

		//_Acc::_Value(_S) = _X;

		// ����Ϊ�Զ������͵�ʱ�򣬿��Ե��ÿ�������
		allocator.construct(&_Acc::_Value(_S), _X);

		this->_Size++;
		return iterator(_S);
#endif
	}

	// ����insert �ڵ�����λ�ò���M��X
	void insert(iterator _P, size_type _M, const_reference_type _X = _Ty())
	{
		while (_M)
		{
			insert(_P, _X);
			_M--;
		}
	}

	// ������ǰ����ָ������
	void insert(iterator _P, const_pointer_type _F, const_pointer_type _L)
	{
		while (_F != _L)
		{
			insert(_P, *_F);
			++(_F);
		}
	}

	// ������ǰ�������������
	void insert(iterator _P, const_iterator _F, const_iterator _L)
	{
		while (_F != _L)
		{
			insert(_P, *_F);
			++(_F);
		}
	}

	// ����
	void assign(_It _F, _It _L)
	{
		erase(_F, _L);
		this->insert(_F, _L);
	}

	void assign(iterator _P, const_reference_type _X = _Ty())
	{
		this->erase(begin(), end());
		insert(begin(), _X);
	}

	void assign(size_type _N, const_reference_type _X = _Ty())
	{
		this->erase(begin(), end());
		insert(begin(),_N, _X);
	}

	iterator erase(iterator _P)
	{
		// ������ָ��ڵ�ɾ���󣬸õ���������ʧЧ������ָ����һ���ڵ�
		_Nodeptr _S = (_P++)._Mynode();
		_Acc::_Next(_Acc::_Prev(_S)) = _Acc::_Next(_S);
		_Acc::_Prev(_Acc::_Next(_S)) = _Acc::_Prev(_S);

		// �ͷſռ�
		//free(_S);
		
		// ���Ե����Զ������͵���������
		allocator.destroy(&_Acc::_Value(_S));
		_Freenode(_S);

		this->_Size--;

		return _P;
	}

	// ɾ������
	iterator erase(_It _F, _It _L)
	{
		while (_F != _L)
		{
			erase(_F++);
		}
		return _F;
	}

	// ��ȡ����Ԫ��
	size_type size()const
	{
		return this->_Size;
	}

	// ͷԪ��
	reference_type front()
	{
		return *this->begin();
	}

	// βԪ��
	reference_type back()
	{
		return *(--this->end());
	}

	// β��
	void push_back(const_reference_type _V)
	{
		insert(end(), _V);
	}

	// β��
	void push_front(const_reference_type _V)
	{
		insert(begin(), _V);
	}
	
	// ͷɾ
	void pop_front()
	{
		this->erase(this->begin());
	}

	// βɾ
	void pop_end()
	{
		this->erase(--this->end());
	}

	// ���
	void clear()
	{
		this->erase(begin(), end());
	}

	iterator begin()
	{
		return iterator(_Acc::_Next(this->_Head));
	}
	const_iterator begin()const
	{
		// ���� const_iterator ����
		// ������ʵ������ָ��ڵ��ָ��
		return const_iterator(_Acc::_Next(this->_Head));
	}

	// end�������һ���ڵ����һ���ڵ㣬 ��˫��ѭ�������� Ҳ����ͷ�ڵ�
	iterator end()
	{
		return iterator(this->_Head);
	}
	const_iterator end()const
	{
		return const_iterator(this->_Head);
	}


protected:
	// ��װ�½��ڵ�
#if 0
	_Nodeptr _Buynode()
	{
		_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
		assert(_S != NULL);
		_S->_Next = _S;
		_S->_Prev = _S;

		return _S;
	}
#else
	// ������,�ò���ֱ�Ӵ����½ڵ��ǰ���ͺ��,���Լ��ٲ����߼�����
	// �����ܵĸ��ô��룬�����߼����������Ӷ����ٳ�����
	_Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0)
	{
		//_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
		
		// �����������ڵ�
		_Nodeptr _S = (_Nodeptr)this->allocator._Charalloc(sizeof(_Node));

		// ����Ϊ��ʱ ��ʾ������Ϣ������ abort�жϳ���
		assert(_S != NULL); 
#if 0
		_S->_Next = (_Narg == 0 ? _S : _Narg);
		_S->_Prev = (_Parg == 0 ? _S : _Parg);
#else
		// ������
		_Acc::_Next(_S) = (_Narg == 0 ? _S : _Narg);
		_Acc::_Prev(_S) = (_Parg == 0 ? _S : _Parg);
#endif

		return _S;
	}
#endif

	void _Freenode(_Nodeptr _S)
	{
		allocator.deallocate(_S, 1);
	}

	//void _Splice(iterator _P, _Myt& _X, iterator _F, iterator _L)
	//{
	//	if (allocator == _X.allocator)
	//	{
	//		
	//	}
	//	else
	//	{
	//		// �������������
	//		insert(_P, _F, _L);
	//		// ɾ������������
	//		_X.erase(_F, _L);
	//	}
	//}

private:
	_A allocator; // �ռ������
	_Nodeptr _Head;
	size_type _Size;
};
