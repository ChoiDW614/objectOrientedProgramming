#include <iostream>
#include <vector>

int sum_positive(const std::vector<int>& v);
int GCD(int x, int y);

void printvector(const std::vector<std::vector<int>>& v)
{
	for (unsigned int i = 0; i < v.size(); i++) {
		for (unsigned int j = 0; j < v[i].size(); j++) {
			std::cout << v[i][j] << " ";
		}
		std::cout << std::endl;
	}

}

int main() {
	std::vector<int> v1{10, 3, -6};
	int data = sum_positive(v1);
	std::cout << data << std::endl;

	std::vector<std::vector<int>> collection(3, std::vector<int>(5));
	printvector(collection);

	std::cout << GCD(10, 4) << std::endl;
}

int GCD(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		int k = x % y;
		return GCD(y, k);
	}
}

int sum_positive(const std::vector<int>& v)
{
	int sum = 0;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] >= 0)
			sum += v[i];
	}
	return sum;
}