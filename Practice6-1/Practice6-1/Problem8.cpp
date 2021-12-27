/*
#include <iostream>
#include <cmath>
using namespace std;

void cal_mean()
{
	double aver = 0, geo_mean = 1, har_mean = 0;
	double input, cnt = 0;
	cin >> input;
	while (!cin.eof())
	{
		aver += input;
		geo_mean *= input;
		har_mean += (1 / input);
		cin >> input;
		cnt++;
	}
	aver = aver / cnt;
	geo_mean = pow(geo_mean, (1 / cnt));
	har_mean = cnt / har_mean;

	cout << "average = " << aver << endl;
	cout << "geometric mean = " << geo_mean << endl;
	cout << "harmonic mean = " << har_mean << endl;
}

int main()
{
	cal_mean();
	return 0;
}
*/