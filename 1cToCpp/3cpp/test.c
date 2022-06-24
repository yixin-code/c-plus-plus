#include <stdio.h>

enum Num
{
    zero,
    one,
    two,
    three
};

void typeEnhance()
{
    int *p = malloc(11);

    const int a = 11;
    int *p2 = &a;
    *p2 = 111;
    printf("a = %d\n", a);

    int arr[2][3];
    int *p3 = arr;

    enum Num num = 1;
    enum Num num = one;

    int a, b, c = 11;
    // (a = b) = c; // c 中返回的是常量 相当于 c复制给一段随机值的常量
}

int main()
{

    return 0;
}