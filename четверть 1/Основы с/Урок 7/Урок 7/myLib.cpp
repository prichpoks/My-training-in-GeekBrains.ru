
#include <iostream>

namespace myLib
{
	void createmas(float *mas, int size)
	{
		srand(time(0));
		for (int i = 0; i < size; i++)
		{
			mas[i] = rand() % 200 - 100;
		}
	}
	void  printmas(float *mas, int size)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << mas[i] << ' ';
		}
		std::cout << '\n';
	}
	void summas(float *mas, int size)
	{
		int res1, res2;
		res1 = res2 = 0;

		for (int i = 0; i < size; i++)
		{
			if (mas[i] < 0)
			{
				res1++;
			}
			else
			{
				res2++;
			}
		}
		std::cout << "count poz elements\n" << res2 << '\n';
		std::cout << "count neg elements\n" << res1 << '\n';
	}
}