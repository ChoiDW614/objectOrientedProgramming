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
	std::cout << a1.GetX() << std::endl; // 10 ���
	std::cout << a2.GetX() << std::endl; // 5 ���

	A* p = a2.Max(&a3); // Max: a2.x�� a3.x�� ���Ͽ� 
								// ū ���� ������ �ν��Ͻ� �ּ� ��ȯ
	std::cout << p->GetX() << std::endl; // 5���
}
*/