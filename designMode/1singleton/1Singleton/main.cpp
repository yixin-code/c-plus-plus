// 单例模式
// 保证只有一个对象实例
#include <iostream>

using namespace std;

class Singleton
{
public:
    // 正常模式下可以随意创建对象, 需将构造函数私有化
    // Singleton() {}
    // 可用静态成员在类外执行构造函数
    // static Singleton *st;

    // 外部接口, 要访问静态成员需要静态成员函数
    static Singleton *getInstance()
    {
        return st;
    }
    

private:
    Singleton()
    {
        cout << "静态成员会在编译阶段执行" << endl;
    }
    Singleton(const Singleton& s)
    {

    }

    static Singleton *st;
};

// 执行构造函数
Singleton* Singleton::st = new Singleton;

void func()
{
    // Singleton s;
    // Singleton *s2 = new Singleton;

    // 指针赋值 两个地址都是st的地址, 但是这样可以通过st更改指向
    // 需要将st也设置为私有, 在公有中提供接口
    // Singleton *s = Singleton::st;
    // Singleton *s2 = Singleton::st;
    // Singleton::st = nullptr;

    // 返回的是指针不是引用， getInstance不能做左值进行修改
    // s和s2， 拿到的是同一个指针
    // 但是可以通过拷贝构造函数拿到st的地址, 使s3的指向和s2的指向并不相同， 只是共享st需要将拷贝构造函数也私有化
    Singleton *s = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    // Singleton *s3 = new Singleton(*s2);
    
}

int main(int argc, char *argv[])
{
    cout << "运行阶段执行" << endl;
    func();

    return 0;
}