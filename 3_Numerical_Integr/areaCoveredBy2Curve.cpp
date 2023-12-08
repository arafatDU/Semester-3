#include<bits/stdc++.h>

#define n 10000
#define EPSILON 10e-6

#define f(x) sqrt(x)
#define g(x) (x)*(x)
#define h(x) ((f(x)) - (g(x)))

double bisection(double a, double b);

int main(){
	
	double a = 0.0, b,x1 = 0.25, x2 = 1.25, h, Sum_X, Sum_O, Sum_E;
	double x[n+1], y[n+1];
	int i;
	
	b = bisection(x1, x2);
	
	h = (b - a) / n;
		
	x[0] = a;
	
	for(i = 1; i < n; ++i){
		x[i] = x[i-1] + h;
	}
	
	x[n] = b;
	
	for(i = 0; i < n+1; ++i){
		y[i] = h(x[i]);
	}
	
	Sum_X = (y[0] + y[n]);
	
	for(i = 1; i < n; i++){
		if(i % 2 == 0) Sum_E += y[i];
		else Sum_O += y[i];
	}
	
	double I = h*(Sum_X + 4*Sum_O + 2*Sum_E)/3;
	
	printf("Simpson's 1/3 Rule- - - - - - - - - - - \n");
	printf("Integral Value = %lf\n", I);
	printf("- - - - - - - - - - - - - - - - - - - -  \n");
		
	return 0;
}

double bisection(double a, double b){
	double c;
	if(h(a)*h(b) > 0) exit(0);
	for(int i = 1; i<n; i++){
		c = (a+b)/2;
		if(fabs(h(c))<EPSILON) {
			return c;
		}
		if(h(a)*h(c)<0) b = c;
		else a = c;
	}
}
