// Урок 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
// Задание 1
void smartent()
{
    bool fl = 1;
    int c = 0;
    std::cout << "Enter c = ";
    while (fl)
    {
        fl = 0;
        std::cin >> c;
        std::cin.clear();
        if (std::cin.get() != '\n')
        {
            fl = 1;
            std::cout << "Enter NBR please!" << std::endl;
            while (std::cin.get() != '\n');
        }
        std::cout << "C = " << c << std::endl;
    }
    std::cout << "C = " << c << std::endl;
}

//Задание 2
void Endl()
{
    std::cout << "\n\n";
    std::cin.clear();
    while (std::cin.get() != '\n');
}

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
    friend std::ostream& operator<< (std::ostream& out, const Card& point)
    {
        if (point.position)
        {
            switch (point.suit) 
            {
            case Spades: out << "Spades ";
                    switch (point.meaning)
                {
                case ace: return (out << "ace");
                case two: return (out << "two");
                case three: return (out << "three");
                case four: return (out << "four");
                case five: return (out << "five");
                case six: return (out << "six");
                case seven: return (out << "seven");
                case eight: return (out << "eight");
                case nine: return (out << "nine");
                case ten: return (out << "ten");
                case JackOrKnave: return (out << "JackOrKnave");
                case queen: return (out << "queen");
                case king: return (out << "king");
                }
            case Hearts: out << "Hearts ";
                    switch (point.meaning)
                    {
                    case ace: return (out << "ace");
                    case two: return (out << "two");
                    case three: return (out << "three");
                    case four: return (out << "four");
                    case five: return (out << "five");
                    case six: return (out << "six");
                    case seven: return (out << "seven");
                    case eight: return (out << "eight");
                    case nine: return (out << "nine");
                    case ten: return (out << "ten");
                    case JackOrKnave: return (out << "JackOrKnave");
                    case queen: return (out << "queen");
                    case king: return (out << "king");
                    }
            case Clubs: out << "Clubs ";
                    switch (point.meaning)
                    {
                    case ace: return (out << "ace");
                    case two: return (out << "two");
                    case three: return (out << "three");
                    case four: return (out << "four");
                    case five: return (out << "five");
                    case six: return (out << "six");
                    case seven: return (out << "seven");
                    case eight: return (out << "eight");
                    case nine: return (out << "nine");
                    case ten: return (out << "ten");
                    case JackOrKnave: return (out << "JackOrKnave");
                    case queen: return (out << "queen");
                    case king: return (out << "king");
                    }
            case Diamonds: out << "Diamonds ";
                    switch (point.meaning)
                    {
                    case ace: return (out << "ace");
                    case two: return (out << "two");
                    case three: return (out << "three");
                    case four: return (out << "four");
                    case five: return (out << "five");
                    case six: return (out << "six");
                    case seven: return (out << "seven");
                    case eight: return (out << "eight");
                    case nine: return (out << "nine");
                    case ten: return (out << "ten");
                    case JackOrKnave: return (out << "JackOrKnave");
                    case queen: return (out << "queen");
                    case king: return (out << "king");
                    }
            }
            
        }
        else
            out << "X.X";
    }
};

class Hand
{
protected:
    std::vector <Card*> hd;
public:
    Hand() {}
    
    void Add(Card* a)
    {
        this->hd.push_back(a);
    }
    void Clear()
    {
        this->hd.clear();
    }
    int GetValue() const
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
protected:
    std::string name;
public:
    
    GenericPlayer(std::string st)
    {
        name = st;
    }
    virtual bool IsHiting()
    {
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
    friend std::ostream& operator<< (std::ostream& out, const GenericPlayer& point)
    {
        out << point.name << '\n';
        for (int i = 0; i < point.hd.size();i++)
        {
            out << *point.hd[i] << '\n';
        }
        out << point.GetValue() << '\n';
        return out;
    }
};

class Player :public GenericPlayer
{
public:
    Player(std::string st):GenericPlayer(st)
    {
        
    }
    virtual bool IsHitting() const
    {
        std::cout << name << ", do you want a hit? (Y/N): ";
        char response;
        std::cin >> response;
        return (response == 'y' || response == 'Y');

    }
    void Win() const
    {
        std::cout << name << "is WIN!!! " << std::endl;
    }
    void Lose() const
    {
        std::cout << name << "is Lose!!! " << std::endl;
    }
    void Push() const
    {
        std::cout << name << "is Push!!! " << std::endl;
    }
};

//Задание 4
class House : public GenericPlayer
{
public:
    House() : GenericPlayer("AI")
    {

    }
    virtual bool IsHitting() const
    {
        if (GetValue() < 16)
        {
            return true;
        }
        else
            return false;
    }
    void FlipFirstCard()
    {
        if (hd.size() > 0)
            hd[0]->Flip();
    }
};

//Задание 5 Перегрузка внутри нужных классов

int main()
{
    std::cout << "EXE 1!" << std::endl;
    int i;
    smartent();
    std::cout << "EXE 2!" << std::endl;
    std::cin >> i;
    Endl();
    std::cin >> i;
    std::cout << "EXE 3!" << std::endl;
    Player player("Serega");
    Card za(Spades, eight);
    Card ze(Spades, queen);
    Card zd(Spades, two);
    player.Clear();
    player.Add(&za);
    player.Add(&ze);
    player.Add(&zd);
    if (player.IsHiting() == false)
        std::cout << "Stap!" << std::endl;
    player.Win();
    player.Lose();
    player.Push();
    std::cout << "EXE 4!" << std::endl;
    House hs;
    hs.Clear();
    hs.Add(&za);
    hs.Add(&ze);
    hs.Add(&zd);
    if (player.IsHiting() == false)
        std::cout << "Stap!" << std::endl;
    hs.FlipFirstCard();
    std::cout << "EXE 5!" << std::endl;
    std::cout << hs << std::endl;
    std::cout << player << std::endl;
    std::cout << "EXE 2!" << std::endl;
    std::cout << zd;
}

