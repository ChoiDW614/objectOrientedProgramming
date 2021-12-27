/*
#include <iostream>
#include <cmath>
using namespace std;

void getRoot(double c)
{
	cout << "not a valid equation" << endl;
}

void getRoot(double b, double c)
{
	cout << "x = " << (-c / b) << endl;
}

void getRoot(double a, double b, double c)
{
	if ((b * b - 4 * a * c) < 0)
		cout << "not a real solution" << endl;
	else
		cout << "x = " << ((-b + sqrt(b * b - 4 * a * c)) / (2. * a)) 
		<< ", x = " << ((-b - sqrt(b * b - 4 * a * c)) / (2. * a)) << endl;
}

void solveEq()
{
	double a, b, c;
	cin >> a >> b >> c;
	if (a == 0 && b == 0)
		getRoot(c);
	else if (a == 0)
		getRoot(b, c);
	else
		getRoot(a, b, c);
}

int main()
{
	solveEq();
	solveEq();
	return 0;
}
*/