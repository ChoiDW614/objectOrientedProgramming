/*
#include <iostream>
#include <iomanip>
#include <random>

int main() {
	std::random_device rdev;
	std::mt19937 mt(rdev());
	// std::uniform_int_distribution<int> dist(0, 99);
	std::normal_distribution<double> dist(50., 10.);
	int histogram[100] = { 0 };

	for (int i = 0; i < 100; i++) {
		int r = dist(mt);
		while (r <= 0 && r <= 99)
		{
			r = dist(mt);
		}
		histogram[i] = r;
	}

	for (int i = 0; i < 100; i++)
		std::cout << i << ": " << histogram[i] << std::endl;
}
*/