#include <iostream>

using namespace std;

void apply(int **p)
{
    *p = new int;
}

void release(int **p)
{
    if(*p != nullptr)
    {
        delete *p;
        *p = nullptr;
    }
}

void apply2(int *&p)
{
    p = new int;
}

void release2(int *&p)
{
    if (p != nullptr)
    {
        delete p;
        p = nullptr;
    }
}

int main(int argc, char *argv[])
{
    int *p = nullptr;
    apply(&p);
    cout << p << endl;
    release(&p);
    cout << p << endl;

    cout << "-----------" << endl;

    apply2(p);
    cout << p << endl;
    release2(p);
    cout << p << endl;

    return 0;
}