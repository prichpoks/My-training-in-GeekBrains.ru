// ООП на примере С++
// Урок 7
//Коорнилов Сергей


#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
//Звдвние 1
class Date
{
private:
    int day;
    int manth;
    int year;
public:
    Date() {}
    void EnterDay(int i)
    {
        day = i;
    }
    void EnterManth(int i)
    {
        manth = i;
    }
    void EnterYear(int i)
    {
        year = i;
    }
    friend std::ostream& operator<< (std::ostream& out, Date& date)
    {
        out <<  date.day << '.' << date.manth << '.' << date.year << '\n';
        return out;
    }
    friend std::ostream &operator<< (std::ostream& out, std::shared_ptr<Date> & date)
    {
        out << date->ReturnDay() << '.' << date->ReturnManth() << '.' << date->ReturnYear() << '\n';
        return out;
    }
    int ReturnYear()
    {
        return year;
    }
    int ReturnManth()
    {
        return manth;
    }
    int ReturnDay()
    {
        return day;
    }

};
//Задание 2
std::shared_ptr<Date> comparison(std::shared_ptr<Date> date1, std::shared_ptr<Date> date2)
{
    if (date1->ReturnYear() > date2->ReturnYear())
        return date2;
    else if (date1->ReturnYear() < date2->ReturnYear())
        return date1;
    else
    {
        if (date1->ReturnManth() > date2->ReturnManth())
            return date2;
        else if (date1->ReturnManth() < date2->ReturnManth())
            return date1;
        else
        {
            if (date1->ReturnDay() > date2->ReturnDay())
                return date2;
            else if (date1->ReturnManth() < date2->ReturnDay())
                return date1;
            else
                return date1;
        }
    }
}


void exchange(std::shared_ptr<Date> date1, std::shared_ptr<Date> date2)
{
    date2->EnterDay(date1->ReturnDay());
    date2->EnterManth(date1->ReturnManth());
    date2->EnterYear(date1->ReturnYear());
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
        for (int i = 0; i < point.hd.size(); i++)
        {
            out << *point.hd[i] << '\n';
        }
        out << point.GetValue() << '\n';
        return out;
    }
    void Maxflip()
    {
        for (int i = 0; i < this->hd.size(); i++)
        {
            this->hd[i]->Flip();
        }
    }
};

class Player :public GenericPlayer
{
public:
    Player(std::string st) :GenericPlayer(st)
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


class Deck : public Hand
{
public:
    void Populate()
    {
        Card* pcard;
        for (int i = 1; i < 5; i++)
        {
            for (int j = 1; j < 14; j++)
            {
                pcard = new Card((Suit)i,(Meaning)j);
                this->Add(pcard);
            }
        }
    }
    void Shuffle()
    {
        srand(time(0));
        Card* pcard;
        for (int i = 0; i < 104; i++)
        {
            int p = rand()%52;
            int z = rand()%52;
            pcard = hd[p];
            hd[p] = hd[z];
            hd[z] = pcard;
        }
    }
    void Deal(Hand& aHand)
    {
        aHand.Add(this->hd[this->hd.size() - 1]);
        this->hd.pop_back();
    }
    void AddltionalCards(GenericPlayer& aGenerlcPlayer)
    {
        if (aGenerlcPlayer.IsHiting())
        {
            aGenerlcPlayer.Add(this->hd[this->hd.size() - 1]);
            this->hd.pop_back();
        }
    }
};
//Задание 4
class Game
{
protected:
    Deck gDeck;
    House gHouse;
    std::vector<Player*> gPlayer;
public:
    Game(std::vector<std::string> namePlayers)
    {
        Player* ppla;
        for (int i = 0; i < namePlayers.size(); i++)
        {
            ppla = new Player(namePlayers[i]);
            gPlayer.push_back(ppla);
        }
        gDeck.Populate();
        gDeck.Shuffle();
    }
    void play()
    {
        for (int i = 0; i < gPlayer.size(); i++)
        {
            gDeck.AddltionalCards(*gPlayer[i]);
            gDeck.AddltionalCards(*gPlayer[i]);
        }
        gDeck.AddltionalCards(gHouse);
        gDeck.AddltionalCards(gHouse);
        for (int i = 0; i < gPlayer.size(); i++)
        {
            std::cout<< *gPlayer[i];
            while (gPlayer[i]->IsHitting())
            {
                gDeck.AddltionalCards(*gPlayer[i]);
                std::cout << *gPlayer[i];
            }
        }
        while (gHouse.IsHitting())
        {
            gDeck.AddltionalCards(gHouse);
        }
        int bol = -1;
        for (int i = 0; i < gPlayer.size(); i++)
        {
            if (gPlayer[i]->GetValue() <= 21)
            {
                bol = i;
                break;
            }
        }
        if (bol > -1)
        {
            for (int i = 1; i < gPlayer.size(); i++)
            {
                if (gPlayer[bol]->GetValue() < gPlayer[i]->GetValue() && gPlayer[i]->GetValue() < 22)
                    bol = i;
            }
        }
        if (bol > -1)
        {
            if (gPlayer[bol]->GetValue() < gHouse.GetValue() && gHouse.GetValue() < 22)
            {
                gHouse.Maxflip();
                std::cout << "AI VIN!\n" << gHouse;
            }
            else
            {
                gPlayer[bol]->Maxflip();
                gPlayer[bol]->Win();
                std::cout << *gPlayer[bol];
            }
        }
        else
        {
            if (gHouse.GetValue() < 22)
            {
                gHouse.Maxflip();
                std::cout << "AI VIN!\n" << gHouse;
            }
            else
            {
                std::cout << "Draw!\n" << gHouse;
            }
        }
    }
    ~Game()
    {
        for (int i = 0; i < gPlayer.size(); i++)
        {
            delete gPlayer[i];
        }
    }

};
//Задание 5
//Реализация в main
int main()
{

    std::cout << "EXE 1!\n";
    auto today = std::make_shared<Date>();
    auto date = std::make_shared<Date>();
    today->EnterDay(6);
    today->EnterManth(2);
    today->EnterYear(2022);
    date = today;
    date->EnterManth(3);
    std::cout << *today;
    std::cout << *date;
    date = NULL;
    if (today == 0 || date == 0)
        std::cout << "pointer is NULL!";
    std::cout << "EXE 2!\n";
    auto date1 = std::make_shared<Date>();
    auto date2 = std::make_shared<Date>();
    date1->EnterDay(3);
    date1->EnterManth(2);
    date1->EnterYear(2021);
    date2->EnterDay(3);
    date2->EnterManth(2);
    date2->EnterYear(2001);
    std::cout << *comparison(date1, date2);
    exchange(date1, date2);
    std::cout << *date2;
    std::cout << *date1;
    std::cout << "EXE 3!\n";
    Player player("Serega");
    Deck deck;
    deck.Populate();
    deck.Shuffle();
    deck.AddltionalCards(player);
    deck.AddltionalCards(player);
    deck.AddltionalCards(player);
    player.Maxflip();
    std::cout << player;
    std::cout << "EXE 4-5!\n";
    std::vector<std::string> str = {"Player test"};
    std::vector<Game*> vgame;
    Game* pgame;
    std::cout << ", do you want a Play? (Y/N): ";
    char response;
    std::cin >> response;
    while (response == 'y' || response == 'Y')
    {
        pgame = new Game(str);
        pgame->play();
        delete pgame;
        std::cout << ", do you want a Play? (Y/N): ";
        std::cin >> response;
    }
    std::cout << "Thanks for playing ";

}