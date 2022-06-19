#include "LOL.h"
#include <iostream>

// 友元函数是全局函数 实现不需要加作用域和限定符
void bestFrind(LOL &l)
{
    std::cout << "user name: " << l.m_userName << std::endl;
    std::cout << "account: " << l.m_account << std::endl;
    std::cout << "passwd: " << l.m_passwd << std::endl; 
}

LOL::LOL()
{
    this->m_account = 0;
    this->m_passwd = 0;
    this->m_userName = "none";
}

LOL::LOL(std::string userName, int account, int passwd)
{
    this->m_account = account;
    this->m_userName = userName;
    this->m_passwd = passwd;
}