
#include <fstream>
#include <iostream>
#include "myLIB.h"


// TASK 2
#define NBRRES(x, y) if (x > -1 && x < y) std::cout << "true\n"; else std::cout << "false\n"

//TASK 3 
#define SIZE 5
#define SwapINT(a, b, c) (c) = (a); (a) = (b); (b) = (c)

void booblsort(int* arr, int size)
{
    int elem = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = (size - 1); j >= (i + 1); j--)
        {
            if (arr[j] < arr[j - 1])
            {
               // elem = arr[j];
                //arr[j] = arr[j - 1];
                //arr[j - 1] = elem;
                SwapINT(arr[j], arr[j - 1], elem);
            }
        }
    }
}
void inmas(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "enet nbr\n";
        std::cin >> arr[i];
    }
}

void  printmasi(int *mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << mas[i] << ' ';
    }
    std::cout << '\n';
}

//TASK4
#define N 5
#pragma pack(push, 1)
struct Worker
{
     char name[22];
     int age;
     bool mstatus;
};
#pragma pack(pop)

void initS(struct Worker* s)
{
    std::cout << "name worker - \n";
    std::cin >> s->name;
    std::cout << "age worker - \n";
    std::cin >> s->age;
    std::cout << "mstatus worker - true|false\n";
    std::cin >> s->mstatus;
}

void prints(struct Worker *s)
{
    std::cout << "name worker - " << s->name << '\n';
    std::cout << "age worker - " << s->age << '\n';
    if (s->mstatus)
        std::cout << "mstatus worker - true\n";
    else
        std::cout << "mstatus worker - false\n";
}

int main()
{
    float mas[6];
    //TASK1/TASK5
    myLib::createmas(mas, 6);
    myLib::printmas(mas, 6);
    myLib::summas(mas, 6);

    //TASK2
    int x, y;
    std::cout << "Enter x\n";
    std::cin >> x;
    std::cout << "Enter y\n";
    std::cin >> y;
    NBRRES(x, y);

    //TASK3
    int arr[SIZE];
    inmas(arr, SIZE);
    booblsort(arr, SIZE);
    printmasi(arr, SIZE);

    //TASK4
    struct Worker *s;
    s = new struct Worker;

    initS(s);
    prints(s);
    std::ofstream fout("data.txt");
    fout << "name worker - " << s->name << '\n';
    fout << "age worker - " << s->age << '\n';
    if (s->mstatus)
        fout << "mstatus worker - true\n";
    else
        fout << "mstatus worker - false\n";
    fout.close();
    delete s;

    return 0;
}

