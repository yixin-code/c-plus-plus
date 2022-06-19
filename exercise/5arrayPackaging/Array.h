#pragma once

class Array
{
private:
    int m_capacity;
    int m_size;
    int *arr;
public:
    Array();
    Array(int capacity);
    Array(const Array &a);
    ~Array();
    void pushBack(int data);
    int &operator[](int index);
    int getSize()const;
    int getCapacity()const;
};