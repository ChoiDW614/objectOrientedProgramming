/*             Object-Oriented Programming, Final exam (2021-2)                       */
// Write your answers in Korean or English(����� �ѱ��� �Ǵ� ����� �ۼ��Ͻÿ�).
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>

static std::string Department = "MECH";
static std::string StudentId = "2018100778";
static std::string Name = "Choi dongwook";
static std::string ExamCode = "d395lg,g+0*k^263Lkne+";

void OOP_2021_2_Exam(std::string ExamCode, std::string SourcePath, std::string Department, std::string StudentId, std::string Name);
static std::string SourcePath = __FILE__;

//*** 1�� ����
class A {
	int x, y;
public:
	A() : x(0), y(0) {}
	A(int a, int b) : x(a), y(b) {}

	void print() const { std::cout << x << ", " << y << std::endl; }
	friend std::ostream& operator<<(std::ostream& os, const A a);
};

std::ostream& operator<<(std::ostream& os, const A a)
{
	os << a.x << ", " << a.y;
	return os;
}

//*** 2�� ����

class B {
public:
	static double x;
	
	B() { x += 1; }
	~B() { x -= 1; }

	static void print() { std::cout << x << std::endl; }
};

double B::x = 0;

//*** 3�� ����

class C {
	int* pX;
public:
	C(int x) : pX(new int(x)) {}
	~C() { delete pX; }

	virtual void print() { std::cout << *pX; }
};

class D : public C {
	int* pY;
public:
	D(int x, int y) : C(x), pY(new int(y)) {}
	~D() { delete pY; }

	void print() override { 
		C::print();
		std::cout << ", " << *pY << std::endl;
	}
};

//*** 5�� ����

	///********** 5��) �Ʒ��� VectorN Ŭ���� ���ø��� �����϶�(main �Լ� ���� �ۼ�). - 7�� 
	///**********      VectorN�� ���� ������ private�� *p�� size�� ������, p�� �������� �Ҵ�� size���� �迭�̴�.
	///**********      VectorN�� �������� �Ķ���ʹ� ������� ���� �Ҵ��� �迭�� ũ��, ù��° ����� ��, �ι�° ��Һ��� ���� ��ҿ��� �������̴�.
	///**********      VectorN���� friend ������ ����.
	///**********      VectorN�� �Ҵ� �����ڴ� �޸𸮸� �������� �ʰ� ���ο� �޸𸮸� �Ҵ��ؼ� ��� ���� �����Ѵ�.
	///**********      VectorN�� [n]�� p�� n��° ����̸�, [n]���� p�� n��° ��Ҹ� ������ ���� �ִ�.
	///**********      new�� ���� �Ҵ�� �޸𸮴� instance�� �Ҹ�Ǹ� �����Ǿ�� �Ѵ�. 
	///**********      ������, �Ҹ���, ������(3��) overloading(���� ����)�� �����ϰ�, �ΰ������� �� ���� ��� �Լ�(�̸��� �����Ӱ� ���)�� �����Ѵ�.

/*
template <class T>
class VectorN {
	int size;
	T p = new T[size];
public:
	VectorN(int s, T k0, T k1) : size(s) {
		int k = k0;
		for (int i = 0; i < size; i++) {
			p + i = k;
			k += k1;
		}
	}
	~VectorN() { delete []p; }
	
	VectorN<T>& operator=(VectorN<T> v) {
		VectorN<T> newtemp(size, p[0], p[1] - p[0]);
		return newtemp;
	}
	
	VectorN<T>& operator[](VectorN<T> v, int idx) {
		return p[idx];
	}
	
	void print() {
		for (int i = 0; i < size; i++) {
			std::cout << p[i] << std::endl;
		}
	}
};

template<class T>
std::ostream& operator<<(std::ostream& os, VectorN<T> vec) {
	vec.print();
	return os;
}
*/

//*** 6�� ����

