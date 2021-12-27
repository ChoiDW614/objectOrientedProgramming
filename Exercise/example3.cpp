/*
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int x = 1, y = 2;
	auto print0 = [=] {std::cout << x << ", " << y << std::endl; };
	auto print1 = [=] ()mutable {std::cout << ++x << ", " << ++y << std::endl; };
	auto print2 = [&] () {std::cout << x++ << ", " << y++ << std::endl; };
	auto print3 = [=, &y] ()  {std::cout << x << ", " << y++ << std::endl; };

	print0();    // 1, 2
	std::cout << "after: " << x << " , " << y << std::endl;  // 1, 2
	x = 1; y = 2;        print1();      // 2, 3
	std::cout << "after: " << x << " , " << y << std::endl;  // 1, 2
	x = 1; y = 2;        print2();      // 1, 2
	std::cout << "after: " << x << " , " << y << std::endl;  // 2, 3
	x = 1; y = 2;        print3();      // 1, 2
	std::cout << "after: " << x << " , " << y << std::endl;  // 1, 3
	return 0;
}
*/