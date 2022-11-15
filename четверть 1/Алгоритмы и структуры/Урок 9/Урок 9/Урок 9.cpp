// Алгоритмы и структуры данных
// Урок 9
// Корнилов Сергей

#include <iostream>

//Задание 1
const int sz = 10;

// эллемент очереди
struct node {
    int pr;
    int date;
};

// очередь
node* arr[sz];
int tail = -1;


// добавление в очередь
void ins(int pr, int date)
{
    if (tail < sz)
    {
        node* p = new node;
        p->pr = pr;
        p->date = date;
        arr[++tail] = p;
    }      
    else
        std::cout << "Queue overflow!\n";
}

// взятие из очереди
node* rem()
{
    if (tail == -1)
    {
        node* p = new node;
        p->pr = 0;
        p->date = 0;
        std::cout << "the queue is empty!\n";
        return p;
        
    }
    node* p = arr[0];
    int j = 0;
    for (int i = 1; i <= tail; i++)
    {
        if (p->pr < arr[i]->pr)
        {
            p = arr[i];
            j = i;
        }
    }
    node* tmp = arr[j];
    arr[j] = arr[tail];
    arr[tail] = tmp;
    tail--;
    return p;
}

// вывод очереди очереди
void printq(node* arr[])
{
    std::cout << "\n{ ";
    for (int i = 0; i < sz; i++)
    {
        if (i > tail)
            std::cout << "[X, X] ";
        else
            std::cout << "[" << arr[i]->pr << ", " << arr[i]->date << "] ";
            
    }
    std::cout << "}\n";
}

// Задание 2
const int s = 40;
char stack[s];
int cursor = -1;

// добовление в стек
bool push(char date)
{
    if (cursor < s)
    {
        stack[++cursor] = date;
        return true;
    }
    else
    {
        std::cout << "stack overflow\n";
        return false;
    }
}

// удаление из стека
char pop()
{
    if (cursor == -1)
    {
        std::cout << "the stack is empty\n";
        return -1;
    }
    else
        return stack[cursor--];
}

// перевод числа из десятичной в двоичную систему. 
void decinbin()
{
    int dec, dec1;
    std::cout << "Enter dec please: ";
    std::cin >> dec;
    dec1 = dec;
    while (dec > 0)
    {
        (dec % 2 == 0) ? push('0') : push('1');
        dec /= 2;
    }
    std::cout << "\nBIN nbr: ";
    while (dec1 > 0)
    {
        std::cout << pop();
        dec1 /= 2;
    }
}
int main()
{
    std::cout << "\n\nEXERCISE 1\n";
    node* p;
    printq(arr);
    ins(1, 120);
    ins(55, 110);
    ins(2, 130);
    ins(15, 140);
    ins(16, 20);
    printq(arr);
    p = rem();
    std::cout << p->pr << ", " << p->date <<"\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    printq(arr);
    ins(1, 120);
    ins(3, 110);
    ins(22, 130);
    ins(15, 140);
    ins(16, 20);
    printq(arr);
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    printq(arr);
    ins(1, 120);
    ins(37, 110);
    ins(22, 130);
    ins(15, 140);
    ins(16, 20);
    ins(21, 120);
    ins(31, 110);
    ins(22, 130);
    ins(15, 140);
    ins(16, 20);
    ins(31, 110);
    ins(22, 130);
    ins(15, 140);
    ins(16, 20);
    printq(arr);
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    p = rem();
    std::cout << p->pr << ", " << p->date << "\n";
    delete p;
    printq(arr);
    std::cout << "\n\nEXERCISE 2\n\n";
    decinbin();
    return 0;
}

