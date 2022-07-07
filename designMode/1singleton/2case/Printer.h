#pragma once
#include <string>

class Printer
{
private:
    Printer();
    Printer(const Printer &p);
public:
    static Printer *getPrinter();
    static int getCount();
    void print(std::string text);
private:
    static Printer *m_printer;
    static int m_count;
};

