#include <iostream>

template <class T>
void mSwap(T &val, T &val2)
{
    T temp = val;
    val = val2;
    val2 = temp;
}

template <class T>
void selectSort(T arr[], int len)
{
    for (int i = 0; i < len - 1; ++i)
    {
        // jia ding zui da zhi
        int max = i;
        for (int j = i + 1; j < len; ++j)
        {
            if (arr[max] > arr[j])
            {
                max = j;
            }
        }
        if (max != i)
        {
            // max shi j he i jiao huan
            mSwap(arr[max], arr[i]);
        }
    }
}

template <class T>
void display(T arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    int arr[] = {3, 4, 5, 1, 2, 6, 1, 7, 8, 6, 32, 2};

    int len = sizeof(arr) / sizeof(int);

    display<int>(arr, len);

    selectSort<int>(arr, len);

    display<int>(arr, len);

    return 0;
}