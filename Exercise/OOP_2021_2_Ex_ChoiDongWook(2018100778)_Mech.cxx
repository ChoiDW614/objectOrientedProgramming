/*             Object-Oriented Programming, Midterm exam (2021-2)                       */
// Write your answers in Korean or English(답안은 한국어 또는 영어로 작성하시오). 
#include <iostream> 
#include <string> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <vector> 

static std::string Department = "Mech";           // 학과(한글/영어 가능, 중국어 금지) 
static std::string StudentId = "2018100778";     // 학번(숫자로 구성된 문자열) 
static std::string Name = "ChoiDongWook";        // 이름(한글/영어 가능, 중국어 금지)
static std::string ExamCode = "exercise";        // 시험마다 다른 코드 지정, test에서는 “exercise”로 지정
// “exercise” 및 시험시간에 공개한 코드가 아니면 동작 불가 

void OOP_2021_2_Exam(std::string ExamCode, std::string SourcePath, std::string Department, std::string StudentId, std::string Name);
static std::string SourcePath = __FILE__;

// 답안 코드 작성, 전처리(preprocessors), 전역 변수(global variables), 함수(functions), 클래스 (classes), …

// Notation: 
// 1. a^b denotes a raised the power b(a^b는 a의 b제곱)
// 2. [a, b] denotes the range from a to b, and a and b are inclusive
//    ([a, b]는 a부터 b까지의 범위이며, a와 b를 포함한다)

/*
1(10). Trace the evaluation of the following expressions, and write their resulting values and corresponding variables
(아래 수식의 평가 과정(결과 값 및 연관된 변수를 포함)을 설명하라).
(example, x = 1+4/2; -> x = 1+2; -> x = 3;)
a)
int x = 10, y = 2, z;		//	x = 10, y = 2
y += x++ + y%10;            // y = 2 + 10 + 2 % 10 -> y = 14, x = 11
z = x;                      // z = 11
b)
int x = 3;					// x = 3
auto result = 4 < x < 10;	// 4 < x -> 0(false), 0 < 10 -> 1(true), auto result = true, auto -> bool
c)
int x = 3;					// 
auto result = (x =! 3);		// !3 -> false, x = 0(false), auto -> int, result = 0
d)
int F(int n) { return n*2; }
int x = F(12%10+5 + F(12)/F(2));		//
e)
int x = 10;		//
int &r = x;		// x 의 별칭으로 r을 할당
int &rr = r;	// r 의 reference를 rr에 할당
rr = 2;			// rr = 2 -> r= 2 -> x =2
int xx = x;		// xx = x -> xx = 2
int xxx = r;	// xxx = r -> xxx = x -> xxx = 2
*/
// Please perform "build/run" after completing problem 1
// (1번 작성후 "build/run"을 진행하시오).


/*
2(10). Explain any errors in the following program
(아래 프로그램의 오류가 있으면 설명하라).
a)
int F(int x, y) { return x+y; }			// parameter y의 자료형이 지정되어 있지 않다.
b)
std::cout << sqrt(2., 1.) << std::endl;	//	sqrt함수는 parameter의 갯수가 1개이다.
c)
std::vector x(10, 3);					//	vector의 자료형을 지정해주지 않았다.
d)
for(int x = 0 ; x < 10 ; x++ );			// for문뒤에 세미콜론이 있어 emptystate를 10번 실행한뒤에
std::cout << x << std::endl;		//		x를 한번 출력한다.
e)
void F(int x1 = 0, int x2 = 0, int x3) {}	//	디폴트 값을 지정할 때는 뒤에서부터 지정해 주어야 한다.

*/
// Please perform "build/run" after completing problem 2
// (2번 작성후 "build/run"을 진행하시오).

/*
* Explain how the following code fragment works(the final values of variables and process)
(아래 코드의 동작을 설명하라(변수에 저장되는 값과 처리 과정)).
3(5).
std::vector<int> data[3];
for(int i = 0 ; i < 3 ; ++i){
do {
data[i] = rand()%10;
for(int k = 0 ; k < i ; ++k)
if(data[k] == data[i]) break;
}while(k<i);
}

//
//
//
//
//
//
//
//

4(5).
int x1 = 10, x2 = 20;
int *p = &x1;
++(*p);
p = &x2;
++(*p);

//
//
//
//
//
//
//
//

5(5).
std::vector<int> data(3, 10);
int i = 0;
for(auto x:data)
x = ++i;
for(auto x:data)
std::cout << x << ' ';

//
//
//
//
//
//
//
//
*/
// Please perform "build/run" after completing problem 5
// (5번 작성후 "build/run"을 진행하시오).

/* Fill in _____ to satify the given condtions(주어진 조건을 만족하도록 _____을 채우시오).
6(3). Condtion: data[r][c] = r*10+c
std::vector<std::vector<int>> data(5, std::vector<int>(3));
for(auto_____ : data) {						//
int r = 0;
for(auto_____: x1d) {					//
int c = 0;
x = _____;							//
}
}

7(2). Condition: average = 2.5
std::vector<int> data = {1, 2, 5, 2};
double average = _____;						//	
for(auto x : data)
average _____;							// 

*/
// Please perform "build/run" after completing problem 7
// (7번 작성후 "build/run"을 진행하시오).

