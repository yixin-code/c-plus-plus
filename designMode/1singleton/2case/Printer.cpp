#include "Printer.h"
#include <iostream>

Printer *Printer::m_printer = new Printer;
int Printer::m_count = 0;

Printer::Printer()
{
}

Printer::Printer(const Printer &p)
{
}

Printer *Printer::getPrinter()
{
    return m_printer;
}

int Printer::getCount()
{
    return m_count;
}

void Printer::print(std::string text)
{
    std::cout << text << std::endl;
    m_count++;
}