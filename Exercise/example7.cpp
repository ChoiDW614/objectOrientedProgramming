/*
#include <iostream>

class Shape {
public:
	static const double PI;
	virtual void calArea() const = 0;
};
const double Shape::PI = 3.14159;

class TwoDimensional : public Shape {
public:
	virtual void calRound() const = 0;
};

class ThreeDimensional : public Shape {
public:
	virtual void calVolume() const = 0;
};

class Triangle : public TwoDimensional {
public:
	double x, y, z;

};

class Rectangle : public TwoDimensional {
public:
	double Width, Height;

	Rectangle(double w, double h) : Width(w), Height(h) {} // width, height
	void calArea() const override { std::cout << Width * Height << std::endl; }
	void calRound() const override { std::cout << 2 * Width * Height << std::endl; }
};

class Circle : public TwoDimensional {
public:
	double x, y, z;

};

int main() {
	Rectangle R1 = { 3., 5.6 };
	R1.calRound();
}
*/