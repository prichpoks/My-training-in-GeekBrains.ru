// Корнилов Сергей
// Группа 1861
// С++ Сложные моменты
// Урок 4

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <numeric>
// Задание 1
template<typename T>
void insert_sorted(std::vector<T> &vec, T nbr)
{
    auto iter = std::lower_bound(vec.begin(), vec.end(), nbr);
    vec.insert(iter, nbr);
}

// Задание 2
void CreateDoubleVector(std::vector<double> &vd)
{
    srand(time(NULL));
    std::generate(vd.begin(), vd.end(), []() {return static_cast<double>(rand() % 1000) / 9.12; });
}
void CreateIntVector(std::vector<double> vd, std::vector<int> &vi)
{
    std::transform(vd.begin(), vd.end(), std::back_inserter(vi), [](double i) {return static_cast<int>(i); });
}
template<typename T>
void PrintVector(std::vector<T> vc)
{
    std::copy(vc.begin(), vc.end(), std::ostream_iterator<T> {std::cout, ", "});
}
double ErrorSignal(std::vector<double> vd, std::vector<int> vi)
{
    /*std::cout << "VD = " << std::accumulate(vd.begin(), vd.end(), 0.0) << std::endl;
    std::cout << "VI = " << static_cast<double>(std::accumulate(vi.begin(), vi.end(), 0)) << std::endl;*/
    return  pow(std::accumulate(vd.begin(), vd.end(), 0.0) - static_cast<double>(std::accumulate(vi.begin(), vi.end(), 0)), 2);
}



int main()
{
   /* std::vector<int> vc = { 1, 2, 4, 4, 1, 2, 4,5 };
    for (auto x : vc)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    std::sort(vc.begin(), vc.end());
    for (auto x : vc)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    insert_sorted(vc, 6);
    for (auto x : vc)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;*/
    std::vector<double> vd(100);
    CreateDoubleVector(vd);
    PrintVector(vd);
    std::vector<int> vi;
    CreateIntVector(vd, vi);
    std::cout << std::endl;
    std::cout << std::endl;
    PrintVector(vi); 
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "EROR NBR == " << ErrorSignal(vd, vi);

} 