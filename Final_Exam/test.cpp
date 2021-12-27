/*             Object-Oriented Programming, Final exam (2021-2)                       */
// Write your answers in Korean or English(답안은 한국어 또는 영어로 작성하시오).
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

//*** 1번 정답
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

//*** 2번 정답

class B {
public:
	static double x;
	
	B() { x += 1; }
	~B() { x -= 1; }

	static void print() { std::cout << x << std::endl; }
};

double B::x = 0;

//*** 3번 정답

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

//*** 5번 정답

	///********** 5번) 아래의 VectorN 클래스 템플릿을 정의하라(main 함수 위에 작성). - 7점 
	///**********      VectorN은 접근 권한이 private인 *p와 size를 가지며, p는 동적으로 할당된 size개의 배열이다.
	///**********      VectorN의 생성자의 파라메터는 순서대로 동적 할당할 배열의 크기, 첫번째 요소의 값, 두번째 요소부터 이전 요소와의 증가값이다.
	///**********      VectorN에서 friend 지정은 없다.
	///**********      VectorN의 할당 연산자는 메모리를 공유하지 않고 새로운 메모리를 할당해서 요소 값을 복사한다.
	///**********      VectorN의 [n]는 p의 n번째 요소이며, [n]으로 p의 n번째 요소를 수정할 수도 있다.
	///**********      new로 동적 할당된 메모리는 instance가 소멸되면 해제되어야 한다. 
	///**********      생성자, 소멸자, 연산자(3개) overloading(비멤버 포함)을 제외하고, 부가적으로 한 개의 멤버 함수(이름은 자유롭게 사용)만 정의한다.

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

//*** 6번 정답

template<class T>
void print(T x) {
	for (auto iter = std::begin(x); iter != std::end(x); iter++) {
		std::cout << *iter << " ";
	}
}



