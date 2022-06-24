#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// 0-1之间有无穷个实数
// 无论几位都没有办法精确的表示
// float 32位 1符号位 8系数 23扩大或缩小
// 浮点数的运算要慢
int main(int argc, char *argv[])
{
    float f = 1.1f;
    float f2 = f * 1000000000000000000;
    std::cout << std::fixed << std::setprecision(11) << f << std::endl;
    std::cout << std::fixed << std::setprecision(11) << f2 << std::endl;
    std::cout << sizeof(long double) << std::endl; // 16字节 128位

    // 浮点数判断
    float f3 = 1.1;
    float f4 = 1.1;
    if (fabs(f3 - f4) < __FLT_EPSILON__)
    {
        std::cout << "相等" << std::endl;
    }

    std::cout << 1.1e-11 << std::endl;
    std::cout << 1.1e11 << std::endl;
    std::cout << 1.1e11l << std::endl; // long double
    std::cout << 1.1e11f << std::endl; // float

    return 0;
}
			
// cmath
//          2.1	    2.9	    -2.1	-2.9
// floor()  2	    2	    -3	    -3
// ceil()	3	    3	    -2	    -2
// round()	2	    3	    -2	    -3