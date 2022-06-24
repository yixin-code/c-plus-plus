#include <stdio.h>
#include <stdbool.h> // bool 类型头文件

void test()
{
    bool a = true;
    bool b = false;
    printf("%d %d\n", a, b);
}

int main(int argc, char **argv)
{
    test();

    return 0;
}