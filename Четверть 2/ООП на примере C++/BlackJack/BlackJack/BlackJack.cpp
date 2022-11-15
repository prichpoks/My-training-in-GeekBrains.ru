// BlackJack/Стабильная версия/ без шлюх
// Корнилоа Сергей

#include <iostream>
#include <vector>
#include <algorithm>

enum Suit { SPADES = 1, HEARTS, CLUBS, DIAMONDS };
enum Meaning { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACKORKNAVE, QUEEN, KING };
class Card // Работает верно!
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
            position = true;
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
            case SPADES: out << "Spades ";
                switch (point.meaning)
                {
                case ACE: return (out << "ace");
                case TWO: return (out << "two");
                case THREE: return (out << "three");
                case FOUR: return (out << "four");
                case FIVE: return (out << "five");
                case SIX: return (out << "six");
                case SEVEN: return (out << "seven");
                case EIGHT: return (out << "eight");
                case NINE: return (out << "nine");
                case TEN: return (out << "ten");
                case JACKORKNAVE: return (out << "JackOrKnave");
                case QUEEN: return (out << "queen");
                case KING: return (out << "king");
                }
            case HEARTS: out << "Hearts ";
                switch (point.meaning)
                {
                case ACE: return (out << "ace");
                case TWO: return (out << "two");
                case THREE: return (out << "three");
                case FOUR: return (out << "four");
                case FIVE: return (out << "five");
                case SIX: return (out << "six");
                case SEVEN: return (out << "seven");
                case EIGHT: return (out << "eight");
                case NINE: return (out << "nine");
                case TEN: return (out << "ten");
                case JACKORKNAVE: return (out << "JackOrKnave");
                case QUEEN: return (out << "queen");
                case KING: return (out << "king");
                }
            case CLUBS: out << "Clubs ";
                switch (point.meaning)
                {
                case ACE: return (out << "ace");
                case TWO: return (out << "two");
                case THREE: return (out << "three");
                case FOUR: return (out << "four");
                case FIVE: return (out << "five");
                case SIX: return (out << "six");
                case SEVEN: return (out << "seven");
                case EIGHT: return (out << "eight");
                case NINE: return (out << "nine");
                case TEN: return (out << "ten");
                case JACKORKNAVE: return (out << "JackOrKnave");
                case QUEEN: return (out << "queen");
                case KING: return (out << "king");
                }
            case DIAMONDS: out << "Diamonds ";
                switch (point.meaning)
                {
                case ACE: return (out << "ace");
                case TWO: return (out << "two");
                case THREE: return (out << "three");
                case FOUR: return (out << "four");
                case FIVE: return (out << "five");
                case SIX: return (out << "six");
                case SEVEN: return (out << "seven");
                case EIGHT: return (out << "eight");
                case NINE: return (out << "nine");
                case TEN: return (out << "ten");
                case JACKORKNAVE: return (out << "JackOrKnave");
                case QUEEN: return (out << "queen");
                case KING: return (out << "king");
                }
            }

        }
        else
            return(out << "X.X");
    }
}; // Работает верно!

class Hand // Работает верно!
{
protected:
    std::vector <Card*> SetOfCard;

public:
    void Add(Card* card)
    {
        SetOfCard.push_back(card);
    }
    void Clear()
    {
        SetOfCard.clear();
        SetOfCard.shrink_to_fit();
    }
    int GetValue() const
    {
        int res = 0;
        int size = SetOfCard.size();
        bool ace = false;
        for (int i = 0; i < size; i++)
        {
            if (SetOfCard[i]->GetValue() == 1)
            {
                ace = true;
            }
            if (SetOfCard[i]->GetValue() > 10)
            {
                res += 10;
            }
            else
            {
                res += SetOfCard[i]->GetValue();
            }

        }
        if (ace && res + 10 == 21)
        {
            res += 10;
        }
        return res;
    }
}; // Работает верно!

class GenericPlayer : public Hand // Работает верно!
{
protected:
    std::string name;

public:
    GenericPlayer(std::string _name)
    {
        this->name = _name;
    }
    virtual bool IsHitting() { return true; }
    bool IsBoosted()
    {
        if (this->GetValue() > 21)
        {
            return true;
        }
        return false;
    }
    void Bust()
    {
        std::cout << name << " - Has to much!" << std::endl;
    }
    friend std::ostream& operator<< (std::ostream& out, GenericPlayer& point)
    {
        out << point.name << "\n";
        int size = point.SetOfCard.size();
        for (int i = 0; i < size; i++)
        {
            out << *point.SetOfCard[i] << "\n";
        }
        out << point.GetValue() << "\n";
        return out;
    }
    void FlipAllCards()
    {
        int size = SetOfCard.size();
        for (int i = 0; i < size; i++)
        {
            SetOfCard[i]->Flip();
        }
    }
};// Работает верно! 

class Player : public GenericPlayer // Работает верно!
{
public:
    Player(std::string name) :GenericPlayer(name) {}
    virtual bool IsHitting() const
    {
        char response;
        std::cout << "Do you want a hit? (Y|N)";
        std::cin >> response;
        return (response == 'Y' || response == 'y');
    }
    void Win() const
    {
        std::cout << name << " - is WIN!!!" << std::endl;
    }
    void Lose() const
    {
        std::cout << name << " - is LOSE!!!" << std::endl;
    }
    void Push() const
    {
        std::cout << name << " - is PUSH!!!" << std::endl;
    }
}; // Работает верно!

