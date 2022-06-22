#pragma once

#include <string>
#include "Weapon.h"

class Hat : public Weapon
{
public:
    Hat();
    virtual int getHarm();                  // 获取伤害
    virtual std::string getName();          // 获取名字
    virtual void setAtk(int atk);           // 设置攻击力
    virtual void setName(std::string name); // 设置名字

    virtual int getLeech();    // 吸血
    virtual bool isNumbness(); // 麻痹
    virtual bool isCrit();     // 暴击
    bool isTrigger(int prob); //触发概率
private:
    int m_leech;
    int m_numbness;
    int m_crit;
};