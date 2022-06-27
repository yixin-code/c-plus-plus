#include "Array.h"
#include <iostream>

Array::Array()
{
    std::cout << "default constructor" << std::endl;
    this->m_capacity = 10;
    this->m_size = 0;
    this->arr = new int[m_capacity];
}

Array::Array(int capacity)
{
    std::cout << "parameter constructor" << std::endl;
    this->m_capacity = capacity;
    this->m_size = 0;
    this->arr = new int[m_capacity];
}

Array::Array(const Array &a)
{
    std::cout << "copy constructor" << std::endl;
    this->m_capacity = a.m_capacity;
    this->m_size = a.m_size;
    this->arr = new int[m_capacity];
    for (int i = 0; i < a.m_size; ++i)
    {
        this->arr[i] = a.arr[i];
    }
}

Array::~Array()
{
    std::cout << "destructor" << std::endl;
    if (this->arr != nullptr)
    {
        delete[] this->arr;
        this->arr = nullptr;
    }
}

void Array::pushBack(int data)
{
    this->arr[this->m_size] = data;
    this->m_size++;
}

int &Array::operator[](int index)
{
    return this->arr[index];
}

int Array::getSize() const
{
    return this->m_size;
}

int Array::getCapacity() const
{
    return this->m_capacity;
}