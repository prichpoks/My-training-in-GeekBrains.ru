// Корнилов Сергей
// Группа 1861
// С++ Сложные моменты
// Урок 2
#include <iostream>
#include <vector>
#include<algorithm>
#include "Time.h"
#include <fstream>

// Задание 1
template<typename T>
void Swap(T **t1, T **t2)
{
    T** ptr = new char*;
    *ptr = *t1;
    *t1 = *t2;
    *t2 = *ptr;
    delete[] ptr;
}

// Задание 2
template <class T>
void SortPointer(T *arr)
{
    sort(arr->begin(), arr->end(), [](int *p1 , int *p2) {return *p1 < *p2; });
}

// Задание 3
size_t CountWarAndPeace1()
{
    Timer timer("Count_if+Find");
    std::vector<char> vstr;
    char ch;
    std::ifstream file("WAP.txt");
    while (!file.eof())
    {
        file.get(ch);
        vstr.push_back(ch);
    }
    size_t size = std::count_if(vstr.begin(), vstr.end(), [](char ch)
        {
            std::string str = "AaEeIiOoUuYy";
            std::string str2;
            str2 =+ ch;
            if (std::string::npos != str.find(str2))
            {
                //std::cout << ch << ' ';
                return true;
            }
            return false;
        });

    timer.print();
    return size;
}

size_t CountWarAndPeace2()
{
    Timer timer("Count_if+For");
    std::vector<char> vstr;
    char ch;
    std::ifstream file("WAP.txt");
    while (!file.eof())
    {
        file.get(ch);
        vstr.push_back(ch);
    }
    size_t size = std::count_if(vstr.begin(), vstr.end(), [](char ch)
        {
            std::string str = "AaEeIiOoUuYy";
            size_t size = str.size();
            for (int i = 0; i < size; i++)
            {
                if (str[i] == ch)
                    return true;
            }
            return false;
        });

    timer.print();
    return size;
}

size_t CountWarAndPeace3()
{
    Timer timer("for+Find");
    std::string str = "AaEeIiOoUuYy";
    std::string str2;
    std::vector<char> vstr;
    size_t res = 0, size;
    char ch;
    std::ifstream file("WAP.txt");
    while (!file.eof())
    {
        file.get(ch);
        vstr.push_back(ch);
    }
    size = vstr.size();
    for (int i = 0; i < size; i++)
    {
        str2 = +vstr[i];
        if (std::string::npos != str.find(str2))
        {
            res++;
        }
    }
    timer.print();
    return res;
}

size_t CountWarAndPeace4()
{
    Timer timer("for+for");
    std::string str = "AaEeIiOoUuYy";
    std::string str2;
    std::vector<char> vstr;
    size_t res = 0, size,size2 = str.size();
    char ch;
    std::ifstream file("WAP.txt");
    while (!file.eof())
    {
        file.get(ch);
        vstr.push_back(ch);
    }
    size = vstr.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (str[j] == vstr[i])
            {
                res++;
            }
        }
    }
    timer.print();
    return res;
}
int main()
{
    /*char* ptr1 = new char('f');
    char* ptr2 = new char('h');
    Swap(&ptr1,& ptr2);
    std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl;*/
    /*int a = 11, b = 12, c = 44, d = 7, e = 22;
    std::vector<int*> inter;
    inter.push_back(&a);
    inter.push_back(&b);
    inter.push_back(&c);
    inter.push_back(&d);
    inter.push_back(&e);
    SortPointer(&inter);
    for (int i = 0; i < inter.size(); i++)
    {
        std::cout << *inter[i] << '\n';
    }*/

    std::cout << CountWarAndPeace1() << std::endl;

    std::cout << CountWarAndPeace2() << std::endl;
    std::cout << CountWarAndPeace3() << std::endl;
    std::cout << CountWarAndPeace4() << std::endl;
}

