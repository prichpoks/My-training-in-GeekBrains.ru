// ООП на примере c++
// Урок 1
// Корниллов Сергей

#include <iostream>
#include <cstdint>

// Задание 1
class Power
{
private:
	int m_a;
	int m_pow;
public:
	Power()
	{
		m_a = 2;
		m_pow = 2;
	}
	void set(int a, int pow)
	{
		m_a = a;
		m_pow = pow;
	}
	void calculate()
	{
		int res;
		if (m_pow == 0)
			res = 1;
		else if (m_pow == 1)
			res = m_a;
		else
		{
			res = m_a;
			for (int i = m_pow; i > 1; i--)
				res *= m_a;
		}
		std::cout << res << std::endl;
	}
};

// Задание 2
class RGBA
{
private:
	std::uint8_t m_red;
	std::uint8_t m_green;
	std::uint8_t m_blue;
	std::uint8_t m_alpha;

public:
	RGBA()
	{
		m_red = 0;
		m_green = 0;
		m_blue = 0;
		m_alpha = 255;
	}
	RGBA(int r, int g, int b, int a)
	{
		m_red = r;
		m_green = g;
		m_blue = b;
		m_alpha = a;
	}
	void print()
	{
		std::cout << "RED - " << m_red << "\nGREEN - " << m_green << "\nBLUE - " << m_blue << "\nALPHA - " << m_alpha << std::endl;
	}
	
};

// Задание 
class Stack
{
private:
	int arr[10];
	int size;
public:
	Stack()
	{
		size = -1;
	}
	void reset()
	{
		size = -1;
	}
	bool push(int i)
	{
		if (size < 9)
			arr[++size] = i;
		else
		{
			std::cout << "stack overflow!" << std::endl;
			return false;
		}
		return true;
	}
	int pop()
	{
		if (size == -1)
		{
			std::cout << "stack is empty!" << std::endl;
			return -1;
		}
		else
			return arr[size--];
	}
	void print()
	{
		if (size == -1)
		{
			std::cout << "stack is empty!" << std::endl;
		}
		else
			for (int i = size; i > -1; i--)
				std::cout << "[ " << arr[i] << " ]\n";
	}
};
int main()
{
	///////////////////////////////////////////////////////////////////
	Power powr;
	powr.calculate();
	powr.set(2, 3);
	powr.calculate();
	//////////////////////////////////////////////////////////////////
	RGBA rgba(3,9,12,55);
	rgba.print();
	///////////////////////////////////////////////////////////////////
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}