/*
#include <iostream>
#include <iomanip>
using namespace std;

double factorial(int n)
{
	int k = 1;
	for (int i = 1; i <= n; i++)
		k *= i;
	return k;
}

int main()
{
	double Euler = 1, eps = 1;
	int num = 1;
	while (eps >= 0.00001)
	{
		eps = 1 / factorial(num);
		Euler += eps;
		num++;
	}
	cout << setprecision(10);
	cout << Euler << endl;
}
*/