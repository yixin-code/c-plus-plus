#pragma once
#include <string>
#include "Weapon.h"

class Code : public Weapon 
{
public:
    Code();
    virtual int getHarm();                  // 获取伤害
    virtual std::string getName();          // 获取名字
    virtual void setAtk(int atk);           // 设置攻击力
    virtual void setName(std::string name); // 设置名字

    virtual int getLeech();    // 吸血
    virtual bool isNumbness(); // 麻痹
    virtual bool isCrit();     // 暴击
};