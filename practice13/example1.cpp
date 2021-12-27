/*
#include <iostream>
#include <vector>
#include <string>

template <class T>
bool is_ascending(std::vector<T>& v)
{
	unsigned int i = 0;
	for (; i < (v.size()-1); i++)
	{
		if (v[i] > v[i + 1])
			break;
	}
	if (i == v.size() - 1)
		return true;
	else
		return false;
}

int main()
{
	std::vector<int> v1 = { 1, 3 ,5 ,7 ,9 };
	std::vector<int> v2 = { 1, 5 ,3 ,7 ,9 };
	std::vector<double> v3 = { 1.57, 3.17736 ,5.173 ,7.187, 9.487 };
	std::vector<char> v4 = {10, 'B', 'E' ,'a' ,'t'};
	std::vector<std::string> v5 = { "ac", "aed" ,"ewsd" ,"q" };

	std::cout << std::boolalpha;
	std::cout << is_ascending(v1) << std::endl;
	std::cout << is_ascending(v2) << std::endl;
	std::cout << is_ascending(v3) << std::endl;
	std::cout << is_ascending(v4) << std::endl;
	std::cout << is_ascending(v5) << std::endl;
}
*/