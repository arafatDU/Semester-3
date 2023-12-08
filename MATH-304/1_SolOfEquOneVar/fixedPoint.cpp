#include<bits/stdc++.h>
using namespace std;

#define F(x) ((x)*(x)*(x) + 4*(x)*(x) - 10)
#define g(X) sqrt((10 - (X)*(X)*(X))/4)
#define EPSILON 10e-6
#define N 100

int main()
{
    int i;
    double x0=1.5, x1;

    cout<<"--------------------------------------------------"<<endl;
	cout<<"Iter     x0         x1        g(x0)      f(x1)      "<<endl;
	cout<<"--------------------------------------------------"<<endl;
	for(i = 1; i<N; i++)
    {
		x1 = g(x0);
		printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf \n", i, x0, x1,  g(x0), F(x1));
		if(fabs(F(x1))<EPSILON) {
            cout<<endl<<"Root = "<< x1 <<endl;
            return 0;
		}
		else x0 = x1;
	}

    return 0;
}