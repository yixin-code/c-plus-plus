#include <iostream>

using namespace std;

class Parent
{
public:
    void eyes()
    {
        cout << "eyes" << endl;
    }
    void nose()
    {
        cout << "nose" << endl;
    }
    void mouth()
    {
        cout << "mouth" << endl;
    }
};

class Son : public Parent
{
public:
    void sex()
    {
        cout << "boy" << endl;
    }
};

class Dau : public Parent
{
public:
    void sex()
    {
        cout << "girl" << endl;
    }
};

int main(int argc, char *argv[])
{
    Son s;
    s.eyes();
    s.mouth();
    s.nose();
    s.sex();

    Dau d;
    d.eyes();
    d.mouth();
    d.nose();
    d.sex();

    return 0;
}