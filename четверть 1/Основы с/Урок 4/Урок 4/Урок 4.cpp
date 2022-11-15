
#include <iostream>

using namespace std;

int main()
{
	// ЗАДАНИЕ 1
	int a, b;
	a = b = 0;

	cout << "enter A\n";
	cin >> a;
	cout << "enter B\n";
	cin >> b;
	if (a + b > 20 || a + b < 10)
		cout << "false\n";
	else
		cout << "true\n";

	// ЗАДАНИЕ 2
	cout << "enter A\n";
	cin >> a;
	cout << "enter B\n";
	cin >> b;
	if (a == 10 || b == 10 || a + b == 10)
		cout << "true\n";
	else
		cout << "false\n";

	// ЗАДАНИЕ 3
	a = 0;
	cout << "numbers:\n";
	while (a != 50)
	{
		if (a % 2 != 0)
			cout << a << " ";
		a++;
	}

	// ЗАДАНИЕ 4
	b = 2;

	cout << "enter a\n";
	cin >> a;

	if (a > 0)
	{
		if (a == 1)
			cout << "true2\n";
		while (b < a)
		{
			if (a % b == 0)
			{
				cout << "false\n";
				break;
			}
			b++;
		}
		if (a == b)
			cout << "true1\n";
	}
	else
		cout << "false1\n";
	
	//ЗАДАНИЕ 5
	do
	{
		cout << "enter a (a > 0 && a < 3001)\n";
		cin >> a;
	} while (a < 1 || a > 3000);
	if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))
		cout << "a = leap year\n";
	else
		cout << "a = not leap year\n";



	return 0;
}

