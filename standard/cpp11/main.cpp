#include <iostream>
#include <cstdint> // int头文件，大部分编译器可以不加

// 类型
void test2()
{
    size_t val = 0;    // 正整数， 通常表示内存，计数等
    int8_t val2 = 0;   // 8位int
    int16_t val3 = 0;  // 16位int
    int32_t val4 = 0;  // 32位int
    int64_t val5 = 0;  // 64位int
    uint8_t val6 = 0;  //  无符号8位int
    uint16_t val7 = 0; // 无符号16位int
    uint32_t val8 = 0; // 无符号32位int
    uint64_t val9 = 0; // 无符号64位int

    // 最大值最小值可用做判断
    std::cout << INT8_MIN << std::endl;
    std::cout << INT8_MAX << std::endl;
    std::cout << INT16_MIN << std::endl;
    std::cout << INT16_MAX << std::endl;
    std::cout << INT32_MIN << std::endl;
    std::cout << INT32_MAX << std::endl;
    std::cout << INT64_MIN << std::endl;
    std::cout << INT64_MAX << std::endl;
}

// 中文字符
void test()
{
    char16_t c = u'阿';
    char32_t c2 = u'阿';
    std::cout << c << " " << c2 << std::endl;
    std::cout << "---------------------------" << std::endl;
}

int main(int argc, char *argv[])
{
    test();
    test2();

    return 0;
}