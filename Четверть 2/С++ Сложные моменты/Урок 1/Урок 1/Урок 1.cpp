// Корнилов Сергей
// Группа 1861
// С++ Сложные моменты
// Урок 1



#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
// Задание 1
struct Person
{
    std::string surname;
    std::string name;
    std::optional<std::string> patronymic;
    Person() {}
    Person(std::string s, std::string n, std::optional < std::string> p) :surname(s), name(n), patronymic(p){}
    bool operator==(Person& second)
    {
        return tie(this->surname, this->name, this->patronymic) == tie(second.surname, second.name, second.patronymic);
    }
    bool operator<(Person& second)
    {
        return tie(this->surname, this->name, this->patronymic) < tie(second.surname, second.name, second.patronymic);
    }
    
};
std::ostream& operator<<(std::ostream& os, Person& person)
{
    os << person.surname << " " << person.name << " ";
    if (person.patronymic)
    {
        os << person.patronymic.value();
    }
    return os;
}

// Задание 2
struct PhoneNumber
{
    int16_t country_code;
    int16_t city_code;
    std::string number;
    std::optional<int16_t> extension_number;
    PhoneNumber() { country_code = 0; city_code = 0; number = "0"; extension_number = 0; }
    PhoneNumber(int16_t c, int16_t ci, std::string n, std::optional<int16_t> e) : country_code(c), city_code(ci), number(n), extension_number(e) {}
    bool operator<(PhoneNumber& pnbr)
    {
        return tie(this->country_code, this->city_code, this->number, this->extension_number) <
            tie(pnbr.country_code, pnbr.city_code, pnbr.number, pnbr.extension_number);
    }
    bool operator==(PhoneNumber& pnbr)
    {
        return tie(this->country_code, this->city_code, this->number, this->extension_number) ==
            tie(pnbr.country_code, pnbr.city_code, pnbr.number, pnbr.extension_number);
    }

};
std::ostream& operator<<(std::ostream& os, PhoneNumber& pnbr)
{
    os << '+' << pnbr.country_code << '(' << pnbr.city_code << ')' << pnbr.number ;
    if (pnbr.extension_number)
        os << ' ' << pnbr.extension_number.value();
    return os;
}

//Задание 3
class PhoneBook
{
private:
    std::vector <std::pair<Person, PhoneNumber>> phonebook;
public:
    PhoneBook(std::ifstream& fiel)
    {
        std::string str;
        std::pair<Person, PhoneNumber> pr;
        while (!fiel.eof())
        {
            fiel >> pr.first.surname >> pr.first.name >> str;
            if (str == "-")
                pr.first.patronymic = std::nullopt;
            else
                pr.first.patronymic = str;
            fiel >> str;
            pr.second.country_code = std::stoi(str);
            fiel >> str >> pr.second.number;
            pr.second.city_code = std::stoi(str);
            fiel >> str;
            if (str == "-")
                pr.second.extension_number = std::nullopt;
            else
                pr.second.extension_number = std::stoi(str);
            phonebook.push_back(pr);
        }
    }
    void SortByName()
    {
        sort(phonebook.begin(), phonebook.end(), [](std::pair<Person, PhoneNumber> & p1, std::pair<Person, PhoneNumber>& p2)
            {
                return p1.first < p2.first;
            });
    }
    void SortByPhone()
    {
        sort(phonebook.begin(), phonebook.end(), [](std::pair<Person, PhoneNumber>& p1, std::pair<Person, PhoneNumber>& p2)
            {
                return p1.second < p2.second;
            });
    }
    friend std::ostream& operator<<(std::ostream& os, PhoneBook& phb);

    std::tuple <std::string, PhoneNumber > GetPhoneNumber(std::string str)
    {
        size_t count = 0, size = phonebook.size();
        size_t res = 0;
        std::tuple<std::string, PhoneNumber> tu;
        for (int i = 0; i < size; i++)
        {
            if (phonebook[i].first.surname == str)
            {
                count++;
                res = i;
            }
        }
        if (count > 1)
        {
            
            tu = { "found more than 1", phonebook[res].second };
            return tu;
        }
        else if (count < 1)
        {
            tu = { "Not found", phonebook[res].second };
            return tu;
        }
        else
        {
            tu = { "", phonebook[res].second};
            return tu;
        }
    }
    bool ChangePhoneNumber(Person pers, PhoneNumber pnb)
    {
        size_t count = 0, size = phonebook.size();
        size_t res = 0;
        std::tuple<std::string, PhoneNumber> tu;
        for (size_t i = 0; i < size; i++)
        {
            if (phonebook[i].first == pers)
            {
                phonebook[i].second = pnb;
                return true;
            }
        }
        return false;
    }
};
std::ostream& operator<<(std::ostream& os, PhoneBook& phb)
{
    size_t size = phb.phonebook.size();
    for (int i = 0; i < size; i++)
    {
        os << phb.phonebook[i].first << " = " << phb.phonebook[i].second << '\n';
    }
    return os;
}




int main()
{
    std::ifstream file("PhoneBook.txt"); // путь к файлу PhoneBook.txt 
    PhoneBook book(file);
    std::cout << book;
    std::cout << "------SortByPhone-------" << std::endl;
    book.SortByPhone();
    std::cout << book;
    std::cout << "------SortByName--------" << std::endl;
    book.SortByName();
    std::cout << book;
    std::cout << "-----GetPhoneNumber-----" << std::endl;
    // лямбда функция, которая принимает фамилию и выводит номер телефона человека, либо строку с ошибкой
    auto print_phone_number = [&book](const std::string& surname) 
    {
        std::cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (std::get<0>(answer).empty())
             std::cout << std::get<1>(answer);
        else
             std::cout << std::get<0>(answer);
        std::cout << std::endl;
    };
    // вызовы лямбды
    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    std::cout << "----ChangePhoneNumber----" << std::endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
        PhoneNumber{ 7, 123, "15344458", std::nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
        PhoneNumber{ 16, 465, "9155448", 13 });
    std::cout << book;
}

