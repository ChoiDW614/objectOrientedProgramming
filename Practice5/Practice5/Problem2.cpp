#include <iostream>
int main() {
	int a = 0;
	while (a < 20) {
		int b = 0;
		while (b < 10) {
			if ((a + b) % 2 == 0)
				std::cout << "*";
			b++;
		}
		std::cout << '\n';
		a++;
	}
}
