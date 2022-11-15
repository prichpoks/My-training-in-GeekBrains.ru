// ООП на примере С++
// Урок 8
// Корнилов Сергей

#include <iostream>

//Задание 1
class DivisionByZero : public std::logic_error
{
public:
	DivisionByZero(std::string str) :std::logic_error(str) {}
	const char* what() const
	{
		std::cerr << "Exeption!" << std::endl;
		return std::logic_error::what();
	}

};
template <typename T>
T Mdiv(T first, T second)
{
	if (second == 0)
	{
		throw DivisionByZero("Division by zero");
	}
	return first / second;
}

//Задание 2
class Ex
{
public:
	double x;
	Ex(double _x)
	{
		x = _x;
	}
};

class Bar
{
private:
	double y;
public:
	Bar()
	{
		y = 0;
	}
	void set(double a)
	{
		if (y + a > 100)
		{
			throw Ex(a * y);
		}
		y = a;
	}
};

// Задание 3
class OffTheField
{
	int horizon;
	int vertical;
public:
	OffTheField(int h, int v)
	{
		horizon = h;
		vertical = v;
	}
	void what() const
	{
		if (horizon > 10 || horizon < 1)
		{
			if (vertical > 10 || vertical < 1)
			{
				std::cerr << "the horizon and vertical goes beyond the field! horizon = " << horizon << " vertical = " << vertical << std::endl;
			}
			else
			{
				std::cerr << "the horizon goes beyond the field! horizon = " << horizon << std::endl;
			}
		}
		else
		{
			std::cerr << "the vertical goes beyond the field! vertical = " << vertical << std::endl;
		}
	}
};
class IllegalCommand
{
	int *position;
	int horizon;
	int vertical;
public:
	IllegalCommand(int* p, int h, int v)
	{
		position = p;
		horizon = h;
		vertical = v;
	}
	void what() const
	{
		std::cerr << "The robot is in position\nhorizon = " << position[0] << "\nvertical = " << position[1] << std::endl;
		std::cerr << "The robot cannot move to a position\nhorizon = " << horizon << "\nvertical = " << vertical << std::endl;
	}
};
class Robot
{
	int position[2];
public:
	Robot()
	{
		position[0] = 5;
		position[1] = 5;
	}
	void Step(int horizon, int vertical)
	{
		if (horizon > 10 || horizon < 1 || vertical > 10 || vertical < 1)
		{
			throw OffTheField(horizon, vertical);
		}
		if (position[0] - horizon > 1 || position[0] - vertical > 1 || position[0] - vertical < -1 || position[0] - horizon < -1)
		{
			throw IllegalCommand(position, horizon, vertical);
		}
		position[0] = horizon;
		position[1] = vertical;
		std::cout << "Еhe robot took a step!\nhorizon = " << position[0] << "\nvertical = " << position[1] << std::endl;
	}
	int* PositionRobot()
	{
		return position;
	}
};
int main()
{
	std::cout << "\nEX 1\n" << std::endl;
	try
	{
		std::cout << Mdiv(5, 0);
	}
	catch (const DivisionByZero& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\nEX 2\n" << std::endl;
	try
	{
		Bar p;
		int n;
		std::cout << "Enter n" << std::endl;
		std::cin >> n;
		while (n)
		{
			p.set(n);
			std::cout << "Enter n" << std::endl;
			std::cin >> n;
		}
	}
	catch (const Ex& e)
	{
		std::cerr << "Exeption = " << e.x << std::endl;
	}
	std::cout << "\nEX 1\n" << std::endl;
	try
	{
		Robot robot;
		int* position, h,v;
		char ch;
		std::cout << "The robot is in position\nhorizon = 5\nvertical = 5\nShall we make a move? (Y|N)" << std::endl;
		std::cin >> ch;
		while (ch == 'Y' || ch == 'y')
		{
			std::cout << "Enter step horisont" << std::endl;
			std::cin >> h;
			std::cout << "Enter step vertical" << std::endl;
			std::cin >> v;
			robot.Step(h, v);
			std::cout << "Shall we make a move? (Y|N)" << std::endl;
			std::cin >> ch;
		}
		position = robot.PositionRobot();
		std::cerr << "The robot stopped at the position\nhorizon = " << position[0] << "\nvertical = " << position[1] << std::endl;
	}
	catch (const OffTheField& e)
	{
		e.what();
	}
	catch (const IllegalCommand& e)
	{
		e.what();
	}
	std::cout << "Program ended!" << std::endl;
	return 0;

}