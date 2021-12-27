/*
#include <iostream>

class Base {
	double point1;
public:
	Base(double b) : point1(b) {}

	virtual void print() const {
		std::cout << point1 << std::endl;
	}

	double get_point1() const {
		return point1;
	}
};

class Derived : public Base {
	double point2;
public:
	Derived(double B, double D) : point2(D), Base(B) {}

	void print() const override {
		std::cout << get_point1() << ", " << point2 << std::endl;
	}

	bool operator<(const Derived& D)
	{
		if ((get_point1() + point2) < (D.get_point1() + D.point2))
			return true;
		else
			return false;
	}
};

int main()
{
	// All data members of Base and Derived classes must be declared 
	// as private access types
	Base* p1 = new Derived(10, 20);		// (x, y)
	Base* p2 = new Base(5);			// (x) 
	p1->print();			// prints 10, 20
	p1->Base::print();		// prints 10
	p2->print(); 			// prints 5
	Derived* p3 = dynamic_cast<Derived*>(p1);
	if (p3 != nullptr) p3->print();			// prints 10, 20

	const Base b1 = *p2;
	b1.print();				// prints 5

	Derived d1(1, 3), d2(2, 4);
	Derived d3 = (d1 < d2) ? d1 : d2;	// operator <: (d1.x+d1.y) < (d2.x+d2.y)
	d3.print();				// prints 1, 3
}
*/