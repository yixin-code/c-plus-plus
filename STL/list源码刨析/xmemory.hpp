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

// ������
// �ռ乹���ͷ� ����������
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

	// ȡ��ַ
	pointer address(reference _X)const
	{
		return &_X;
	}

	// ȡ����ַ
	const_pointer address(const_reference _X)const
	{
		return &_X;
	}

	// ����ռ�
	pointer allocate(size_type _N, const void*)
	{
		return (_myAllocate((difference_type)_N, (pointer)0));
	}

	// char����ռ�
	char* _Charalloc(size_type _N)
	{
		return (_myAllocate((difference_type)_N, (char*)0));
	}

	// �ͷſռ�
	void deallocate(void* _P, size_type)
	{
		operator delete(_P);
	}

	// ���췽��
	void construct(pointer _P, const_reference _V)
	{
		_myConstruct(_P, _V);
	}

	// ��������
	void destroy(pointer _P)
	{
		_myDestroy(_P);
	}

	// �ɴ��������������
	size_type max_size() const
	{
		// -1������fffffff, ��ÿ�������С���Ǹ���
		size_type _N = (size_type)(-1) / sizeof(_Ty); 
		return (0 < _N ? _N : 1);
	}
};
