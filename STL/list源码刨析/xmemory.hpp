#pragma once

template<class _Ty>
_Ty* _myAllocate(int _N, _Ty*)
{
	if (_N < 0)
	{
		_N = 0;
	}
	return ((_Ty*)operator new((size_t)_N * sizeof(_Ty)));
}

template<class _T1, class _T2>
void _myConstruct(_T1* _P, const _T2& _V)
{
	new((void*)_P) _T1(_V);
}

template<class _Ty>
void _myDestroy(_Ty* _P)
{
	_P->~_Ty();
}

// 分配器
// 空间构造释放 对象构造析构
template<class _Ty>
class myallocator
{
public:
	using size_type =			size_t;
	using difference_type =		int;
	using pointer =				_Ty*;
	using const_pointer =		const _Ty*;
	using reference =			_Ty&;
	using const_reference =		const _Ty&;
	using value_type =			_Ty;

	// 取地址
	pointer address(reference _X)const
	{
		return &_X;
	}

	// 取常地址
	const_pointer address(const_reference _X)const
	{
		return &_X;
	}

	// 申请空间
	pointer allocate(size_type _N, const void*)
	{
		return (_myAllocate((difference_type)_N, (pointer)0));
	}

	// char申请空间
	char* _Charalloc(size_type _N)
	{
		return (_myAllocate((difference_type)_N, (char*)0));
	}

	// 释放空间
	void deallocate(void* _P, size_type)
	{
		operator delete(_P);
	}

	// 构造方法
	void construct(pointer _P, const_reference _V)
	{
		_myConstruct(_P, _V);
	}

	// 析构方法
	void destroy(pointer _P)
	{
		_myDestroy(_P);
	}

	// 可创建对象的最大个数
	size_type max_size() const
	{
		// -1补码是fffffff, 除每个对象大小就是个数
		size_type _N = (size_type)(-1) / sizeof(_Ty); 
		return (0 < _N ? _N : 1);
	}
};
