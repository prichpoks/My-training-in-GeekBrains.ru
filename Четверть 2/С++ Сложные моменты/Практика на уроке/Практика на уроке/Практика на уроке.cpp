// C++: сложные моменты
// Корнилов Сергей
// Заметки на уроке 1
// 
// Вспомогательные классы 
// Tie() - функция которая используется для срванения на подобии vector
// tuple - Контейнер фиксированного размера в котором хранятся элементы возмжно различных типов
// pair - структура позволяющая обрабатывать два обьекта как один
// optional - структура дает понять есть ли элемент в ней и какой элемент
// [](){} - структура лямдафункции или анонимной функции, ее можно присвоить переменной

#include <iostream>
#include <tuple>
#include <vector>
#include <optional>
#include <algorithm>

class Time
{
private:
    int hour, minute, second;
public:
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
    friend bool operator<(const Time& t1, const Time& t2);
};

bool operator<(const Time& t1, const Time& t2)
{
    return std::tuple(t1.hour, t1.minute, t1.minute) < std::tuple(t2.hour, t2.minute, t2.minute);

}

class Poets
{
private:
    std::vector<std::pair<std::string, int>> poets;
    static bool compare_birthday(const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2)
    {
        return p1.second < p2.second;
    }
public:
    Poets()
    {
        poets = { {"Pushkin", 1799}, {"Lermontov", 1814}, {"Zhukovsky", 1783} };
    }
    std::optional<int> FindPoet(const std::string& s)
    {
        for (const auto& [surname, birthday] : poets)
        {
            if (surname == s)
                return {birthday };
        }
        return std::nullopt;
    }

    void SortByBirthday()
    {
        sort(poets.begin(), poets.end(), 
            [](const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2)
            {return p1.second < p2.second; });
    }
    size_t PoetsAtCenture(int centure)
    {
        size_t count = 0;
        for_each(poets.begin(), poets.end(), [centure, &count](const auto& poet)
            {
                if (poet.second < centure * 100 && poet.second >= (centure - 1) * 100)
                {
                    std::cout << "ops" << std::endl;
                    count++;
                }
            });
        return count;
    }
    friend std::ostream& operator<<(std::ostream& out, const Poets& poets);
};
std::ostream& operator<<(std::ostream& out, const Poets& p)
{
    for (const auto& [surname, birthday] : p.poets)
    {
        out << surname << "\t" << birthday << "\n";
    }
    return out;
}

int main()
{
   // std::tuple t1(1, "Hello", 4.32);
  //  std::cout << std::get<0>(t1) << std::endl;
   // std::cout << std::get<1>(t1) << std::endl;
 //   std::pair p2 = { 1, "hello" };
    Poets p;
   /* auto result = p.FindPoet("Pushkin");
    if (result.has_value())
        std::cout << result.value() << std::endl;
    else
        std::cout << "Not found" << std::endl;*/
    p.SortByBirthday();
    std::cout << p.PoetsAtCenture(19)<<std::endl;



}
