/*
#include <iostream>

template <class T>
class Point {
	T x;
	T y;
public:
	Point(T x, T y) : x(x), y(y) {}

	T get_x() { return x; }
	T get_y() { return y; }
	void set_x(T x) { this->x = x; }
	void set_y(T y) { this->y = y; }

	void print();
	void input();
	friend std::ostream& operator<<(std::ostream& os, const Point<T>& p);
};

template <class T>
void Point<T>::print() {
	std::cout << "( " << get_x() << ", " << get_y() << " )" << std::endl;
}

template <class T>
void Point<T>::input() {
	T x, y;
	std::cin >> x >> y;
	set_x(x);
	set_y(y);
}

int main()
{
	Point<int> P1(457, 523);
	P1.print();
	P1.input();
	P1.print();

	Point<double> P2(345.302, 295.234);
	P2.print();
	P2.input();
	P2.print();
}
*/