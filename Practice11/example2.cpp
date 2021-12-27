/*
#include <iostream>

class Vector2D {
	int x, y;
public:
	Vector2D(int x, int y) : x(x), y(y) {}

	int get_x() const {
		return x;
	}

	int get_y() const {
		return y;
	}

	Vector2D operator+(const Vector2D& v) const
	{
		return Vector2D(x + v.x, y + v.y);
	}
};

std::ostream& operator<<(std::ostream& os, const Vector2D& v)
{
	os << v.get_x() << ", " << v.get_y() << "\n";
	return os;
}

int main() {
	Vector2D v1(10, 2), v2(20, 5);
	std::cout << v1 + v2 << std::endl; // 30, 7 Ãâ·Â
}
*/