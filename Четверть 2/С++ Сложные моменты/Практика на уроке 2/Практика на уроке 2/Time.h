#include <iostream>
#include <chrono>

class Timer// ????? ??? ???????? ???????????? ??????? ?? ?????????? ?????????
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::string m_name;
	std::chrono::time_point<clock_t> m_begin;

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_begin).count();
	}
public:
	Timer() : m_begin(clock_t::now()) {}
	Timer(std::string name) : m_name(name), m_begin(clock_t::now()) {}
	void start(std::string name)
	{
		m_name = name;
		m_begin = clock_t::now();
	}
	void print() const
	{
		std::cout << m_name << ":\t" << elapsed() * 1000 << "ms" << '\n';
	}
};