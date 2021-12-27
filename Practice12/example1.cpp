#include <iostream>
#include <iomanip>
#include <cmath>

class Shape {
public:
	static double PI;
	virtual void calArea() const = 0;
};

double Shape::PI = 3.14159;

class TwoDimensional : public Shape {
public:
	virtual void calRound() const = 0;
};

class ThreeDimensional : public Shape {
public:
	virtual void calVolume() const = 0;
};

class Triangle : public TwoDimensional {
	double side1, side2, side3;
public:
	Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

	void calArea() const override {
		double s = (side1 + side2 + side3)/2;
		std::cout << sqrt(s * (s - side1) * (s - side2) * (s - side3)) << std::endl;
	}

	void calRound() const override {
		std::cout << side1 + side2 + side3 << std::endl;
	}
};

class Rectangle : public TwoDimensional {
	double width, height;
public:
	Rectangle(double w, double h) : width(w), height(h) {}

	void calArea() const override {
		std::cout << width * height << std::endl;
	}

	void calRound() const override {
		std::cout << 2 * (width + height) << std::endl;
	}
};

class Circle : public TwoDimensional {
	double Radius;
public:
	Circle(double R) : Radius(R) {}

	void calArea() const override {
		std::cout << PI * pow(Radius,2) << std::endl;
	}

	void calRound() const override {
		std::cout << 2 * PI * Radius << std::endl;
	}
};

class Cube : public ThreeDimensional {
	double width, height, depth;
public:
	Cube(double w, double h, double d) : width(w), height(h), depth(d) {}

	void calArea() const override {
		std::cout << 2 * (width * height + height * depth + depth * width) << std::endl;
	}
	
	void calVolume() const override {
		std::cout << width * height * depth << std::endl;
	}
};

class Sphere : public ThreeDimensional {
	double Radius;
public:
	Sphere(double R) : Radius(R) {}

	void calArea() const override {
		std::cout << 4 * PI * pow(Radius, 2) << std::endl;
	}

	void calVolume() const override {
		std::cout << (4/3.) * PI * pow(Radius, 3) << std::endl;
	}
};

int main()
{
	std::cout << std::setprecision(10);

	Triangle t(5, 5, 5);
	t.calArea();
	t.calRound();

	Rectangle r(5, 5);
	r.calArea();
	r.calRound();

	Circle c1(5);
	c1.calArea();
	c1.calRound();

	Cube c2(5, 5, 5);
	c2.calArea();
	c2.calVolume();

	Sphere s(5);
	s.calArea();
	s.calVolume();

	return 0;
}