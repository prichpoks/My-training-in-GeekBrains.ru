// Алгоритмы и структуры данных
// Урок 10
// Корнилов Сергей


#include <iostream>
/////////////////////////////////////////////////////////////////////////
// Задание 1
struct node 
{
    char date;
    node* next;
};

struct list
{
    node* hade;
    int size;
};

// Добавление в стек
bool push(list* st, char ch)
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

// Извлечение ищ стека
char pop(list* st)
{
    if (st->size == 0)
    {
        std::cout << "stack is empty!\n";
        return -1;
    }
    char d;
    node* p;
    d = st->hade->date;
    p = st->hade;
    st->hade = st->hade->next;
    st->size--;
    delete p;
    return d;
}

//функция проверки последовательности 
bool checkseq(char *p, int sz)
{
    if (sz % 2 != 0)
    {
        std::cout << "not true!\n";
        return false;
    }
    list* st = new list;
    if (st == NULL)
    {
        std::cout << "memori is empty!\n";
        return false;
    }
    st->hade = NULL;
    st->size = 0;
    for (int i = 0; i < sz; i++)
    {
        if (p[i] == '{' || p[i] == '[' || p[i] == '(')
        {
            bool check = push(st, p[i]);
            if (check == false)
            {
                while (st->size)
                    pop(st);
                delete st;
                std::cout << "not true!\n";
                return false;
            }
        }
        else if (p[i] == '}' || p[i] == ']' || p[i] == ')')
        {
            char ch = pop(st);
            if (p[i] - ch > 2)
            {
                if (ch == -1)
                {
                    std::cout << "not true!\n";
                    return false;
                }
                while (st->size)
                    pop(st);
                delete st;
                std::cout << "not true!\n";
                return false;
            }
        }
    }
    if (st->size != 0)
    {
        while (st->size)
            pop(st);
        delete st;
        std::cout << "not true!\n";
        return false;
    }
    std::cout << "right!\n";
    delete st;
    return true;
    

}
///////////////////////////////////////////////////////////////////////////////
// Задание 2

// вывести список
void printlist(list* p)
{
    node* tmp;
    tmp = p->hade;
    for(int i = 0; i < p->size; i++)
    {
        std::cout << "[" << tmp->date << "] ";
        tmp = tmp->next;
    }
    std::cout << "size - " << p->size;
}

// копирование односвязного списка
list* cplist(list* ls)
{
    if (ls == NULL)
    {
        return NULL;
    }
    else if (ls->size == 0)
    {
        list* p = new list;
        if (p == NULL)
        {
            std::cout << "memori is empty!\n";
            return NULL;
        }
        p->hade = NULL;
        p->size = 0;
        return p;
    }
    else
    {
        list* p = new list;
        if (p == NULL)
        {
            std::cout << "memori is empty!\n";
            return NULL;
        }
        node* tmp = ls->hade;
        node* ne = tmp;
        for (int i = 0; i < ls->size; i++)
        {
            node* n = new node;
            if (n == NULL)
            {
                std::cout << "memori is empty!\n";
                return NULL;
            }
            if (i == 0)
            {
                n->next = NULL;
                n->date = tmp->date;
                ne = n;
                p->hade = n;
                p->size = ls->size;
                tmp = tmp->next;
            }
            else
            {
                ne->next = n;
                n->date = tmp->date;
                n->next = NULL;
                ne = n;
                tmp = tmp->next;
            }
        }
        return p;
    }
}

// Задание 3
bool checksort(list* p)
{
    int fl = 0;
    node* tmp = p->hade;
    while (tmp->next && fl == 0)
    {
        if (tmp->date < tmp->next->date)
            fl = 1;
        if (tmp->date > tmp->next->date)
            fl = -1;
        else
            tmp = tmp->next;
    }
    if (fl == 0)
    {
        std::cout << "\nAll numbers are equal\n";
        return true;
    }
    else if (fl == 1)
    {
        while (tmp->next)
        {
            if (tmp->date > tmp->next->date)
            {
                std::cout << "list NOT Sort!\n";
                return false;
            }
            else
                tmp = tmp->next;
        }
        std::cout << "list is Sort <\n";
        return true;
    }
    else
    {
        while (tmp->next)
        {
            if (tmp->date < tmp->next->date)
            {
                std::cout << "list NOT Sort!\n";
                return false;
            }
            else
                tmp = tmp->next;
        }
        std::cout << "list is Sort >\n";
        return true;
    }
}
int main()
{
    std::cout << "EXERCISE 1\n\n";
    int i;
    std::cout << "enter nbr: ";
    std::cin >> i;
    char* p = new char[i];
    for (int j = 0; j < i; j++)
    {
        std::cout << "enter char: ";
        std::cin >> p[j];
    }
    checkseq(p, i);
    delete[]p;
    
    ///////////////////////////////////////////////////////////////////////////////

    std::cout << "EXERCISE 2\n\n";
    list* po, * pe = new list;
    pe->size = 0;
    pe->hade = NULL;
    push(pe, 'A');
    push(pe, 'C');
    push(pe, '_');
    push(pe, 'A');
    push(pe, 'K');
    std::cout << "\npe\n";
    printlist(pe);
    po = cplist(pe);
    std::cout << "\npo\n";
    printlist(po);
    pop(po);
    push(pe, 'Z');
    std::cout << "\npo\n";
    printlist(po);
    std::cout << "\npe\n";
    printlist(pe);
    char ch;
    std::cout << "\n\n";
    while (ch = pop(po) != -1);
    std::cout << "\n\n";
    while (ch = pop(pe) != -1);
    /////////////////////////////////////////////////////////////////////////////////
   
    std::cout << "\nEXERCISE 3\n\n";
    push(pe, '1');
    push(pe, '2');
    push(pe, '3');
    push(pe, '5');
    push(pe, '5');
    checksort(pe);
    push(pe, '3');
    checksort(pe);
    while (ch = pop(pe) != -1);
    push(pe, '5');
    push(pe, '5');
    push(pe, '3');
    push(pe, '2');
    push(pe, '1');
    checksort(pe);
    while (ch = pop(pe) != -1);
    push(pe, '5');
    push(pe, '5');
    push(pe, '5');
    push(pe, '5');
    push(pe, '5');
    checksort(pe);
    while (ch = pop(pe) != -1);
    delete pe;
    delete po;
}

