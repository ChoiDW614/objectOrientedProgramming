/*
#include <iostream>

int sum(int x, int y)
{
	return x + y;
}

void sum(int x, int y, int* s)
{
	*s = x + y;
}

void sum(int x, int y, int& s)
{
	s = x + y;
}

int main()
{
	int x, y, s1, s2, s3;
	std::cin >> x >> y;
	s1 = sum(x, y);
	sum(x, y, &s2);
	sum(x, y, s3);
	std::cout << s1 << ' ' << s2 << ' ' << s3 << '\n';
}
*/