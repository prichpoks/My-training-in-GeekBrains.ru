// Корнилов Сергей
// Практика на уроке 2
// Группа 1861
// С++ сложные моменты


//

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <optional>
#include <algorithm>
#include <string_view>

//#include <chrono>
#include "Time.h"

//class Timer// Класс для подсчета заьраченного времени на выполнение программы
//{
//private:
//	using clock_t = std::chrono::high_resolution_clock;
//	using second_t = std::chrono::duration<double, std::ratio<1>>;
//
//	std::string m_name;
//	std::chrono::time_point<clock_t> m_begin;
//
//	double elapsed() const
//	{
//		return std::chrono::duration_cast<second_t>(clock_t::now() - m_begin).count();
//	}
//public:
//	Timer() : m_begin(clock_t::now()) {}
//	Timer(std::string name) : m_name(name), m_begin(clock_t::now()) {}
//	void start(std::string name)
//	{
//		m_name = name;
//		m_begin = clock_t::now();
//	}
//	void print() const
//	{
//		std::cout << m_name << ":\t" << elapsed() * 1000 << "ms" << '\n';
//	}
//};
void StlSort(std::vector<int> v)
{
	Timer timer("STL sort");
	std::sort(v.begin(), v.end());
	timer.print();
}

void Bubblesort(std::vector<int> v)
{
	size_t size = v.size();
	int temp;
	Timer timer("Buvvle sort");
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = v[j];
			}
		}
	}
	timer.print();
}

void InsertionSort(std::vector<int> v)
{
	size_t size = v.size();
	int temp, item;
	Timer timer("Insertion sort");
	for (size_t i = 0; i < size; i++)
	{
		temp = v[i];
		item = i - 1;
		while (item >= 0 && v[item] > temp)
		{
			v[item + 1] = v[item];
			v[item] = temp;
			item--;
		}
	}
	timer.print();
}
std::string CreateBigString()
{
	return std::string(1000000, 'a');
}
template<typename T>
class Repository
{
private:
	T m_data;
public:
	Repository() {}
	Repository(const T& t) : m_data(t) {}
	Repository(const Repository& other)
	{
		m_data = other.m_data;
		std::cout << "copy ctor" << std::endl;
	}
	Repository(Repository&& other)
	{
		m_date = move(other.m_data);
		std::cout << "move ctor" << std::endl;
	}
	void operator=(const Repository& other)
	{
		m_data = other.m_data;
	}
	void operator=(Repository&& other)
	{
		m_date = move(other.m_data);
	}
	~Repository() {}
	T data() const
	{
		return m_data;
	}
};
int main()
{
	/*const int value = 10;
	const int* ptr = &value;
	int val = 9;
	int* const ptr1 = &val;
	const int* const ptr2 = &value;*/

	/*constexpr double pi = 3.14;
	int age = 20;
	const int myAge = age;*/
	

	/*size_t size = 10000;
	std::vector<int> numbers;
	for (size_t i = 0; i < size; i++)
	{
		numbers.push_back(rand());
	}
	
	Bubblesort(numbers);
	InsertionSort(numbers);
	StlSort(numbers);*/

	/*std::vector<std::string> v;
	Timer timer("with var");
	
	std::string big_string = CreateBigString();
	v.push_back(move(big_string));
	timer.print();

	timer.start("without var");
	v.push_back(CreateBigString());
	timer.print();*/


	/*Repository<std::string> r1("AAA");
	Repository<std::string> r2("BBB");
	Repository<std::string> r3(r1);
	std::cout << r1.data() << ' ' << r3.data() << std::endl;
	Repository<std::string> r4(std::move(r2));
	std::cout << r2.data() << ' ' << r4.data() << std::endl;*/

	std::string s = "hello";
	std::string s2 = s;
	std::string_view sw = s;
	s[0] = 'h';
	std::cout << s2 << ' ' << sw << std::endl;
}

