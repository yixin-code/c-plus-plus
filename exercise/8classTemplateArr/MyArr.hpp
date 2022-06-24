#pragma once

template <typename T>
class MyArr
{
private:
    T *m_arr;
    int m_capacity;
    int m_size;

public:
    explicit MyArr()
    {
        this->m_capacity = 11;
        this->m_size = 0;
        this->m_arr = new T[m_capacity];
    }

    explicit MyArr(int capacity)
    {
        this->m_capacity = capacity;
        this->m_size = 0;
        this->m_arr = new T[m_capacity];
    }

    explicit MyArr(const MyArr &m)
    {
        this->m_capacity = m.m_capacity;
        this->m_size = m.m_size;

        this->m_arr = new T[m_capacity];
        for (int i = 0; i < m_size; ++i)
        {
            this->m_arr[i] = m.m_arr[i];
        }
    }

    MyArr &operator=(const MyArr &m)
    {
        if (this->m_arr != nullptr)
        {
            delete[] this->m_arr;
        }
        
        this->m_capacity = m.m_capacity;
        this->m_size = m.m_size;

        this->m_arr = new T[m_capacity];
        for (int i = 0; i < m_size; ++i)
        {
            this->m_arr[i] = m.m_arr[i];
        }
    }

    T &operator[](int index) const
    {
        return this->m_arr[index];
    }

    void back_push(T data)
    {
        this->m_arr[this->m_size] = data;
        this->m_size++;
    }

    int getCapacity() const
    {
        return this->m_capacity;        
    }

    int getSize() const
    {
        return this->m_size;
    }
};