// Make your codes as clear, concise, and simple as possible.
// 가능하면 명확하고 간결하고 간단히 작성하라.

// 8(4). Write a function that returns the relative change of two parameters(두 개의 매개변수의 상대 변화를 반환하는 함수를 작성하라).
// Do not use the standard library functions(표준 라이브러리 함수를 사용하지 말 것)
// relative difference of a and b: |x-y|/x
double Fn01(int x, int y) {
	double k;
	if (x > y)
	{
		k = (static_cast<double>(x) - y) / x;
	}
	else
	{
		k = (static_cast<double>(y) - x) / x;
	}
	return k;
}

// 9(15). Write a recursive function that returns the reversed number of an integer parameter(정수형 매개변수를 역순으로 반환하는 recursive 함수를 작성하시오).
// Input(입력): 4321 -> Reversed number(역순): 4321
// Hint: n = n0 * 1 + n1 * 10 + n2 * 100 + n3 *1000 -> ((n3 * 10 + n2) * 10) * 10 + n1
int Fn02(int n) {
	int inverse = 0;
	if (n >= 10)
	{
		while (n >= 10)
		{
			if (n < 10) {
				inverse = n % 10;
					n = n / 10;
			}
			else
			{
				inverse *= 10;
					inverse += n % 10;
					n = n / 10;
			}
		}
		inverse *= 10;
		inverse += n;
	}
	return inverse;
}

// 10(6). Write a function that can modify an argument(passing to Max) value, and the argument value stores the maximum value of data vector
// (인수(Max로 전달)의 값을 data vector에 저장된 가장 큰 값으로 수정하는 함수를 작성하라).
void Fn03(std::vector<int> data, int& Max) {// You can modify the parameter types(파리메터 타입을 수정할 수 있음).
	int maxval = Max;
	for (unsigned int i = 0; i < data.size(); i++)
	{
		if (data[i] > maxval)
			maxval = data[i];
	}
	Max = maxval;
}

// 11(15). Write a function that returns sin(Angle) where Angle is an angle in degree. sin should be calculated by x - x^3/3! + x^5/5! - x^7/7! (x is an angle in radian ranging [0, 2pi]).
// You cannot use the sin function and another user-defined function. 
// (sin(Angle)을 반환하는 함수를 작성하라(Angle은 degree). sin은 x - x^3/3! + x^5/5! - x^7/7!로 계산하며 x는 [0, 2pi] 범위의 radian 각도이다. sin 함수와 다른 사용자 정의 함수를 사용할 수 없다.
double Fn04(double Angle) {
	double rad = Angle / 180 * 3.141592;
	double rad1, rad2, rad3;
	rad1 = rad * rad * rad / 6;
	rad2 = rad1 * rad * rad / (4 * 5);
	rad3 = rad2 * rad * rad / (6 * 7);
	double x = rad - rad1 + rad2 - rad3;
	return x;
}

/* 12(20). Write a function that works as like the below comments and test codes(main).
아래 주석과 같이 동작하는 함수와 테스트 코드(main)를 작성하라.
std::vector<int> v1, v2;
// define v3(v3를 정의)
// v1 and v2 store ten elements that are random values ranging [0, 100]
// (v1과 v2는 [0, 100]의 임의의 수를 10개의 요소로 저장)
v3 = Fn05(v1, v2);
// v3 stores ten elements that are average values of v1 and v2 by element-wise (real value)
// (v3는 v1과 v2의 요소단위의 평균을 10개의 요소에 저장)
*/

std::vector<double> Fn05(std::vector<double> v1, std::vector<double> v2)
{
	std::vector<double> v3(10);
	for (int i = 0; i < 10; i++)
	{
		v3[i] = (v1[i] + v2[i]) / 2;
	}
	return v3;
}

int main() {
	OOP_2021_2_Exam(ExamCode, SourcePath, Department, StudentId, Name);

	srand((unsigned)time(nullptr));

	std::cout << Fn01(2, 5) << std::endl;
	std::cout << Fn02(1222553) << std::endl;

	std::vector<int> data(15);
	for (int i = 0; i < data.size(); i++)
		data[i] = rand() % 1000;

	int Return;
	Fn03(data, Return);
	std::cout << Return << std::endl;

	for (double i = 0; i <= 180.; i += 30.)
		std::cout << Fn04(i) << std::endl;


	// Do not change the codes above in the main function(main 함수에서 위의 내용은 수정하지 마시오).

	// Write test codes for problems 12(12번 문제의 test 코드를 작성)


	// You can optionally use the remaining parts(이후 부분은 자유롭게 사용하세요).

	std::vector<double> v1, v2, v3;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(rand() % 101);
		v2.push_back(rand() % 101);
	}
	v3 = Fn05(v1, v2);


}
