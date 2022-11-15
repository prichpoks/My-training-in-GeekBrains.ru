// ООП на примере С++
// Урок 3
// Корнилов Сергей

#include <iostream>

// Задание 1
#include <cmath>
const double PI = 3.14159;
class Figure
{
public:
    virtual double area() = 0;
};

class Parallelogram : public Figure
{
protected:
    double a;
    double b;
public:
    Parallelogram()
    {
        a = 1;
        b = 1;
    }
    Parallelogram(double _a, double _b)
    {
        a = _a;
        b = _b;
    }
    virtual double area()
    {
        return a * b;
    }
};

class Circle : public Figure
{
protected:
    double r;
public:
    Circle(double _r)
    {
        r = _r;
    }
    virtual double area()
    {
        return r * r * PI;
    }
};

class Rectangle : public Parallelogram
{
protected:
    double corner;


public:
    Rectangle(double _a)
    {
        a = _a;
        b = a * 2;
        corner = 90;
    }
    virtual double area()
    {
        return a * a * 2;
    }
};

class Square : Parallelogram
{
protected:
    double corner;
public:
    Square(double _a)
    {
        a = _a;
        b = a;
        corner = 90;
    }
    virtual double area()
    {
        return a * a;
    }
};

class Rhombus : Parallelogram
{
protected:
    double corner;
public:
    Rhombus(double _a, double _corners)
    {
        a = _a;
        b = a;
        corner = _corners;
    }
    virtual double area()
    {
        return a*a*sin(corner * PI / 180);
    }
};

// Задание 2
#include <string>

class Car
{
protected:
    std::string company;
    std::string model;
public:
    Car()
    {
        company = "company";
        model = "model";
        std::cout << "\nCreate class Car" << std::endl;
        std::cout << "Car company - " << company << std::endl;
        std::cout << "Car model - " << model << std::endl;
    }
    Car(std::string com, std::string mod)
    {
        company = com;
        model = mod;
        std::cout << "\nCreate class Car" << std::endl;
        std::cout << "Car company - " << company << std::endl;
        std::cout << "Car model - " << model << std::endl;
    }
};

class PassengerCar : public virtual Car
{
public:
    PassengerCar()
    {
        std::cout << "\nCreate class PassengerCar" << std::endl;
        std::cout << "Car company - " << company << std::endl;
        std::cout << "Car model - " << model << std::endl;
    }
    PassengerCar(std::string com, std::string mod):Car(com, mod)
    {
        std::cout << "\nCreate class PassengerCar" << std::endl;
        std::cout << "Car company - " << company << std::endl;
        std::cout << "Car model - " << model << std::endl;
    }
};

class Bus : public virtual Car
{
public:
    Bus()
    {
        std::cout << "\nCreate class Bus" << std::endl;
        std::cout << "Car company - " << company << std::endl;
        std::cout << "Car model - " << model << std::endl;
    }
    Bus(std::string com, std::string mod) :Car(com, mod)
    {
        std::cout << "\nCreate class Bus" << std::endl;
        std::cout << "Car company - " << company << std::endl;
        std::cout << "Car model - " << model << std::endl;
    }
};

class Minivan : public Bus, PassengerCar
{
public:
    Minivan()
    {
        std::cout << "\nCreate class Minivan" << std::endl;
        std::cout << "Car company - " << company << std::endl;
        std::cout << "Car model - " << model << std::endl;
    }
    Minivan(std::string com, std::string mod)
    {
        model = mod;
        company = com;
        std::cout << "\nCreate class Minivan" << std::endl;
        std::cout << "Car company - " << company << std::endl;
        std::cout << "Car model - " << model << std::endl;
    }
};

//Задание 3
class Fraction
{
protected:

    int numerator;
    int denominator;
public:
    Fraction(int i, int c)
    {
        numerator = i;
        denominator = c;
    }
    Fraction operator+(Fraction &n)
    {
        if (denominator != n.denominator)
            return Fraction(numerator * n.denominator + n.numerator * denominator, n.denominator * denominator);
        else
            return Fraction(numerator + n.numerator, n.denominator);
    }
    Fraction operator-(Fraction& n)
    {
        if (denominator != n.denominator)
            return Fraction(numerator * n.denominator - n.numerator * denominator, n.denominator * denominator);
        else
            return Fraction(numerator - n.numerator, n.denominator);
    }
    Fraction operator*(Fraction& n)
    {
        return Fraction(numerator * n.numerator, n.denominator * denominator);
    }
    Fraction operator/(Fraction& n)
    {
        return Fraction(numerator * n.denominator, n.numerator * denominator);
    }
    Fraction operator-()
    {
        return Fraction(-numerator, -denominator);
    }
    bool operator==(Fraction n)
    {
        return numerator * n.denominator == n.numerator * denominator;
    }
    bool operator>(Fraction n)
    {
        return numerator * n.denominator > n.numerator * denominator;
    }
    bool operator<(Fraction n)
    {
        return numerator * n.denominator < n.numerator * denominator;
    }
    bool operator<=(Fraction n)
    {
        return numerator * n.denominator <= n.numerator * denominator;
    }
    bool operator>=(Fraction n)
    {
        return numerator * n.denominator >= n.numerator * denominator;
    }
    void printFraction()
    {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};

// Задание 4

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
int main()
{
    std::cout << "!!!!!EXE 1!!!!!" << std::endl;
    Rhombus romb(4, 30);
    Square kvadrat(2);
    Rectangle priama(2);
    Circle krug(6);
   
    std::cout << "S romb = " << romb.area() << std::endl;
    std::cout << "S kvadrat = " << kvadrat.area() << std::endl;
    std::cout << "S priama = " << priama.area() << std::endl;
    std::cout << "S krug = " << krug.area() << std::endl;

    std::cout << "!!!!!EXE 2!!!!!" << std::endl;
    std::cout << "!CREATE CLASS CAR!\n!CREATE CLASS CAR!" << std::endl;
    Car car("ini", "33");
    std::cout << "!CREATE CLASS Bus!\n!CREATE CLASS Bus!" << std::endl;
    Bus bus("Uaz", "432");
    std::cout << "!CREATE CLASS PassengerCar!\n!CREATE CLASS PassengerCar!" << std::endl;
    PassengerCar pcar("BMW", "X6");
    std::cout << "!CREATE CLASS Minivan!\n!CREATE CLASS Minivan!" << std::endl;
    Minivan minivan("MB", "strannik");
    std::cout << "!!!!!EXE 3!!!!!" << std::endl;
    Fraction a(2, 4);
    Fraction b(4, 6);
    Fraction c = a + b + a;
    c.printFraction();
    c = a * b;
    c.printFraction();
    c = a / b;
    c.printFraction();
    c = a - b;
    c.printFraction();
    std::cout << "a > b = " << (a > b) << std::endl;
    std::cout << "a < b = " << (a < b) << std::endl;
    std::cout << "a == b = " << (a == b) << std::endl;
    std::cout << "!!!!!EXE 4!!!!!" << std::endl;
    Card card(Suit::Spades, Meaning::four);
    std::cout << "meaning of card = " << card.GetValue() << std::endl;
}

