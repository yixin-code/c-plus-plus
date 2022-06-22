#include "Hat.h"

Hat::Hat()
{
    this->m_atk = 22;
    this->m_crit = 33;
    this->m_leech = 11;
    this->m_name = "灭世之帽";
    this->m_numbness = 22;
}

int Hat::getHarm() // 获取伤害
{
    return this->m_atk;
}

std::string Hat::getName() // 获取名字
{
    return this->m_name;
}

void Hat::setAtk(int atk) // 设置攻击力
{
    this->m_atk = atk;
}
void Hat::setName(std::string name) // 设置名字
{
    this->m_name = name;
}

bool Hat::isNumbness() // 麻痹
{
    if (isTrigger(this->m_numbness))
    {
        return true;
    }
    return false;
}

bool Hat::isCrit() // 暴击
{
    if (isTrigger(this->m_crit))
    {
        return true;
    }
    return false;
}

bool Hat::isTrigger(int prob) //触发概率
{
    if ((rand() % 100 + 1) <= prob)
    {
        return true;
    }
    return false;
}