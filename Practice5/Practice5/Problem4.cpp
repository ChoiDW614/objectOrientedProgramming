/*
#include <iostream>

int main()
{
	double sum = 0, aver, max, min;
	double input;
	std::cin >> input;
	sum = input;
	max = min = input;
	for (int i = 0; i < 19; i++)
	{
		std::cin >> input;
		sum += input;
		if (max < input)
			max = input;
		else if (min > input)
			min = input;
	}
	aver = sum / 20;
	std::cout << "sum = " << sum << ", average = " << aver
		<< ", max = " << max << ", min = " << min << std::endl;
}
*/