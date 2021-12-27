/*
#include <iostream>
#include <cmath>

void inintializeCp(double C[])
{
	for (int i = 0; i < 24000; i++)
		C[i] = 0;
}

int main()
{
	double t[24000];
	for (int i = 0; i < 24000; i++)
	{
		t[i] = static_cast<double>(i);
	}
	int injectionTime = 0;
	double DG = 3, Ke = 1.6, Ka = 0.4;
	double Cp[24000], sumCp[24000];

	inintializeCp(sumCp);
	inintializeCp(Cp);
	
	for (injectionTime = 0; injectionTime <= 16000; injectionTime + 4000)
	{
		for (int i = injectionTime; i < 24000; i++)
		{
			Cp[i] = (DG * Ka / (Ka - Ke)) * (exp(-Ke * t[i]) - exp(-Ka * t[i]));
			sumCp[i] += Cp[i];
		}
		inintializeCp(Cp);
	}

}
*/