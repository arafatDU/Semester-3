#include<bits/stdc++.h>
using namespace std;

#define n 10
#define f(x) (x*x + 1)

int main() 
{
	int i;
	double x[n+1] = {0.0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0};
	double y[n+1], h;

	for(i=0; i<n+1; i++)	y[i] = f(x[i]);
	h = (x[0] + x[n])/n;
	
	double Sum_X = y[0] + y[n];
	double Sum_O = 0, Sum_E = 0;
	for(i=1; i<n; i++) 
	{
		if(i % 2 == 0) Sum_E += y[i];
		else Sum_O += y[i];
	}

	double I = (h*(Sum_X + 4*Sum_O + 2*Sum_E))/3;

	printf("\"x\",\"f(x)\"\n");
	for(i=0; i<n+1; i++)
	{
		printf("%lf,%lf\n", x[i], y[i]);
	}

	printf("\nSimpson's 1/3 Rule---------\n");
	printf("Integral value = %lf\n--------------------------\n", I);

}