class House : public GenericPlayer // Работает верно!
{
public:
    House() :GenericPlayer("AI") {}
    virtual bool IsHitting() const
    {
        return (GetValue() < 17);
    }
    void FlipFirstCard()
    {
        if (SetOfCard.size() > 0)
        {
            SetOfCard[0]->Flip();
        }
    }
}; // Работает верно!

class Deck :public Hand // Работает верно!
{
public:
    void Populate()
    {
        for (int i = 1; i < 5; i++)
        {
            for (int count = 1; count < 14; count++)
            {
                SetOfCard.push_back(new Card((Suit)i, (Meaning)count));
            }
        }
    }
    void Shuffle()
    {
        srand(time(0));
        Card* pcard;
        for (int i = 0; i < 104; i++)
        {
            int p = rand() % 52;
            int z = rand() % 52;
            pcard = SetOfCard[p];
            SetOfCard[p] = SetOfCard[z];
            SetOfCard[z] = pcard;
        }
    }
    void Deal(Hand& aHand)
    {
        aHand.Add(SetOfCard.back());
        SetOfCard.pop_back();
    }
    void AddltionalCards(Player& player)
    {
        player.FlipAllCards();
        std::cout << player << std::endl;
        while (player.IsHitting() && !player.IsBoosted())
        {
            Deal(player);
            player.FlipAllCards();
            std::cout << player << std::endl;
        }
    }
    void AddAiCard(House& house)
    {
        while (house.IsHitting())
        {
            Deal(house);
        }
    }
    int SizeSet()
    {
        return(SetOfCard.size());
    }
}; // Работает верно!

class Game
{
private:
    Deck deck;
    House house;
    std::vector<Player*> players;
public:
    Game(std::vector<std::string> names)
    {
        int size = names.size();
        for (int i = 0; i < size; i++)
        {
            players.push_back(new Player(names[i]));
        }
        deck.Populate();
        deck.Shuffle();
    }
    void play()
    {
        int raund = 1;
        char ch;
        std::cout << "Rady to start raund " << raund << " (Y|N)? ";
        std::cin >> ch;
        int size = players.size();
        while (ch == 'Y' || ch == 'y')
        {
            if (raund > 1)
            {
                deck.Populate();
                deck.Shuffle();
            }
            for (int i = 0; i < size; i++)
            {
                deck.Deal(*players[i]);
                deck.Deal(*players[i]);

            }
            deck.Deal(house);
            deck.Deal(house);
            house.FlipFirstCard();
            std::cout << "One level\nPlayers:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << *players[i] << std::endl;
            }
            std::cout << house << std::endl;
            std::cout << "Two level\nPlayers:\n\n";
            for (int i = 0; i < size; i++)
            {
                deck.AddltionalCards(*players[i]);
            }
            deck.AddAiCard(house);
            int FlagWin = -1;
            bool FlagPush = false;
            int sum, sumAI;
            sumAI = house.GetValue();
            for (int i = 0; i < size; i++)
            {
                if ((sum = players[i]->GetValue()) < 22)
                {
                    if (FlagWin == sum)
                    {
                        FlagPush = true;
                    }
                    FlagWin = sum;
                }
            }
            std::cout << "\n\nGame results\n\n";
            if (FlagWin > -1)
            {
                if (sumAI > sum && sumAI < 22)
                {
                    for (int i = 0; i < size; i++)
                    {
                        std::cout << *players[i];
                        players[i]->Lose();
                    }
                    std::cout << house;
                }
                else
                {
                    if (FlagPush)
                    {
                        for (int i = 0; i < size; i++)
                        {
                            if (players[i]->GetValue() == sum)
                            {
                                std::cout << *players[i];
                                players[i]->Push();
                            }
                            else
                            {
                                std::cout << *players[i];
                                players[i]->Lose();
                            }
                            std::cout << house;
                        }
                    }
                    else
                    {
                        for (int i = 0; i < size; i++)
                        {
                            if (players[i]->GetValue() == sum)
                            {
                                std::cout << *players[i];
                                players[i]->Win();
                            }
                            else
                            {
                                std::cout << *players[i];
                                players[i]->Lose();

                            }
                            std::cout << house;
                        }
                    }
                }
            }
            else
            {
                if (sumAI < 22)
                {
                    for (int i = 0; i < size; i++)
                    {
                        std::cout << *players[i];
                        players[i]->Lose();
                    }
                    std::cout << house;
                }
                else
                {
                    for (int i = 0; i < size; i++)
                    {
                        std::cout << *players[i];
                        players[i]->Push();
                    }
                    std::cout << house;
                }
            }
            house.Clear();
            for (int i = 0; i < size; i++)
            {
                players[i]->Clear();
            }
            deck.Clear();
            raund++;
            std::cout << "Rady to start raund " << raund << " (Y|N)? ";
            std::cin >> ch;
        }
    }
    ~Game()
    {
        int size = players.size();
        for (int i = 0; i < size; i++)
        {
            delete players[i];
        }
    }

};

int main()
{

    Game game({ "hoi", "popa", "pipa" });

    game.play();


}
