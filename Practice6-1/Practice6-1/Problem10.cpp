/*
#include <iostream>
using namespace std;

int cal_permutation(int n, int r)
{
	int sym = 1;
	if (r > n)
	{
		int temp = n;
		n = r;
		r = temp;
	}

	if (n == r)
		return sym;
	else
	{
		for (int i = 0; i < r ; i++)
		{
			sym *= (n-i);
		}
	}
	return sym;
}

int main()
{
	int N, R;
	cin >> N >> R;
	cout << cal_permutation(N, R) << endl;
	return 0;
}
*/