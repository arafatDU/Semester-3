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
	double Sum_I = 0;
	
	for(i=1; i<n; i++) 
	{
		Sum_I += y[i];
	}

	double I = (h*(Sum_X + 2*Sum_I))/2;

	printf("\"x\",\"f(x)\"\n");
	for(i=0; i<n+1; i++)
	{
		printf("%lf,%lf\n", x[i], y[i]);
	}

	printf("\nTrapexoidal Rule---------\n");
	printf("Integral value = %lf\n--------------------------\n", I);

}