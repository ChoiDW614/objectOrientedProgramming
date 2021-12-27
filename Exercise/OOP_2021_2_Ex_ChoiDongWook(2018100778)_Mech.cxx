/*             Object-Oriented Programming, Midterm exam (2021-2)                       */
// Write your answers in Korean or English(����� �ѱ��� �Ǵ� ����� �ۼ��Ͻÿ�). 
#include <iostream> 
#include <string> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <vector> 

static std::string Department = "Mech";           // �а�(�ѱ�/���� ����, �߱��� ����) 
static std::string StudentId = "2018100778";     // �й�(���ڷ� ������ ���ڿ�) 
static std::string Name = "ChoiDongWook";        // �̸�(�ѱ�/���� ����, �߱��� ����)
static std::string ExamCode = "exercise";        // ���踶�� �ٸ� �ڵ� ����, test������ ��exercise���� ����
// ��exercise�� �� ����ð��� ������ �ڵ尡 �ƴϸ� ���� �Ұ� 

void OOP_2021_2_Exam(std::string ExamCode, std::string SourcePath, std::string Department, std::string StudentId, std::string Name);
static std::string SourcePath = __FILE__;

// ��� �ڵ� �ۼ�, ��ó��(preprocessors), ���� ����(global variables), �Լ�(functions), Ŭ���� (classes), ��

// Notation: 
// 1. a^b denotes a raised the power b(a^b�� a�� b����)
// 2. [a, b] denotes the range from a to b, and a and b are inclusive
//    ([a, b]�� a���� b������ �����̸�, a�� b�� �����Ѵ�)

/*
1(10). Trace the evaluation of the following expressions, and write their resulting values and corresponding variables
(�Ʒ� ������ �� ����(��� �� �� ������ ������ ����)�� �����϶�).
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
int &r = x;		// x �� ��Ī���� r�� �Ҵ�
int &rr = r;	// r �� reference�� rr�� �Ҵ�
rr = 2;			// rr = 2 -> r= 2 -> x =2
int xx = x;		// xx = x -> xx = 2
int xxx = r;	// xxx = r -> xxx = x -> xxx = 2
*/
// Please perform "build/run" after completing problem 1
// (1�� �ۼ��� "build/run"�� �����Ͻÿ�).


/*
2(10). Explain any errors in the following program
(�Ʒ� ���α׷��� ������ ������ �����϶�).
a)
int F(int x, y) { return x+y; }			// parameter y�� �ڷ����� �����Ǿ� ���� �ʴ�.
b)
std::cout << sqrt(2., 1.) << std::endl;	//	sqrt�Լ��� parameter�� ������ 1���̴�.
c)
std::vector x(10, 3);					//	vector�� �ڷ����� ���������� �ʾҴ�.
d)
for(int x = 0 ; x < 10 ; x++ );			// for���ڿ� �����ݷ��� �־� emptystate�� 10�� �����ѵڿ�
std::cout << x << std::endl;		//		x�� �ѹ� ����Ѵ�.
e)
void F(int x1 = 0, int x2 = 0, int x3) {}	//	����Ʈ ���� ������ ���� �ڿ������� ������ �־�� �Ѵ�.

*/
// Please perform "build/run" after completing problem 2
// (2�� �ۼ��� "build/run"�� �����Ͻÿ�).

/*
* Explain how the following code fragment works(the final values of variables and process)
(�Ʒ� �ڵ��� ������ �����϶�(������ ����Ǵ� ���� ó�� ����)).
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
// (5�� �ۼ��� "build/run"�� �����Ͻÿ�).

/* Fill in _____ to satify the given condtions(�־��� ������ �����ϵ��� _____�� ä��ÿ�).
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
// (7�� �ۼ��� "build/run"�� �����Ͻÿ�).

// Make your codes as clear, concise, and simple as possible.
// �����ϸ� ��Ȯ�ϰ� �����ϰ� ������ �ۼ��϶�.

// 8(4). Write a function that returns the relative change of two parameters(�� ���� �Ű������� ��� ��ȭ�� ��ȯ�ϴ� �Լ��� �ۼ��϶�).
// Do not use the standard library functions(ǥ�� ���̺귯�� �Լ��� ������� �� ��)
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

// 9(15). Write a recursive function that returns the reversed number of an integer parameter(������ �Ű������� �������� ��ȯ�ϴ� recursive �Լ��� �ۼ��Ͻÿ�).
// Input(�Է�): 4321 -> Reversed number(����): 4321
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
// (�μ�(Max�� ����)�� ���� data vector�� ����� ���� ū ������ �����ϴ� �Լ��� �ۼ��϶�).
void Fn03(std::vector<int> data, int& Max) {// You can modify the parameter types(�ĸ����� Ÿ���� ������ �� ����).
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
// (sin(Angle)�� ��ȯ�ϴ� �Լ��� �ۼ��϶�(Angle�� degree). sin�� x - x^3/3! + x^5/5! - x^7/7!�� ����ϸ� x�� [0, 2pi] ������ radian �����̴�. sin �Լ��� �ٸ� ����� ���� �Լ��� ����� �� ����.
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
�Ʒ� �ּ��� ���� �����ϴ� �Լ��� �׽�Ʈ �ڵ�(main)�� �ۼ��϶�.
std::vector<int> v1, v2;
// define v3(v3�� ����)
// v1 and v2 store ten elements that are random values ranging [0, 100]
// (v1�� v2�� [0, 100]�� ������ ���� 10���� ��ҷ� ����)
v3 = Fn05(v1, v2);
// v3 stores ten elements that are average values of v1 and v2 by element-wise (real value)
// (v3�� v1�� v2�� ��Ҵ����� ����� 10���� ��ҿ� ����)
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


	// Do not change the codes above in the main function(main �Լ����� ���� ������ �������� ���ÿ�).

	// Write test codes for problems 12(12�� ������ test �ڵ带 �ۼ�)


	// You can optionally use the remaining parts(���� �κ��� �����Ӱ� ����ϼ���).

	std::vector<double> v1, v2, v3;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(rand() % 101);
		v2.push_back(rand() % 101);
	}
	v3 = Fn05(v1, v2);


}
