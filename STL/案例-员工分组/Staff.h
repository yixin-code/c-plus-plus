#pragma once
#include <string>

class Staff
{
public:
	Staff();
	Staff(double salary, std::string name);
	void setName(std::string name);
	void setSalary(double salary);
	std::string getName() const;
	double getSalary() const;
private:
	std::string m_name;
	double m_salary;
};

