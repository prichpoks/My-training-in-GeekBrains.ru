// ООП на примере с++
// Урок 5
// Корнилов Сергей

#include <iostream>

//Задание 1 
template <class T>
class Pair1
{
public:
    T _first, _second;
    Pair1(T ffirst, T ssecond)
    {
        _first = ffirst;
        _second = ssecond;
    }
    T first() const
    {
        return _first;
    }
    T second() const
    {
        return _second;
    }

};

//Задание 2
template <class T1, class T2>
class Pair
{
public:
    T1 _first;
    T2 _second;
    Pair(T1 ffirst, T2 ssecond)
    {
        this->_first = ffirst;
        this->_second = ssecond;
    }
    T1 first() const
    {
        return this->_first;
    }
    T2 second() const
    {
        return this->_second;
    }

};

//Задание 3
//Немогу ВКУРИТЬ((((((((((((((((((((((((
/*template<char T2, typename T2>
class Pair2
{
public:
    char* p;
    T2 _second;
    Pair(char * ffirst, T2 ssecond)
    {
        this->_second = ssecond;
    }
    char* first() const
    {
        return T1;
    }
    T2 second() const
    {
        return this->_second;
    }
};
*/
/*template< typename T2 >
class Pair2<char* , T2> 
{
public:
    T2 _second;
    Pair(T1 ffirst, T2 ssecond)
    {
        this->_second = ssecond;
    }
    char* first() const
    {
        return ffirst;
    }
    T2 second() const
    {
        return this->_second;
    }
};*/

template <char* T1, typename T2>
class StringValuePair : public Pair<T1,T2>
{
public:
    StringValuePair(char ffirst, T2 ssecond)
    {
        Pair(T1 ffirst, T2 ssecond)
    }
};

template <typename T2>
class StringValuePair<char*, T2> : public Pair
{
public:
    StringValuePair(T1 ffirst, T2 ssecond)
    {
        Pair(T1 ffirst, T2 ssecond)
    }
};

//Задание 4
#include <vector>
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
class GenericPlayer : public Hand
{
public:
    std::string name;
    GenericPlayer(std::string st)
    {
        name = st;
    }
    virtual bool IsHiting()
    {
        if (GetValue() > 20)
            return false;
        else
            return true;
    }
    bool IsBoosted()
    {
        if (GetValue() > 21)
            return true;
        else
            return false;
    }
    void BusT()
    {
        std::cout << name << " Has Too Much!" << std::endl;
    }
};

int main()
{
    std::cout << "EXE 1!" << std::endl;
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    std::cout << "EXE 2!" << std::endl;
    Pair<int, double> p3(6, 7.8);
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';
    const Pair<double, int> p4(3.4, 5);
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    std::cout << "EXE 3!" << std::endl;
    /*StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';*/

    std::cout << "EXE 4!" << std::endl;
    GenericPlayer player("Serega");
    Card za(Spades, eight);
    Card ze(Spades, queen);
    Card zd(Spades, two);
    player.Clear();
    player.Add(&za);
    player.Add(&ze);
    player.Add(&zd);
    if (player.IsHiting() == false)
        std::cout << "Stap!" << std::endl;
    if (player.IsBoosted())
        player.BusT();
}