template<class T>
void print(T x) {
	for (auto iter = std::begin(x); iter != std::end(x); iter++) {
		std::cout << *iter << " ";
	}
}



int main() {
	OOP_2021_2_Exam(ExamCode, SourcePath, Department, StudentId, Name);

	///********** 1��) �Ʒ��� AŬ������ �����ϰ�, �ʿ��� �Լ�, �����ڸ� �����϶�(main �Լ� ���� �ۼ�). - 3��
	///**********      A Ŭ������ instance data member�� ���� ������ private�̸�, int������ x, y�� �������� ����Ѵ�. 
	///**********      �����ڿ� �Ҹ��ڸ� �����ϰ�, �� ���� print �� <<�� �����Ѵ�(��� �Ǵ� ����).
	std::cout << "*** 1 ***" << std::endl;
	
	A a1, a2(1, 3);
	const A a3(2, 5);

	a1.print();		// 0, 0 ���(x, y)
	a2.print();		// 1, 3 ���(x, y)
	a3.print();		// 2, 5 ���(x, y)
	std::cout << std::endl;

	std::cout << a1 << std::endl;	// 0, 0 ���(x, y)
	std::cout << a2 << std::endl;	// 1, 3 ���(x, y)
	std::cout << a3 << std::endl;	// 2, 5 ���(x, y)
	
	std::cout << std::endl;

	///********** 2��) �Ʒ��� BŬ������ �����ϰ�, �ʿ��� �Լ�, �����ڸ� �����϶�(main �Լ� ���� �ۼ�). - 3��
	///**********      ���� ���� �� ���� �Լ��� ����ϸ� 0�� ó����.
	///**********      �����ڿ� �Ҹ��ڸ� �����ϰ�, �� ���� ������ ����� print�� �����Ѵ�. (overloading�ϸ� 0��)
	std::cout << "*** 2 ***" << std::endl;
	
	B b1; 	b1.print();		// 1���(���� �����ϴ� B���� �ν��Ͻ�)
	B b2; 	b2.print();		// 2���(���� �����ϴ� B���� �ν��Ͻ�)
	B *p = new B[3];
	B::print();				// 5���(���� �����ϴ� B���� �ν��Ͻ�)
	delete [] p;
	B b3; 	b3.print();		// 3���(���� �����ϴ� B���� �ν��Ͻ�)
	
	std::cout << std::endl;
	

	///********** 3��) �Ʒ��� C, D Ŭ������ �����ϰ�, �ʿ��� �Լ�, �����ڸ� �����϶�(main �Լ� ���� �ۼ�). - 5�� 
	///**********      C Ŭ������ ������ ��� int *pX(private ���� ����)�� ������, �Ķ���Ͱ� 1���� �����ڿ��� int ������ �����Ҵ��ϰ� �Ķ���Ͱ����� �ʱ�ȭ�Ѵ�. 
	///**********      D Ŭ������ ������ ��� int *pY(private ���� ����)�� ������, �Ķ���Ͱ� 2���� �����ڿ��� pX�� C Ŭ������ �����ڷ� �ʱ�ȭ�ϰ�, pY�� int ������ �����Ҵ��ϰ� �� ��° �Ķ���Ͱ����� �ʱ�ȭ�Ѵ�. 	
	///**********      C Ŭ�������� D Ŭ������ friend�� ������ �� ����.
	///**********      new�� ���� �Ҵ�� �޸�(pX, pY)�� instance�� �Ҹ�Ǹ� �����Ǿ�� �Ѵ�. 
	///**********      �����ڿ� �Ҹ��ڸ� �����ϰ�, print �Լ��� �����Ѵ�.  (overriding�� ����)
	std::cout << "*** 3 ***" << std::endl;
	
	C* pC = new D(1, 2);
	pC->print();		// 1�� 2 ���(*pX, *pY)
	delete pC;
	
	std::cout << std::endl;

	///********** 4��) �Ʒ��� ���� x�� ������ ������ ������([0, 100]) �����ǵ��� min_max�� ���� �Լ��� �̿��Ͽ� �Ʒ���(//*** 4�� ���� ����) �����϶�. - 1�� 
	///**********      �ּ����� �ڵ�� �ۼ��ϰ�, �ٸ� ǥ�� �Լ� ���� ����� �� ����. 
	//*** 4�� ����

	auto min_max = [](int& x, int a, int b) { if (x < a) x = a; else if (x > b) x = b; };

	std::cout << "*** 4 ***" << std::endl;
	
	int x;
	x = 10; min_max(x, 0, 100); std::cout << x << " ";	// 10 ���
	x = -1; min_max(x, 0, 100); std::cout << x << " ";	// 0 ���
	x = 107; min_max(x, 0, 100); std::cout << x << std::endl;	// 100 ���
	
	std::cout << std::endl;

	///********** 5��) �Ʒ��� VectorN Ŭ���� ���ø��� �����϶�(main �Լ� ���� �ۼ�). - 7�� 
	///**********      VectorN�� ���� ������ private�� *p�� size�� ������, p�� �������� �Ҵ�� size���� �迭�̴�.
	///**********      VectorN�� �������� �Ķ���ʹ� ������� ���� �Ҵ��� �迭�� ũ��, ù��° ����� ��, �ι�° ��Һ��� ���� ��ҿ��� �������̴�.
	///**********      VectorN���� friend ������ ����.
	///**********      VectorN�� �Ҵ� �����ڴ� �޸𸮸� �������� �ʰ� ���ο� �޸𸮸� �Ҵ��ؼ� ��� ���� �����Ѵ�.
	///**********      VectorN�� [n]�� p�� n��° ����̸�, [n]���� p�� n��° ��Ҹ� ������ ���� �ִ�.
	///**********      new�� ���� �Ҵ�� �޸𸮴� instance�� �Ҹ�Ǹ� �����Ǿ�� �Ѵ�. 
	///**********      ������, �Ҹ���, ������(3��) overloading(���� ����)�� �����ϰ�, �ΰ������� �� ���� ��� �Լ�(�̸��� �����Ӱ� ���)�� �����Ѵ�.
	std::cout << "*** 5 ***" << std::endl;
	/*
	VectorN<int> v1(5, 10, 2);			// 5���� int�� �迭�� 10, 12, 14, 16, 18�� �ʱ�ȭ
	VectorN<double> v2(5, 1.2, 0.3);	// 5���� double�� �迭�� 1.2, 1.5, 1.8, 2.1, 2.4�� �ʱ�ȭ

	// std::cout << v1[0] << std::endl;	// 10 ���(v1.p[0])
	std::cout << v1 << std::endl;		// 10 12 14 16 18 ���(v1.p ���)
	std::cout << v2 << std::endl;		// 1.2 1.5 1.8 2.1 2.4 ���(v2.p ���)

	VectorN<double> v3(2, 2.3, 0.1);
	std::cout << v3 << std::endl;		// 2.3 2.4 ���(v3.p ���)
	v3 = v2;
	// v2[0] = 0.1;
	std::cout << v3 << std::endl;		// 1.2 1.5 1.8 2.1 2.4 ���(v3.p ���)
	std::cout << v2 << std::endl;		// 0.1 1.5 1.8 2.1 2.4 ���(v2.p ���)
	*/
	std::cout << std::endl;
	

	///********** 6��) �Ʒ��� print �Լ� ���ø��� �����϶�(main �Լ� ���� �ۼ�). - 1�� 
	std::cout << "*** 6 ***" << std::endl;
	
	std::vector<int> vec {10, 20, 30, 40, 50};
	std::list<double> lst {1.5, 2.5, 3.5, 4.5, 5.5};

	print(vec);							// 10 20 30 40 50 ���
	std::cout << std::endl;
	print(lst);							// 1.5 2.5 3.5 4.5 5.5 ���
	std::cout << std::endl;
	
}