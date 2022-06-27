#include <iostream>
#include "ID.h"

ID::ID()
{
    std::cout << "ID constructor" << std::endl;
}

ID::ID(int id)
{
    std::cout << "ID argument constructor" << std::endl;
    this->m_id = id;
}

int ID::getId() const
{
    return this->m_id;
}

ID::~ID()
{
    std::cout << "ID destructor" << std::endl;
}