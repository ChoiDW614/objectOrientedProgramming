/*
#include <iostream>
#include <vector>

class A {
public:
	int x;
	A() : x(0) {
		std::cout << x << std::endl;
	}
	A(int xx) : x(xx) {
		std::cout << x << std::endl;
	}
};

class B {
public:
	int x;
	B() : x() {
		std::cout << x << std::endl;
	}
	explicit B(int xx) : x(xx) {
		std::cout << x << std::endl;
	}
};

class S {
public:
	std::vector<int> v;
	S(std::initializer_list<int> I) : v(I) {}
	S(int i1, int i2)
	{
		v.push_back(i1 / 2);
		v.push_back(i2 / 2);
	}
};

int main()
{
	A a1(1), a2{}, a3();	// a3: function declaration?
	a1 = A(2.);
	a1 = 3.;
	a1 = A();
	std::cout << "----------------------" << std::endl;

	A a5{ 1 };
	a5 = { 2 };
	// a5 = { 3. };
	std::cout << "----------------------" << std::endl;

	B b1(1), b2{};
	b1 = B(2);
	// b1 = 3;
	std::cout << "----------------------" << std::endl;

	S s1{ 1, 2, 3, 4, 5 };
	for (auto x : s1.v) std::cout << x;
	std::cout << std::endl;

	S s2{ 1, 2 };
	for (auto x : s2.v) std::cout << x;

	return 0;
}
*/