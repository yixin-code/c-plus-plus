#include <string>

class Test
{
private:
    int m_num;
    std::string m_str;

public:
    // Test(const char * str)
    Test(const std::string str)
    {
        m_str = str;
        m_num = 0;
    }

    explicit Test(int num)
    {
        m_str = "none";
        m_num = num;
    }
};

int main()
{
    // Test t = "aaa"; // 隐式类型转换不能从 const char* -> const string
    Test t("aaa");
    // Test t2 = 11; // 会发生隐士转化
    Test t2(11);
    Test t3(11.11);

    return 0;
}