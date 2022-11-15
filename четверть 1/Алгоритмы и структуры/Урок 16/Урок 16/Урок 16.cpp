// Алгоритмы и структуры данных
// Урок 16
// Корнилов Сергей

#include <iostream>
#include <cstring>
#include <string.h>

// Задание 1
void CCode(char* str, int offset, int status)
{
   int i = 0;
   if (status == 0)
   {
       while (str[i])
       {
           if (str[i] > 95 && str[i] < 123)
           {
               str[i] = (str[i] + offset - 96) % 26 + 96;
           }
           if (str[i] > 64 && str[i] < 91)
           {
               str[i] = (str[i] + offset - 65) % 26 + 65;
           }
           i++;
       }
   }
   else
   {
       while (str[i])
       {
           if (str[i] > 95 && str[i] < 123)
           {
               str[i] = (str[i] - offset - 96) % 26 + 96;

           }
           if (str[i] > 64 && str[i] < 91)
           {
               str[i] = (str[i] + offset - 65) % 26 + 65;
           }
           i++;
       }
   }
}

// Задание 2
char* Change_Code(char* str, int colu, int status)
{
    int len = strlen(str);
    int step;
    char* ptr;
    int first_step = 0;
    int second_step;
    int count = 0;
    if (!status)
    {
        if (len % (colu + 1))
        {
            step = len / (colu + 1) + 1;
        }
        else
        {
            step = len / (colu + 1);
        }
        ptr = (char*)malloc(sizeof(char) * step * (colu + 1) + 1);
        while (first_step < colu + 1)
        {
            second_step = first_step;
            while (second_step < len)
            {
                ptr[count] = str[second_step];
                count++;
                second_step += colu + 1;
            }
            if ((count) % step)
            {
                ptr[count++] = 'x';
            }
            first_step++;
        }
        ptr[count] = 0;
        return ptr;
    }
    else
    {
        step = len / (colu + 1);
        ptr = (char*)malloc(sizeof(char) * step * (colu + 1) + 1);
        while (first_step < step)
        {
            second_step = first_step;
            while (second_step < len)
            {
                ptr[count] = str[second_step];
                count++;
                second_step += step;
            }
            first_step++;
        }
        ptr[count] = 0;
        return ptr;
    }
    return 0;
}
int main()
{
    char str[20];
    char* ptr, *ptr1;
    strncpy_s(str, "hai, super", 10);
    std::cout << "EX #1\n";
    CCode(str, 4, 0);
    std::cout << str << '\n';
    CCode(str, 4, 1);
    std::cout << str << '\n';
    std::cout << "\n\nEX #2\n";
    ptr = Change_Code(str, 2, 0);
    std::cout << ptr << '\n';
    ptr1 = Change_Code(ptr, 2, 1);
    std::cout << ptr1 << '\n';
    free(ptr);
    free(ptr1);
}
