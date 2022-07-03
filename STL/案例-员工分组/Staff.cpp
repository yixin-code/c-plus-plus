#include "Staff.h"

Staff::Staff()
{
}

Staff::Staff(double salary, std::string name)
{
	this->m_name = name;
	this->m_salary = salary;
}

void Staff::setName(std::string name)
{
	this->m_name = name;
}

void Staff::setSalary(double salary)
{
	this->m_salary = salary;
}

std::string Staff::getName() const
{
	return std::string(this->m_name);
}

double Staff::getSalary() const
{
	return this->m_salary;
}
