// ios::app	追加模式。所有写入都追加到文件末尾。
// ios::ate	文件打开后定位到文件末尾。
// ios::in	打开文件用于读取。
// ios::out	打开文件用于写入。
// ios::trunc	如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0。

// 文件位置指针
// istream 和 ostream 都提供了用于重新定位文件位置指针的成员函数。这些成员函数包括关于 istream 的 seekg（"seek get"）和关于 ostream 的 seekp（"seek put"）。
// seekg 和 seekp 的参数通常是一个长整型。第二个参数可以用于指定查找方向。查找方向可以是 ios::beg（默认的，从流的开头开始定位），也可以是 ios::cur（从流的当前位置开始定位），也可以是 ios::end（从流的末尾开始定位）。
// 文件位置指针是一个整数值，指定了从文件的起始位置到指针所在位置的字节数。下面是关于定位 "get" 文件位置指针的实例：
// // 定位到 fileObject 的第 n 个字节（假设是 ios::beg）
// fileObject.seekg( n );
// // 把文件的读指针从 fileObject 当前位置向后移 n 个字节
// fileObject.seekg( n, ios::cur );
// // 把文件的读指针从 fileObject 末尾往回移 n 个字节
// fileObject.seekg( n, ios::end );
// // 定位到 fileObject 的末尾
// fileObject.seekg( 0, ios::end );
#include <iostream>
#include <fstream>

using namespace std;

void wirteFile()
{
    ofstream fout("./test", ios::out);
    if (fout.is_open())
    {
        fout << "前不久看到一句话挺喜欢的" << endl;
        fout << "也许你现在所做的事情看不到成果" << endl;
        fout << "但是不要害怕，你并不是没有成长" << endl;
        fout << "而是在扎根!" << endl;
    }
    else
    {
        cerr << "文件打开失败" << endl;
    }

    fout.close();
}

void readFile()
{
    ifstream fin("./test", ios::in);
    if (fin.is_open())
    {
        string str;
        while (fin >> str) // 不会读取换行符
        {
            cout << str << endl;
        }
    }
    else
    {
        cerr << "文件打开失败" << endl;
    }

    fin.close();
}

void readFile2()
{
    ifstream fin("./test", ios::in);
    if (fin.is_open())
    {
        string str;
        while (fin.eof() == false) // 不会读取换行符
        {
            getline(fin, str);
            cout << str << endl;
        }
    }
    else
    {
        cerr << "文件打开失败" << endl;
    }

    fin.close();
}

int main(int argc, char *argv[])
{
    wirteFile();
    readFile();
    readFile2();

    return 0;
}