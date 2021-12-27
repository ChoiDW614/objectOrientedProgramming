/*
#include <iostream>

class A {
	int x;
public:
	A(int x) : x(x) {}

	int GetX() {
		return x;
	}

	int GetX() const {
		return x;
	}

	A *Max(A* a)
	{
		if (x >= a->x)
			return this;
		else
			return a;
	}
};

int main()
{
	const A a1(10);
	A a2(5), a3(3);
	std::cout << a1.GetX() << std::endl; // 10 출력
	std::cout << a2.GetX() << std::endl; // 5 출력

	A* p = a2.Max(&a3); // Max: a2.x와 a3.x를 비교하여 
								// 큰 값을 가지는 인스턴스 주소 반환
	std::cout << p->GetX() << std::endl; // 5출력
}
*/