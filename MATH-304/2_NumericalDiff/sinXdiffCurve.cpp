#include<bits/stdc++.h>
using namespace std;

#define f(x) sin(x)
#define PI 3.14159

int main()
{
	double a=0.0, b=2*PI, h;
	int n=100;
	//printf("Enter interval: ");
	//scanf("%lf%lf", &a, &b);
	//printf("Enter number of interval: ");
	//scanf("%d", &n);

	h = (b - a)/n;
	double x[n+1];
	x[0] = a;
	for(int i=1; i<= n-1; i++)
	{
		x[i] = a + h;
		a = x[i];	
	}
	x[n] = b;

	//for(int i=0; i<n+1; i++) printf("%lf  ",x[i]);
	//printf("\n");

	double y[n+1];
	for(int i=0; i<n+1; i++)
	{
		y[i] = f(x[i]);
	}
	
	//for(int i=0; i<n+1; i++) printf("%lf  ", y[i]);
	//printf("\n");

	
	double f[n+1];
	f[0] = (y[1] - y[0])/(x[1] - x[0]);
	for(int i=1; i<= n-1; i++)
	{
		f[i] = (y[i+1] - y[i-1])/(x[i+1] -x[i-1]);
	}
	f[n] = (y[n] - y[n-1])/(x[n] - x[n-1]);

	
	printf("\"x\",\"y\",\"y'\"\n");	
	for(int i=0; i<n+1; i++)
	{
		printf("%lf,%lf,%lf\n", x[i], y[i], f[i]);
	}
	
	
	return 0;
	
}