int main() {
	OOP_2021_2_Exam(ExamCode, SourcePath, Department, StudentId, Name);

	///********** 1번) 아래의 A클래스를 정의하고, 필요한 함수, 연산자를 정의하라(main 함수 위에 작성). - 3점
	///**********      A 클래스의 instance data member의 접근 권한은 private이며, int형으로 x, y의 변수명을 사용한다. 
	///**********      생성자와 소멸자를 제외하고, 한 개의 print 및 <<를 정의한다(멤버 또는 비멤버).
	std::cout << "*** 1 ***" << std::endl;
	
	A a1, a2(1, 3);
	const A a3(2, 5);

	a1.print();		// 0, 0 출력(x, y)
	a2.print();		// 1, 3 출력(x, y)
	a3.print();		// 2, 5 출력(x, y)
	std::cout << std::endl;

	std::cout << a1 << std::endl;	// 0, 0 출력(x, y)
	std::cout << a2 << std::endl;	// 1, 3 출력(x, y)
	std::cout << a3 << std::endl;	// 2, 5 출력(x, y)
	
	std::cout << std::endl;

	///********** 2번) 아래의 B클래스를 정의하고, 필요한 함수, 연산자를 정의하라(main 함수 위에 작성). - 3점
	///**********      전역 변수 및 전역 함수를 사용하면 0점 처리함.
	///**********      생성자와 소멸자를 제외하고, 한 개의 데이터 멤버와 print를 정의한다. (overloading하면 0점)
	std::cout << "*** 2 ***" << std::endl;
	
	B b1; 	b1.print();		// 1출력(현재 존재하는 B형의 인스턴스)
	B b2; 	b2.print();		// 2출력(현재 존재하는 B형의 인스턴스)
	B *p = new B[3];
	B::print();				// 5출력(현재 존재하는 B형의 인스턴스)
	delete [] p;
	B b3; 	b3.print();		// 3출력(현재 존재하는 B형의 인스턴스)
	
	std::cout << std::endl;
	

	///********** 3번) 아래의 C, D 클래스를 정의하고, 필요한 함수, 연산자를 정의하라(main 함수 위에 작성). - 5점 
	///**********      C 클래스의 데이터 멤버 int *pX(private 접근 권한)를 가지며, 파라메터가 1개인 생성자에서 int 형으로 동적할당하고 파라메터값으로 초기화한다. 
	///**********      D 클래스의 데이터 멤버 int *pY(private 접근 권한)를 가지며, 파라메터가 2개인 생성자에서 pX는 C 클래스의 생성자로 초기화하고, pY는 int 형으로 동적할당하고 두 번째 파라메터값으로 초기화한다. 	
	///**********      C 클래스에서 D 클래스를 friend로 지정할 수 없다.
	///**********      new로 동적 할당된 메모리(pX, pY)는 instance가 소멸되면 해제되어야 한다. 
	///**********      생성자와 소멸자를 제외하고, print 함수만 정의한다.  (overriding은 가능)
	std::cout << "*** 3 ***" << std::endl;
	
	C* pC = new D(1, 2);
	pC->print();		// 1과 2 출력(*pX, *pY)
	delete pC;
	
	std::cout << std::endl;

	///********** 4번) 아래와 같이 x의 범위가 지정된 범위로([0, 100]) 조정되도록 min_max를 람다 함수를 이용하여 아래에(//*** 4번 정답 이후) 정의하라. - 1점 
	///**********      최소한의 코드로 작성하고, 다른 표준 함수 등을 사용할 수 없다. 
	//*** 4번 정답

	auto min_max = [](int& x, int a, int b) { if (x < a) x = a; else if (x > b) x = b; };

	std::cout << "*** 4 ***" << std::endl;
	
	int x;
	x = 10; min_max(x, 0, 100); std::cout << x << " ";	// 10 출력
	x = -1; min_max(x, 0, 100); std::cout << x << " ";	// 0 출력
	x = 107; min_max(x, 0, 100); std::cout << x << std::endl;	// 100 출력
	
	std::cout << std::endl;

	///********** 5번) 아래의 VectorN 클래스 템플릿을 정의하라(main 함수 위에 작성). - 7점 
	///**********      VectorN은 접근 권한이 private인 *p와 size를 가지며, p는 동적으로 할당된 size개의 배열이다.
	///**********      VectorN의 생성자의 파라메터는 순서대로 동적 할당할 배열의 크기, 첫번째 요소의 값, 두번째 요소부터 이전 요소와의 증가값이다.
	///**********      VectorN에서 friend 지정은 없다.
	///**********      VectorN의 할당 연산자는 메모리를 공유하지 않고 새로운 메모리를 할당해서 요소 값을 복사한다.
	///**********      VectorN의 [n]는 p의 n번째 요소이며, [n]으로 p의 n번째 요소를 수정할 수도 있다.
	///**********      new로 동적 할당된 메모리는 instance가 소멸되면 해제되어야 한다. 
	///**********      생성자, 소멸자, 연산자(3개) overloading(비멤버 포함)을 제외하고, 부가적으로 한 개의 멤버 함수(이름은 자유롭게 사용)만 정의한다.
	std::cout << "*** 5 ***" << std::endl;
	/*
	VectorN<int> v1(5, 10, 2);			// 5개의 int형 배열로 10, 12, 14, 16, 18로 초기화
	VectorN<double> v2(5, 1.2, 0.3);	// 5개의 double형 배열로 1.2, 1.5, 1.8, 2.1, 2.4로 초기화

	// std::cout << v1[0] << std::endl;	// 10 출력(v1.p[0])
	std::cout << v1 << std::endl;		// 10 12 14 16 18 출력(v1.p 요소)
	std::cout << v2 << std::endl;		// 1.2 1.5 1.8 2.1 2.4 출력(v2.p 요소)

	VectorN<double> v3(2, 2.3, 0.1);
	std::cout << v3 << std::endl;		// 2.3 2.4 출력(v3.p 요소)
	v3 = v2;
	// v2[0] = 0.1;
	std::cout << v3 << std::endl;		// 1.2 1.5 1.8 2.1 2.4 출력(v3.p 요소)
	std::cout << v2 << std::endl;		// 0.1 1.5 1.8 2.1 2.4 출력(v2.p 요소)
	*/
	std::cout << std::endl;
	

	///********** 6번) 아래의 print 함수 템플릿을 정의하라(main 함수 위에 작성). - 1점 
	std::cout << "*** 6 ***" << std::endl;
	
	std::vector<int> vec {10, 20, 30, 40, 50};
	std::list<double> lst {1.5, 2.5, 3.5, 4.5, 5.5};

	print(vec);							// 10 20 30 40 50 출력
	std::cout << std::endl;
	print(lst);							// 1.5 2.5 3.5 4.5 5.5 출력
	std::cout << std::endl;
	
}