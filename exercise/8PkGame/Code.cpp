#include "Code.h"

Code::Code()
{
    this->m_atk = 11;
    this->m_name = "恶魔法典";
}

int Code::getHarm() // 获取伤害
{
    return this->m_atk;
}

std::string Code::getName() // 获取名字
{
    return this->m_name;
}

void Code::setAtk(int atk) // 设置攻击力
{
    this->m_atk = atk;
}

void Code::setName(std::string name) // 设置名字
{
    this->m_name = name;
}

int Code::getLeech() // 吸血
{
    return 0;
}

bool Code::isNumbness() // 麻痹
{
    return false;
}

bool Code::isCrit() // 暴击
{
    return false;
}