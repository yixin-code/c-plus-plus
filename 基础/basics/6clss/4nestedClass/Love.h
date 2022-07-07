#pragma once
#include <string>

class Love
{
private:
    std::string m_name;
public:
    Love();
    Love(std::string name);
    std::string getName() const;
    ~Love();
};
