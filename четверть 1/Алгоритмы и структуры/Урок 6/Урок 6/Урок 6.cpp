#include <iostream>


// ЗАдание 1
void bsort2m(int **m, int l, int s)
{
    int a, x, y, z, so, ls; 
  
    
    ls = l * s;
    for (int i = 0; i < ls; i++)
    {
        x = y = z = 0;
        a = 1;
        for (int j = 0; j < ls -1; j++)
        {
            std::cout << m[y][x] << " + " << m[z][a] << "\n";
            if (m[y][x] > m[z][a])
            {
                so = m[y][x];
                m[y][x] = m[z][a];
                m[z][a] = so;
            }
            x++;
            a++;
            if (x % 3 == 0)
            {
                y++;
                x = 0;
            }
            if (a % 3 == 0)
            {
                z++;
                a = 0;
            }
        }
    }
}

void printmas(int **m, int l, int s)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < s; j++)
        {
            std::cout << " " << m[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void createm(int **m, int l, int s)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < s; j++)
        {
            std::cout << "Enter number mas = ";
            std::cin >> m[i][j];
        }
    }
}

// Задание 2
void atpk(void)
{
    int p[11];
    for (int i = 10; i  > -1; i--)
    {
        std::cout << "Enter nbr";
        std::cin >> p[i];
    }
    for (int i = 0; i < 11; i++)
    {
        if ((sqrt(fabs(p[i])) + 5 * pow(p[i], 3)) > 400)
            std::cout << i << " - element > 400!!!\n";
    }
}
int main()
{
    int** m = new int*[3];
    for (int i = 0; i < 3; i++)
        m[i] = new int[3];
    createm(m, 3, 3);  
    printmas(m, 3, 3);
    std::cout << "\n";
    bsort2m(m, 3, 3);
    printmas(m, 3, 3);
    atpk();
}

