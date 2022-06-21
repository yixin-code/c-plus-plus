#pragma once
#include <string>

class Weapon
{
private:
    std::string m_name;
    int m_atk;

public:
    virtual int getHarm() = 0; // 获取伤害
    virtual std::string getName() = 0; // 获取名字
    virtual void setAtk(int atk) = 0; // 设置攻击力
    virtual void setName(std::string name) = 0; // 设置名字

    virtual int getLeech() = 0; // 吸血
    virtual bool isNumbness() = 0; // 麻痹
    virtual bool isCrit() = 0; // 暴击

};