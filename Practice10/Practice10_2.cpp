/*
#include <iostream>
#include <cmath>

class IntPoint {
public:
	int x; // x 좌표
	int y; // y 좌표
	IntPoint(int x, int y) : x(x), y(y) {}
};

class Rectangle {
	IntPoint corner; // 직사각형의 왼쪽-아래 코너점
	int width; // 직사각형의 폭 
	int height; // 직시각형의 높이 
public:
	Rectangle(IntPoint pt, int w, int h) :
		corner(pt),
		width((w < 0) ? 0 : w), height((h < 0) ? 0 : h) {}
	int perimeter() {
		return 2 * width + 2 * height;
	}
	int area() {
		return width * height;
	}
	int get_width() {
		return width;
	}
	int get_height() {
		return height;
	}
	// 현재 인스턴스 사각형과 r이 겹쳐있다면 true, 그렇지 않으며 false 
	bool intersect(Rectangle r) {
		if ((r.corner.x + r.width < corner.x || r.corner.x > corner.x + width) != true)
			if ((r.corner.y + r.height < corner.y || r.corner.y > corner.y + height) != true)
				return true;

		return false;
	}
	// 대각선의 길이(int 형)를 반환
	int diagonal() {
		return static_cast<int>(sqrt(static_cast<int>(pow(width, 2) + pow(height, 2))));
	}
	// 사각형의 중심점의 좌표를 IntPoint 형으로 반환 
	IntPoint center() {
		IntPoint cen((corner.x+ width / 2), (corner.y+ height / 2));
		return cen;
	}
	// 현재 인스턴스 사각형의 내부(경계포함)에 pt가 있으면 true, 그렇지 않으면 false
	bool is_inside(IntPoint pt) {
		if (pt.x >= corner.x && pt.x <= corner.x + width)
			if (pt.y >= corner.y && pt.y <= corner.y + height)
				return true;
		return false;
	}
};

int main()
{
	IntPoint P1(2, 4), P2(1, 3), P3(6, 1), P4(3, 5);
	Rectangle R1(P1, 3, 6), R2(P2, 3, 6), R3(P3, 1, 2);

	// determine if the current instance rectangle and r overlap
	std::cout << std::boolalpha << "R2: " << R1.intersect(R2) << std::endl;
	std::cout << "R3: " << R1.intersect(R3) << std::endl;

	// get the length of the diagonal line
	std::cout << "diagonal length: " << R1.diagonal() << std::endl;
	
	// get the coordinates of the center point of the rectangle
	std::cout << "x: " << R1.center().x << ", y: " << R1.center().y << std::endl;

	// determine if there's a pt inside an instance rectangle
	std::cout << "R3: " << R1.is_inside(P3) << std::endl;
	std::cout << "R4: " << R1.is_inside(P4) << std::endl;

	return 0;
}
*/