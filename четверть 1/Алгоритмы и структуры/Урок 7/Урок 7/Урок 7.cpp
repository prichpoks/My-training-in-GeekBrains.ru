//Алгоритмы и структуры данных.
//Урок 7
//Корнилов Сергей

#include <iostream>
#include <ctime>

// Создание и заполнение масива
int* createarr(int i)
{
    int* p = new int[i];
    srand(time(0));
    for (int c = 0; c < i; c++)
        p[c] = rand() % 100;
    return p;
}

//Вывод масива
void printarr(int* p, int i)
{
    for (int c = 0; c < i; c++)
        std::cout << p[c] << "; ";
}

// Сортировка вставками
void psort(int* arr, int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        int j = i;
        while(j > l && arr[j - 1] > arr[j])
        {
            int tmp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = tmp;
            j--;
        }
    }
}

// Нахождение медианы
int med(int* p, int b, int c)
{
    int a = b + c / 2;
    if (p[a] >= p[b])
    {
        if (p[c] > p[a])
            return a;
        return (p[b] >= p[c]) ? b : c;
    }
    if (p[c] >= p[b])
        return b;
    return (p[a] >= p[c]) ? a : c;
}

//Задание 1
int bqsort(int* p, int left, int right)
{
    if (right - left <= 10)
    {
        psort(p, left, right);
    }
    else
    {
        int l, r, m, sw;
        l = left;
        r = right;
        sw = p[m = med(p, l, r)];
        p[m] = p[(l + r) / 2];
        p[(l + r) / 2] = sw;
        m = p[(l + r) / 2];
        do
        {


            while (p[l] < m) l++;
            while (p[r] > m) r--;
            if (l <= r)
            {
                sw = p[l];
                p[l] = p[r];
                p[r] = sw;
                l++;
                r--;
            }
        } while (l <= r);
        bqsort(p, l, right);
        bqsort(p, left, r);
    }
    return 0;
}

// Задание 2
void bSort(int* p, int len)
{
    int** bks = new int * [10];
    for (int i = 0; i < 10; i++)
        bks[i] = new int[len + 1];
    for (int i = 0; i < 10; i++)
        bks[i][len] = 0;
    for (int di = 1; di < 1000000000; di *= 10)
    {
        for (int i = 0; i < len; i++)
        {
            if (p[i] % 2 == 0)
            {
                int d = (p[i] / di) % 10;
                bks[d][bks[d][len]++] = p[i];
                p[i] = -1;
            }
        }
        int idx = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < bks[i][len]; j++)
            {
                while (p[idx] != -1)
                    idx++;
                p[idx] = bks[i][j];
            }
            bks[i][len] = 0;
        }
    }
    for (int i = 0; i < 10; i++) 
    {
        delete[]bks[i];
    }
    delete[]bks;
}


int main()
{
    int i, * p;
    std::cout << "Enter number for arr: ";
    std::cin >> i;

    p = createarr(i);
    printarr(p, i);
    bSort(p, i);
    std::cout << "\n\nsort mas\n";
    printarr(p, i);
    delete[] p;
}