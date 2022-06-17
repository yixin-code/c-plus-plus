#include "ID.h"
#include "Love.h"

class Student
{
    // 构造函数调用的顺序和复制顺序无关， 和成员变量声明有关
private:
    std::string m_name;
    ID m_id;
    Love m_love;
public:
    Student();
    Student(std::string name, std::string love_name, int id);
    void display();
    ~Student();
};