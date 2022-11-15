
#include <iostream>


// задание 1
void decinbin(int d)
{
    if (d > 0)
    {
        decinbin(d / 2);
        std::cout << d % 2;
    }
}

// задание 2.1
long m_pow(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return a *= m_pow(a, b - 1);
        
}

// ЗАДАНИЕ 2.2
long my_pow(int a, int b)
{
    if (b == 0)
        return 1;
    else
    {
        if (b % 2 == 0)
        {
            return my_pow(a * a, b / 2);
        }
        else
            return a *= my_pow(a, b - 1);
    }
}

// Задание 3

int** createboard(int y, int x)
{
    int x1, y1;
    
    int** board = new int* [y];
    for (int i = 0; i < y; i++)
    {
        board[i] = new int[x];
    }
    for (int i = 0; i < y; i++)
    {
        for (int c = 0; c < x; c++)
        {
            board[i][c] = 0;
        }
    }
    int p = 0;
    while (p != 911)
    {
        std::cout << "enter the x coordinate of the obstacle = ";
        std::cin >> x1;
        std::cout << "enter the y coordinate of the obstacle = ";
        std::cin >> y1;
        if (x1 > 0 && x1 < x && y1 > 0 && y1 < y)
        {
            board[y1 - 1][x1 - 1] = 1;
            std::cout << "obstacle created\n";
        }
        std::cout << "if you want to finish, dial 911\n";
        std::cin >> p;
    }
    return board;
}

int numberpaths(int** board, int y, int x)
{
    if (y == 0 && x == 0)
        return 0;
    if ((y == 0 || x == 0) && board[y][x] != 1)
        return 1;
    if (board[y][x] != 1)
        return numberpaths(board, y - 1, x) + numberpaths(board, y, x - 1);
    else
        return 0;
}

void printboard(int** board, int y, int x)
{

    for (int i = 0; i < y; i++)
    {
        for (int c = 0; c < x; c++)
        {
            std::cout << "  " << board[i][c];
        }
        std::cout << "  \n";
    }
}
void printboard1(int** board, int y, int x)
{

    for (int i = 0; i < y; i++)
    {
        for (int c = 0; c < x; c++)
        {
            if (board[i][c] == 1)
                std::cout << "  0";
            else
                std::cout << "  " << numberpaths(board, i, c);
        }
        std::cout << "  \n";
    }
}

int main()
{
    int a = 4, b = 4, d;
    std::cout << "enter number: ";
    std::cin >> d;
    decinbin(d);
    std::cout << "res = " << my_pow(a, b);
    int x, y, ** board;
    std::cout << "enter length = ";
    std::cin >> x;
    std::cout << "enter width = ";
    std::cin >> y;
    board = createboard(y, x);
    printboard(board, y, x);
    std::cout << numberpaths(board, 5, 6) << "\n";
    printboard1(board, y, x);
    return 0;
}