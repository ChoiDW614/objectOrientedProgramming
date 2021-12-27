#include <iostream>
#include <vector>
#include <string>

class BigUnsigned
{
private:
	std::vector<int> bigNumber;

public:
	BigUnsigned() : bigNumber(1) {}

	BigUnsigned(unsigned char c) {
		bigNumber.push_back(c - '0');
	}

	BigUnsigned(std::string s) {
		for (unsigned int i = 0; i < s.size(); i++)
		{
			bigNumber.push_back(stoi(s.substr(i, 1)));
		}
	}

	BigUnsigned operator+(const BigUnsigned& B)
	{
		int result1 = 0;
		for (unsigned int i = 0; i < bigNumber.size() && i < B.bigNumber.size(); i++)
		{
			result1 *= 10;
			result1 += bigNumber[i] + B.bigNumber[i];
		}
		if (bigNumber.size() > B.bigNumber.size())
		{
			for (unsigned int i = B.bigNumber.size(); i < bigNumber.size(); i++)
			{
				result1 *= 10;
				result1 += bigNumber[i];
			}
		}
		if (bigNumber.size() < B.bigNumber.size())
		{
			for (unsigned int i = bigNumber.size(); i < B.bigNumber.size(); i++)
			{
				result1 *= 10;
				result1 += B.bigNumber[i];
			}
		}
		std::string result = std::to_string(result1);
		return BigUnsigned(result);
	}

	std::vector<int> getVector() const {
		return bigNumber;
	}
};

std::ostream& operator<<(std::ostream& os, const BigUnsigned& B)
{
	for (unsigned int i = 0; i < B.getVector().size(); i++) {
		os << B.getVector()[i];
	}
	return os;
}

int main()
{
	BigUnsigned num1;
	std::cout << num1 << std::endl;

	BigUnsigned num2('2');
	std::cout << num2 << std::endl;

	BigUnsigned num3("38238");
	std::cout << num3 << std::endl;

	BigUnsigned num4("75342");
	BigUnsigned num5 = num3 + num4;
	std::cout << num5 << std::endl;

	return 0;
}