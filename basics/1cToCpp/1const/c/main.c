#include <stdio.h>

int main(int argc, char *argv[])
{
    // 在C中const是外部链接
    extern const int  NUM;

    printf("%d\n", NUM);

    return 0;
}