#include <iostream>

void test()
{
    // 中文字符
    char16_t c = u'阿';
    char32_t c2 = u'阿';
    std::cout << c << " " << c2 << std::endl;
}

int main(int argc, char *argv[])
{
    test();

    return 0;
}