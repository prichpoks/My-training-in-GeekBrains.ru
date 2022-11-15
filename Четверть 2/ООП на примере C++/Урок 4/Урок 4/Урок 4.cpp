// ООП на примере С++
// Урок 4
// Корнилов Сергей



#include <iostream>

// Задание 1
int crn(const void *i, const void *a)
{
    return *(int**)i - *(int**)a;
}
class Case
{
public:
    int* p;
    int* pd;
    int i;
    Case() : i(0) {}
    void push_back(int a)
    {

        i++;
        if (i == 0)
        {
            p = new int[i];
            p[0] = a;
        }
        else
        {
            pd = new int[i];
            for (int j = 0; j < i - 1; j++)
                pd[j] = p[j];
            pd[i - 1] = a;
            delete[] p;
            p = pd;
        }
    }
    void push_front(int a)
    {
            i++;
            pd = new int[i];
            for (int j = 1; j < i; j++)
                pd[j] = p[j-1];
            pd[0] = a;
            delete[] p;
            p = pd;
    }
    void pop_back()
    {
        if (i != 0)
        {
            std::cout << "hello!" << std::endl;

            if (i == 1)
            {
                i--;
                delete[]p;
            }
            else
            {
                i--;
                pd = new int[i];
                for (int j = 0; j < i; j++)
                    pd[j] = p[j];
                delete[] p;
                p = pd;
            }
        }
    }
    void pop_front()
    {
        if (i != 0)
        {
            std::cout << "hello" << std::endl;
            if (i == 1)
            {
                i--;
                delete[]p;
            }
            else
            {
                i--;
                pd = new int[i];
                for (int j = 1; j < i + 1; j++)
                    pd[j - 1] = p[j];
                delete[] p;
                p = pd;
            }
        }
    }
    void printCase()
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << this->p[j] << std::endl;
        }
    }
    void sortCase()
    {
        qsort(p, i, sizeof (int), crn);
    }
    ~Case()
    {
        delete[]p;
    }
};

// Задание 2
#include <vector>
#include <set>
class Vectorearr
{
public:
    std::vector <int> arr1;
    std::set <int> arr2;
    Vectorearr() {}
    void createarr(int i, int a)
    {
        this->arr1.clear();
        for(int j = 0; j < i; j++)
        {
            this->arr1.push_back(rand() % a);
        }
    }
    void printarr1()
    {
        int c = this->arr1.size();
        std::cout << "!ARR1!" << std::endl;
        for (int j = 0; j < c; j++)
        {
            std::cout << "[" << arr1[j] << "]; ";
        }
        std::cout << std::endl;
    }
    void printarr2()
    {
        std::cout << "!ARR2!" << std::endl;
        for (auto j : arr2)
        {
            std::cout << "[" << j << "]; ";
        }
        std::cout << std::endl;
    }
    int number_of_unique_numbers()
    {
        this->arr2.clear();
        int c = this->arr1.size();
        for (int j = 0; j < c; j++)
        {
            this->arr2.insert(arr1[j]);
        }
        return arr2.size();
    }
    ~Vectorearr()
    {
        this->arr1.clear();
        this->arr2.clear();
    }
};

//Задание 3
enum Suit { Spades = 1, Hearts, Clubs, Diamonds };
enum Meaning { ace = 1, two, three, four, five, six, seven, eight, nine, ten, JackOrKnave, queen, king };
class Card
{
protected:
    Suit suit;
    Meaning meaning;
    bool position;
public:
    Card(Suit i, Meaning b)
    {
        suit = i;
        meaning = b;
        position = false;
    }
    void Flip()
    {
        if (!position)
            position = 1;
    }
    Meaning GetValue()
    {
        return meaning;
    }

};

class Hand
{
public:
    Hand() {}
    std::vector <Card*> hd;
    void Add(Card* a)
    {
        this->hd.push_back(a);
    }
    void Clear()
    {
        this->hd.clear();
    }
    int GetValue()
    {
        int al = 0;
        int res = 0;
        for (auto i : hd)
        {
            if (i->GetValue() == 1)
                al = 1;
            res += i->GetValue();
        }
        if (al == 1 && res + 10 <= 21)
            res += 10;
        return res;

    }


};
int main()
{
    std::cout << "EXE 1!" << std::endl;
    Case ca;
    ca.push_back(4);
    ca.push_back(3);
    ca.push_back(4);
    ca.push_back(22);
    ca.push_back(4);
    ca.printCase();
    ca.push_front(55);
    ca.push_front(55);
    ca.push_front(99);
    ca.push_front(34);
    ca.push_front(55);
    ca.printCase();
    ca.pop_back();
    ca.pop_front();
    ca.printCase();
    ca.sortCase();
    ca.printCase();
    std::cout << "EXE 2!" << std::endl;
    srand(time(0));
    std::vector <int> arr1;
    Vectorearr vec;
    vec.createarr(15, 10);
    vec.printarr1();
    std::cout << "unique_numbers = " << vec.number_of_unique_numbers()<< std::endl;
    vec.printarr2();
    std::cout << "EXE 3!" << std::endl;
    Card pa(Spades, eight);
    Card ce(Spades, two);
    Card cd(Spades, ace);
    Hand hand;
    hand.Add(&pa);
    hand.Add(&ce);
    hand.Add(&cd);
    std::cout << "Hand Value - " << hand.GetValue() << std::endl;
    Card za(Spades, eight);
    Card ze(Spades, queen);
    Card zd(Spades, ace);
    hand.Clear();
    hand.Add(&za);
    hand.Add(&ze);
    hand.Add(&zd);
    std::cout << "Hand Value - " << hand.GetValue() << std::endl;



}

