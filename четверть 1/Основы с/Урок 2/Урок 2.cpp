// Урок 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    /*ЗАДАНИЕ 1*/
    short int a = 213;
    int b = 12903;
    long long c = 2121233;
    char d = 'a';
    bool e = true;
    float f = 3.54f;
    double g = 3.42445;

    /*ЗАДАНИЕ 2*/
    enum game {vvoid, zero, cross};
    enum game tic_tac_toe;
    tic_tac_toe = zero;
    

    /*ЗАДАНИЕ 3*/
    short int mgame[3];
    mgame[0] = 0;
    mgame[1] = 1;
    mgame[2] = 2;

    /*ЗАДАНИЕ 4*/
    struct cgame
    {
        int box1[3][3]; // поле для игры
        char p1[33];    // имя игрока 1
        char p2[33];    // имя игрока 2
    };
    
    /*ЗАДАНИЕ 5*/
    union MyData
    {
        int ia;
        float fa;
        char cha;
    };
    struct MyVariant
    {
        union MyData x;
        int isInt : 1;
        int isFloat : 1;
        int isChar : 1;
    };

    struct MyVariant l;
    l.x.ia = 43;
    l.isInt = 0;
    l.isFloat = 0;
    l.isChar = 1;

    int test = 1;
    /*Пример*/
   // if (l.isInt == 0)
     //   printf("MyData = %c", l.x.cha);
    //if (l.isFloat == 0)
       // printf("MyData = %f", l.x.fa);
    //if (l.isChar)
      //  printf("MyData = %c", l.x.cha);
    return 0;
}
