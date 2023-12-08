#include<bits/stdc++.h>
using namespace std;

#define f(x) (x*x + 1)

int main() 
{
	double a, b;
	int n, i;
	printf("Enter the value of a: ");
	scanf("%lf", &a);
	printf("Enter the value of b: ");
	scanf("%lf", &b);
	printf("Enter the value of N: ");
	scanf("%d", &n);

	double h=(b - a)/n;
	double x[n+1], y[n+1];

	x[0] = a;
	for(i=1; i< n; i++)
	{
		x[i] = x[i-1] + h;
	}
	x[n] = b;

	for(i=0; i<n+1; i++)
	{
		y[i] = f(x[i]);
	}

	double Sum_X = y[0] + y[n];
	double Sum_O = 0, Sum_E = 0;
	for(i=1; i<n; i++) 
	{
		if(i % 2 == 0) Sum_E += y[i];
		else Sum_O += y[i];
	}

	double I = (h*(Sum_X + 4*Sum_O + 2*Sum_E))/3;

	printf("\tx\t\tf(x)\n");
	for(i=0; i<n+1; i++)
	{
		printf("%lf\t%lf\t\n", x[i], y[i]);
	}

	printf("Simpson's 1/3 Rule---------\n");
	printf("Integral value = %lf\n--------------------------\n", I);

}