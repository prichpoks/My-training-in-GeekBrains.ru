

#include <iostream>

bool simple(long long n) 
{
	for (long long i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	long long x;
	std::cout << "Enter x - ";
	std::cin >> x;
	if(simple(x))
		std::cout << "simple\n";
	else
		std::cout << "not simple\n";
	return 0;
}

