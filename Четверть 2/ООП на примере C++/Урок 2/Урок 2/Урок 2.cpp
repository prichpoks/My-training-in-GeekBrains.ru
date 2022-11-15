// ООП на примере С++
// Урок 2
// Корнилов Сергей


#include <iostream>

// Задание 1

class Person
{
private:
    std::string name;
    int age;
    bool gender;
    int weight;
public:
    Person()
    {
        std::cout << "pleace Enter Name: ";
        std::cin >> name;
        std::cout << "pleace Enter Age: ";
        std::cin >> age;
        std::cout << "pleace Enter gender (0|1): ";
        std::cin >> gender;
        std::cout << "pleace Enter weight: ";
        std::cin >> weight;
    }
    void ToChangeName(std::string str)
    {
        name = str;
    }
    void ToChangeAge(int nbr)
    {
        age = nbr;
    }
    void ToChangeWeight(int nbr)
    {
        weight = nbr;
    }
    void PrintPerson()
    {
        std::cout << "\nPersont - " << name << "\nAge - " << age << "\nWeight - " << weight << "\nGender - " << gender;
    }
};

class Student : public Person
{
private:
    int YearOfStudy;
    static int SizeStudents;
public:
    Student()
    {
        SizeStudents++;
        std::cout << "Enter please Year of study: ";
        std::cin >> YearOfStudy;
    }
    void ToChangeYearOfStudy(int nbr)
    {
        YearOfStudy = nbr;
    }
    void AddYearOfStudy()
    {
        YearOfStudy++;
    }
    void PrintStudent()
    {
        PrintPerson();
        std::cout << "\nYear of Study - " << YearOfStudy;
    }
    void EnterSize()
    {
        std::cout << "\nNumber students - " << SizeStudents;
    }
};

int Student::SizeStudents = 0;

// Задание 2
class Fruit
{
public:
    std::string name;
    std::string color;
    Fruit()
    {}
    std::string getName()
    {
        return name;
    }
    std::string getColor()
    {
        return color;
    }

};

class Apple : public Fruit
{
public:
    Apple()
    {
        name.append("apple");
        color.append("no color");
    }
    Apple(const char* p)
    {
        color.append(p);
        name.append("apple");
    }
};
class Banana : public Fruit
{
public:
    Banana()
    {
        name.append("banana");
        color.append("yelow");
    }
};
class GrannySmith : public Apple
{
public:
    GrannySmith()
    {
        color.clear();
        name.clear();
        name.append("Granny Smith apple");
        color.append("green");
    }
};

// Задание 3
/*
Очень далека от меня игра блэкджек!
Однако исходя из правил предлогаю использовать следующие классы:
Можно создать 7 классов для каждого обьекта.
Но не вижу смысла усложнять, предлогаю сделать 2 класса: ИГРОК и КАЛОДА. 
Игрок имеет параметры: стату(учасник/крупье) рука, банк.
методы: Ставка, параметры, взять карту, обнулить руку, добавить в банк, вскрыть карты.
Колода имеет параметры: количество колод, количество карт и банк карт.
методы: вывод количества карт, выдача карты.
Можно ввести класс Крупье который будет наследовать от класса игрок и иметь пораметр сложность
Можно ввесте класс ИИ который будет наследовать от класса игрок и иметь параметр сложность и эмоции для более богатова гемплея. 
Алучше всего сделать игру "Козел", там логика игры ближе и нативно понятно кто и что должен делать))))
*/
int main()
{
    std::cout << "EXE 1" << std::endl;
    Person sergey;
    sergey.PrintPerson();
    sergey.ToChangeName("Her");
    sergey.ToChangeAge(99);
    sergey.PrintPerson();
    Student popik, plop, mak;
    popik.PrintStudent();
    mak.AddYearOfStudy();
    mak.PrintStudent();
    plop.EnterSize();

    std::cout << "EXE 2" << std::endl;
    Apple z("red");
    Banana x;
    GrannySmith v;

    std::cout << "My " << z.getName() << " is " << z.getColor() << ".\n";
    std::cout << "My " << x.getName() << " is " << x.getColor() << ".\n";
    std::cout << "My " << v.getName() << " is " << v.getColor() << ".\n";

}


