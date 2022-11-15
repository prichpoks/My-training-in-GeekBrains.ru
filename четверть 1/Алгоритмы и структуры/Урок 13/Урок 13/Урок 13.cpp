// Алгоритмы и структуры данных
// Урок 13
// Корнилов Сергей



#include <iostream>
// Задание 1
const int n = 6;
int pip[n][n] = 
{
    {0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0},

};
struct node
{
    int date;
    node* next;
};

struct Stack
{
    node* hade;
    int size;
};

// Добавление в стек
bool push(Stack* st, int ch)
{
    node* tmp = new node;
    if (tmp == NULL)
    {
        std::cout << "stack ocerflow!\n";
        return false;
    }
    tmp->next = st->hade;
    tmp->date = ch;
    st->hade = tmp;
    st->size++;
    return true;
}

// Извлечение из стека
int pop(Stack* st)
{
    if (st->size == 0)
    {
        std::cout << "stack is empty!\n";
        return -1;
    }
    int d;
    node* p;
    d = st->hade->date;
    p = st->hade;
    st->hade = st->hade->next;
    st->size--;
    delete p;
    return d;
}
void DeepCrawl(int s)
{
    int i = 0, j = 0;
    Stack stack;
    stack.hade = NULL;
    stack.size = 0;
    int vers[n] = {0};
    push(&stack, s);
    vers[s] = 1;
    std::cout << s << " ";
    while(1)
    {
        if (j == 5 && stack.size > 0)
        {
            //pop(&stack);
            pop(&stack);
            if (stack.size > 0)
                s = stack.hade->date;
            j = -1;
        }
        if (stack.size == 0)
        {
            break;
        }
        j++;
        if (pip[s][j] == 1 && vers[j] != 1)
        {
            std::cout << j << " ";
            s = j;
            push(&stack, s);
            vers[s] = 1;
            j = -1;
        }

       
    }
    
}
// Задание 2
int marr[n] = { 0 };

void robotrec(int x)
{
    marr[x]++;
    for (int r = 0; r < n; r++)
    {
        if (pip[x][r] == 1 && marr[r] > 0)
            marr[r]++;
        if (pip[x][r] == 1 && marr[r] == 0)
            robotrec(r);
        
    }
}
void robomtrix()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (pip[j][i] == 1)
                marr[i]++;
    }
}
void robot(int x)
{
    robotrec(x);
    for (int i = 0; i < n; i++)
    {
        std::cout << static_cast<char> (i + 65) << " = " << marr[i] << "\n";
    }
    for (int i = 0; i < n; i++)
    {
        marr[i] = 0;
    }
    robomtrix();
    for (int i = 0; i < n; i++)
    {
        std::cout << static_cast<char> (i + 65) << " = " << marr[i] << "\n";
    }

    
}
int main()
{
    DeepCrawl(0);
    std::cout << "\n\n";
    DeepCrawl(1);
    std::cout << "\n\n";
    DeepCrawl(2);
    std::cout << "\n\n";
    robot(2);
}