/*
#include <iostream>
#include <vector>

class Base {
protected:
	std::vector<double> data;
public:
	Base() {}
	Base(int B) : data(B) {}

	virtual void print() const {
		std::cout << data.size() << std::endl;
	}

	virtual void printData() const {
		for (unsigned int i = 0; i < data.size(); i++){
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}

	virtual void setN(int idx, double N) {
		if (data.size() > idx)
			data[idx] = N;
	}
};

class Derived : public Base{
public:
	Derived(int D) : Base(D) {}

	void insert(double N) {
		data.push_back(N);
	}
};

int main()
{
	Base b1(2), b2(10);

	b1.print();		// 2
	b2.print();		// 10
	for (int i = 0; i < 5; i++) {
		b1.setN(i, (i + 1) * 20);
		b2.setN(i, (i + 1) * 10);
	}
	b1.printData();  // 20 40
	b2.printData();  // 10 20 30 40 50 0 0 0 0 0
	
	Derived d(5);
	d.print();		// 5
	d.printData();		// 0 0 0 0 0
	for (int i = 0; i < 10; i++) {
		d.setN(i, (i + 1) * 3);
	}
	d.printData();	// 3 6 9 12 15
	d.insert(99);	// "Base" class does not have "insert" method.
	d.printData();	// 3 6 9 12 15 99
}
*/