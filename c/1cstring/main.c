#include <stdio.h>
#include <string.h>

void test()
{
    char str[111] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char str2[11] = "bbb";
    char str3[11] = "ccc";

    // 拷贝
    strcpy(str2, str);
    printf("%s\n", str2);
    strncpy(str3, str, sizeof(str3) - 1); // 两个字符串最小空间
    printf("%s\n", str3);
}

int main(int argc, char **argv)
{
    test();

    return 0;
}