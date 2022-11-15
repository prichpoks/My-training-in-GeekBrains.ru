#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>

using namespace std;

enum Cell
{
    CROSS = 'X',
    ZERO  = '0',
    EMPTY = '_'
};

struct Coord
{
    size_t y;
    size_t x;
};

enum Progress
{
    IN_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW
};

#pragma pack(push, 1)
struct Game
{
    Cell** ppField = nullptr;
    const size_t SIZE = 3;
    Progress progress = IN_PROGRESS;
    Cell ai;
    Cell human;
    size_t turn = 0;
};
#pragma pack(pop)

inline void clearScr()
{
    system("cls");
}

int32_t __fastcall getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}


void __fastcall initGame(Game& g)
{
    g.ppField = new Cell * [g.SIZE];
    for (size_t i = 0; i < g.SIZE; i++)
    {
        g.ppField[i] = new Cell[g.SIZE];
    }
    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            g.ppField[y][x] = EMPTY;
        }
    }
    if (getRandomNum(0, 1000) > 500)
    {
        g.ai = CROSS;
        g.human = ZERO;
        g.turn = 1;
    }
    else
    {
        g.ai = ZERO;
        g.human = CROSS;
        g.turn = 0;
    }
}

void __fastcall printGame(const Game& g)
{
    cout << "    ";
    for (size_t i = 0; i < g.SIZE; i++)
    {
        cout << i + 1 << "   ";
    }
    cout << endl;
    for (size_t y = 0; y < g.SIZE; y++)
    {
        cout << y + 1 << " | ";
        for (size_t x = 0; x < g.SIZE; x++)
        {
           cout <<  (char)g.ppField[y][x] << " | ";
        }
        cout << endl;
    }
    cout << endl << "Human: " << (char)g.human << endl;
    cout << "Ai: " << (char)g.ai << endl << endl;
}

void __fastcall deinitGame(Game& g)
{
    for (size_t i = 0; i < g.SIZE; i++)
    {
       delete[]  g.ppField[i];
    }
    delete[] g.ppField;
    g.ppField = nullptr;
}

Progress __fastcall getWon(Game& g)
{
    for (size_t i = 0; i < g.SIZE; i++)
    {
        if (g.ppField[i][0] == g.ppField[i][1] && g.ppField[i][0] == g.ppField[i][2])
        {
            if (g.ppField[i][0] == g.human)
                return WON_HUMAN;
            if (g.ppField[i][0] == g.ai)
                return WON_AI;
        }
        if (g.ppField[0][i] == g.ppField[1][i] && g.ppField[0][i] == g.ppField[2][i])
        {
            if (g.ppField[0][i] == g.human)
                return WON_HUMAN;
            if (g.ppField[0][i] == g.ai)
                return WON_AI;
        }
    }
    if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2])
    {
        if (g.ppField[0][0] == g.human)
            return WON_HUMAN;
        if (g.ppField[0][0] == g.ai)
            return WON_AI;
    }
    if (g.ppField[0][2] == g.ppField[1][1] && g.ppField[0][2] == g.ppField[2][0])
    {
        if (g.ppField[0][2] == g.human)
            return WON_HUMAN;
        if (g.ppField[0][2] == g.ai)
            return WON_AI;
    }

    bool draw = true;
    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                draw = false;
                break;
            }
        }
        if (!draw)
            break;
    }
    if (draw)
        return DRAW;

    return IN_PROGRESS;
}


Coord __fastcall getCoordHuman(Game& g)
{
    Coord c;
    do
    {
        cout << "Enter y coord: ";
        cin >> c.y;
        cout << endl;
        cout << "Enter x coord: ";
        cin >> c.x;
        cout << endl;

    } while (c.y == 0 || c.y > 3 || c.x == 0 || c.x > 3 || g.ppField[c.y - 1][c.x - 1] != EMPTY);
    c.y--;
    c.x--;
    return c;
}


Coord _fastcall getCoordAi(Game& g)
{
    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] = g.ai;
                if (getWon(g) == WON_AI)
                {
                    g.ppField[y][x] = EMPTY;
                    return { y,x };
                }
                g.ppField[y][x] = EMPTY;
            }
        }
    }

    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] = g.human;
                if (getWon(g) == WON_HUMAN)
                {
                    g.ppField[y][x] = EMPTY;
                    return { y,x };
                }
                g.ppField[y][x] = EMPTY;
            }
        }
    }
    //умный ход
    if (g.ppField[0][0] == g.ai)
        return { 2,2 };
    if (g.ppField[0][0] == g.ai && g.ppField[2][2] == g.ai)
        return { 0,2 };

    if (g.ppField[0][2] == g.ai)
        return { 2,0 };
    if (g.ppField[0][2] == g.ai && g.ppField[2][0] == g.ai)
        return { 2,2 };
    
    if (g.ppField[2][2] == g.ai)
        return { 0,2 };
    if (g.ppField[0][2] == g.ai && g.ppField[2][2] == g.ai)
        return { 2,0 };

    //================================================================
    if (g.ppField[1][1] == EMPTY)
        return { 1,1 };
    
    Coord arr[4];
    size_t count = 0;
   

    if (g.ppField[0][0] == EMPTY)
    {
        arr[count] = { 0,0 };
        count++;
    }
    if (g.ppField[2][2] == EMPTY)
    {
        arr[count] = { 2,2 };
        count++;
    }
    if (g.ppField[0][2] == EMPTY)
    {
        arr[count] = { 0,2 };
        count++;
    }
    if (g.ppField[2][0] == EMPTY)
    {
        arr[count] = { 2,0 };
        count++;
    }
    if (count > 0)
    {
        size_t index = getRandomNum(0, 1000) % count;
        return arr[index];
    }

    if (g.ppField[0][1] == EMPTY)
    {
        arr[count] = { 0,1 };
        count++;
    }
    if (g.ppField[2][1] == EMPTY)
    {
        arr[count] = { 2,1 };
        count++;
    }
    if (g.ppField[1][2] == EMPTY)
    {
        arr[count] = { 1,2 };
        count++;
    }
    if (g.ppField[1][0] == EMPTY)
    {
        arr[count] = { 1,0 };
        count++;
    }
    if (count > 0)
    {
        size_t index = getRandomNum(0, 1000) % count;
        return arr[index];
    }

}


void __fastcall congrats(Game & g)
{
    if (g.progress == WON_HUMAN)
    {
        cout << "Human Won! :)" << endl;
    }
    else if (g.progress == WON_AI)
    {
        cout << "AI Won! :/" << endl;
    }
    else if (g.progress == DRAW)
    {
        cout << "Draw! :(" << endl;
    }
}

int main()
{
    Game g;
    initGame(g);
    Coord c;

    clearScr();
    printGame(g);

    do
    {
        if (g.turn % 2 == 0)
        {
            c = getCoordHuman(g);
            g.ppField[c.y][c.x] = g.human;
        }
        else
        {
            c = getCoordAi(g);
            g.ppField[c.y][c.x] = g.ai;
        }
        g.turn++;  
        clearScr();
        printGame(g);
        g.progress = getWon(g);
    } while (g.progress == IN_PROGRESS);
    congrats(g);
    deinitGame(g);
    return 0;
}

