#pragma once
#include <assert.h>
#include <iostream>
#include "xmemory.hpp"

using namespace std;

// STL中_开始的是内部使用的成员
template<class _Ty, class _A = myallocator<_Ty> >
class list
{
public:
	struct _Node; // 前置声明

	// 萃取
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

	// 迭代器
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
			// 调用重载的==, 减少逻辑代码
			// 重载后两个对象相比
			return !(*this == _X);
		}
		// 前置
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
			// 调用重载的==, 减少逻辑代码
			// 重载后两个对象相比
			return !(*this == _X);
		}
		// 前置
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

	// _Acc 只是一个名字而已，什么含义要问写这段代码的人。
	struct _Acc
	{
		typedef _Nodeptr& _Nodepref; // 指针的引用
		typedef reference_type _Vref; // 值的引用

		// 定义成静态我能想到的好像也只有共享这一个原因了
		static _Nodepref _Next(_Nodepref _P)
		{
			return ((_Nodepref)(*_P)._Next); // _P->_Next 等价 只是更安全些
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
	// 空链表需要包含头节点
	// explicit 防止隐士类型转换
	// 可以将分配节点的工作单独进行封装
	// 初始化 _Head 时会调用 _Buynode 并将返回值赋值给 _Head
	explicit list() : _Size(0), _Head(_Buynode())
	{
#if 0
		this->_Head = (_Nodeptr)malloc(sizeof(_Node));
		assert(_Head != NULL);
		this->_Head->_Next = this->_Head;
		this->_Head->_Prev = this->_Head;
#endif
	}

	// 构造几个几 list<int> l(10,1)
	explicit list(size_type _N, const_reference_type _V = _Ty()) : _Head(this->_Buynode()), _Size(0)
	{
		this->insert(this->begin(), _N, _V);
	}

	// 指针区间构造
	explicit list(const_pointer_type _F, const_pointer_type _L) : _Head(this->_Buynode()), _Size(0)
	{
		this->insert(this->begin(), _F, _L);
	}

	// 迭代器区间构造
	explicit list(_It _F, _It _L) : _Head(this->_Buynode()), _Size(0)
	{
		this->insert(this->begin(), _F, _L);
	}

	// 析构的时候删除所有节点
	// 在删除头节点
	~list()
	{
		erase(begin(), end());
		_Freenode(_Head);
		_Head = NULL;
		this->_Size = 0;
	}

public:
	// 后续用insert实现
#if 0
	void push_back(const_reference_type _V)
	{
#if 0
		_Nodeptr _S = _Buynode();
		_S->_Next = this->_Head;
		// 新节点的前一节点是未插入新节点的最后一个节点
		// _Head->_Prev 就是未插入新节点时的最后一个节点
		_S->_Prev = this->_Head->_Prev;
		// this->_Head->_Prev->_Next 是未插入新节点时最后一个节点的下一节点
		this->_Head->_Prev->_Next = _S;
		// 需要使用 _Head 找其他节点所以必须最后赋值
		this->_Head->_Prev = _S;
		this->_Head->_Value = _V;
#elif 0
		// 升级版
		_Nodeptr _S = _Buynode(this->_Head, this->_Head->_Prev);
		// this->_Head->_Prev->_Next 是未插入新节点时最后一个节点的下一节点
		this->_Head->_Prev->_Next = _S;
		// 需要使用 _Head 找其他节点所以必须最后赋值
		this->_Head->_Prev = _S;
		this->_Head->_Value = _V;
#else
		// 升级版 2
		_Nodeptr _S = _Buynode(_Head, _Acc::_Prev(this->_Head));
		_Acc::_Next(_Acc::_Prev(this->_Head)) = _S;
		_Acc::_Prev(this->_Head) = _S;
		_Acc::_Value(_S) = _V;
#endif

		this->_Size++;
	}
#endif

	// STL 所有插入都是在位置前插入
	iterator insert(iterator _P, const _Ty& _X = _Ty())
	{
#if 0
		_Nodeptr _Ptr = _P._Mynode();
		_Nodeptr _S = _Buynode(_Ptr, _Acc::_Prev(_Ptr));
		// 迭代器位置的前一节点赋值为 _S
		_Acc::_Prev(_Ptr) = _S;
		// 插入节点的前一节点的下一节点为 _S
		_Acc::_Next(_Acc::_Prev(_S)) = _S;

		_Acc::_Value(_S) = _X;
		this->_Size++;
		return iterator(_S);
#else
		// _S 为迭代器指向 节点的指针
		_Nodeptr _S = _P._Mynode();
		// 新节点前驱后继指向
		// _S 节点的前驱 指向 新节点 三个指向
		_Acc::_Prev(_S) = _Buynode(_S, _Acc::_Prev(_S));
		// 将 _S 指向新节点
		_S = _Acc::_Prev(_S);
		// 新节点后继
		_Acc::_Next(_Acc::_Prev(_S)) = _S;

		//_Acc::_Value(_S) = _X;

		// 数据为自定义类型的时候，可以调用拷贝构造
		allocator.construct(&_Acc::_Value(_S), _X);

		this->_Size++;
		return iterator(_S);
#endif
	}

	// 重载insert 在迭代器位置插入M个X
	void insert(iterator _P, size_type _M, const_reference_type _X = _Ty())
	{
		while (_M)
		{
			insert(_P, _X);
			_M--;
		}
	}

	// 迭代器前插入指针区域
	void insert(iterator _P, const_pointer_type _F, const_pointer_type _L)
	{
		while (_F != _L)
		{
			insert(_P, *_F);
			++(_F);
		}
	}

	// 迭代器前插入迭代器区间
	void insert(iterator _P, const_iterator _F, const_iterator _L)
	{
		while (_F != _L)
		{
			insert(_P, *_F);
			++(_F);
		}
	}

	// 分配
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
		// 迭代器指向节点删除后，该迭代器并不失效，而是指向下一个节点
		_Nodeptr _S = (_P++)._Mynode();
		_Acc::_Next(_Acc::_Prev(_S)) = _Acc::_Next(_S);
		_Acc::_Prev(_Acc::_Next(_S)) = _Acc::_Prev(_S);

		// 释放空间
		//free(_S);
		
		// 可以调用自定义类型的析构函数
		allocator.destroy(&_Acc::_Value(_S));
		_Freenode(_S);

		this->_Size--;

		return _P;
	}

	// 删除区间
	iterator erase(_It _F, _It _L)
	{
		while (_F != _L)
		{
			erase(_F++);
		}
		return _F;
	}

	// 获取几个元素
	size_type size()const
	{
		return this->_Size;
	}

	// 头元素
	reference_type front()
	{
		return *this->begin();
	}

	// 尾元素
	reference_type back()
	{
		return *(--this->end());
	}

	// 尾插
	void push_back(const_reference_type _V)
	{
		insert(end(), _V);
	}

	// 尾插
	void push_front(const_reference_type _V)
	{
		insert(begin(), _V);
	}
	
	// 头删
	void pop_front()
	{
		this->erase(this->begin());
	}

	// 尾删
	void pop_end()
	{
		this->erase(--this->end());
	}

	// 清除
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
		// 返回 const_iterator 对象
		// 迭代器实际上是指向节点的指针
		return const_iterator(_Acc::_Next(this->_Head));
	}

	// end返回最后一个节点的下一个节点， 在双向循环链表中 也就是头节点
	iterator end()
	{
		return iterator(this->_Head);
	}
	const_iterator end()const
	{
		return const_iterator(this->_Head);
	}


protected:
	// 封装新建节点
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
	// 升级版,用参数直接传入新节点的前驱和后继,可以减少插入逻辑代码
	// 尽可能的复用代码，减少逻辑代码量，从而减少出错率
	_Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0)
	{
		//_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
		
		// 分配器创建节点
		_Nodeptr _S = (_Nodeptr)this->allocator._Charalloc(sizeof(_Node));

		// 参数为假时 显示错误信息，调用 abort中断程序
		assert(_S != NULL); 
#if 0
		_S->_Next = (_Narg == 0 ? _S : _Narg);
		_S->_Prev = (_Parg == 0 ? _S : _Parg);
#else
		// 升级版
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
	//		// 插入迭代器区间
	//		insert(_P, _F, _L);
	//		// 删除迭代器区间
	//		_X.erase(_F, _L);
	//	}
	//}

private:
	_A allocator; // 空间分配器
	_Nodeptr _Head;
	size_type _Size;
};
