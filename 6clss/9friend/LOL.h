#pragma once
#include <string>

class LOL
{
    friend void bestFrind(LOL &l);
private:
    std::string m_userName;
    int m_account;
    int m_passwd;
public:
    LOL();
    LOL(std::string userName, int account, int passwd);
};