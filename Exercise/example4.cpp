/*
#include <iostream>
#include <functional>
#include <algorithm>

std::function<double(double)> derivative0 (std::function<double(double)> f, double h) {
	return [f, h](double x) { return (f(x + h) - f(x)) / h; };
}

double fun(double x) { return 3 * x * x + 5; }

int main() {
	double h = 0.00001;
	auto der0 = derivative0(fun, h);
	std::cout << der0(5.) << std::endl;

	auto der1 = [h](double x) {return (fun(x + h) - fun(x)) / h; };
	std::cout << der1(5.) << std::endl;
	return 0;
}
*/