/*
#include <iostream>
using namespace std;

void Fibonacci(int n)
{
	int fib = -1;
	int fib_1 = 1, fib_2 = 1;
	int fib_0 = 0;

	if (n == 1)
		cout << fib_0 << endl;
	else if (n == 2)
		cout << fib_0 << ", " << fib_1 << endl;
	else if (n == 3)
		cout << fib_0 << ", " << fib_1 << ", " << fib_2 << endl;
	else
	{
		cout << fib_0 << ", " << fib_1 << ", " << fib_2 << ", ";
		for (int i = 4; i < n; i++)
		{
			fib = fib_1 + fib_2;
			fib_1 = fib_2;
			fib_2 = fib;
			cout << fib << ", ";
		}
		fib = fib_1 + fib_2;
		cout << fib << endl;
	}
}

int main()
{
	int input;
	cin >> input;
	Fibonacci(input);
	return 0;
}
*/