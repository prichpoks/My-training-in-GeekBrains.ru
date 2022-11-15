

#include <iostream>
using namespace std;
// TASK 1
bool printMas(int* a, int b)
{
    if (b < 1)
        return false;
    int i = 0;
    while (i < b)
    {
        cout << a[i] << '\n';
        i++;
    }
    return true;
}


// TASK 2

bool chanMas(int* a, int b)
{
    if (b < 1)
        return false;
    int i = 0;
    while (i < b)
    {
        if (a[i] == 0)
            a[i] = 1;
        else
            a[i] = 0;
        cout << a[i] << '\n';
        i++;
    }
    return true;

}

// TASK 3
void enterMas(int* a)
{
    int i = 1;
    while (i < 23)
    {
        *a = i;
        i += 3;
        a++;
    }
    
}

// TASK 4
void slideMas(int* a, int n)
{
    int p, i, ic;

    if (n > 0)
    {
        i = 0;
        while (i < n)
        {
            ic = 0;
            p = a[n - 1];
            while (ic < n - 1)
            {
                a[n -1] = a[ic];
                a[ic] = p;
                ic++;
                p = a[ic];
                a[ic] = a[n -1];
                
            }
            i++;
        }
    }
    if (n < 0)
    {
        n *= -1;
        i = n - 1;
        while (i > 0)
        {
            ic = n - 1;
            p = a[0];
            while (ic < 0)
            {
                a[0] = a[ic];
                a[ic] = p;
                ic--;
                p = a[ic];
                a[ic] = a[0];
            }
            i--;
        }
    }
}

// TASK 5
bool checkBalance(int* m, int n)
{
    int res1, res2, i = 1, ic;

    while (i < n)
    {
        res1 = res2 = 0;
        ic = 0;
        while (ic < i)
        {
            res1 += m[ic];
            ic++;
        }
        while (ic < n)
        {
            res2 += m[ic];
            ic++;
        }
        i++;
        if (res1 == res2)
            return true;
    }
    return false;
}
int main()
{
    int a[8] = { 1,3,0,1,3,4,0,0 };
    bool res;
    chanMas(a, 8);
    cout << "\n\n";
    enterMas(a);
    printMas(a, 8);
    cout << "\n\n";
    int b[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    slideMas(b, -12);
    printMas(b, 12);
    cout << "\n\n";
    int s[8] = { 1,5,1,2,1,-3,3,4 };
    cout << checkBalance(s, 8);
    return 0;
}   