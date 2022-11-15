// Алгоритмы и структуры данных
// Урок 15 
// Корнилов Сергей

#include <iostream>

// Задание 1
int hfun(const char* str)
{
    int res = 0; 
    for (int i = 0; str[i] != 0; i++)
    {
        res = res + str[i] * pow(26, i);
    }
    return res;
}

// Задание 2 
int galg(int* p, int l, int n)
{
    int res = 0;
    int i = 0;
    int res1 = 0;
    while (res < n)
    {
        while (res + p[i] > n)
        {
            i++;
        }
        res += p[i];
        res1++;
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
    return res1;
}

int main()
{
     std::cout << hfun("PI") << std::endl;
     int p[] = {50, 10, 5, 2, 1};
     std::cout << galg(p, 5, 98);

}
