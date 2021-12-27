/*
#include <iostream>
#include <vector>
#include <algorithm>

class Base {
public:
	std::vector<int> vec;

	Base(double n) : vec(n) {}

	void print() { std::cout << vec.size() << std::endl; }
	
	void printData() {
		for (auto iter = std::begin(vec); iter != std::end(vec); iter++) {
			std::cout << *iter << " ";
		}
		std::cout << '\n';
	}

	void setN(int idx, int x) {
		if (vec.size() > idx) {
			vec[idx] = x;
		}
	}
};

class Derived : public Base {
public:
	Derived(int x) : Base(x) {}

	void insert(int x) {
		vec.push_back(x);
	}
};

int main() {
	Base b1(2), b2(10);	

	b1.print();		// 2 
	b2.print();		// 10
	for (int i = 0; i < 5; i++) {
		b1.setN(i, (i + 1) * 20);
		b2.setN(i, (i + 1) * 10);
	}

	b1.printData();  // 20 40
	b2.printData();  // 10 20 30 40 50 0 0 0 0 0
	
	Derived d(5);
	d.print();             // 5
	d.printData();                   // 0 0 0 0 0
	for (int i = 0; i < 10; i++) {
		d.setN(i, (i + 1) * 3);
	}
	d.printData();       // 3 6 9 12 15
	d.insert(99);         // "Base" class does not have "insert" method.
	d.printData();       // 3 6 9 12 15 99
}
*/