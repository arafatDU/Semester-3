#include<bits/stdc++.h>
using namespace std;

#define F(x) ((x)*(x)*(x) + 4*(x)*(x) - 10)
#define EPSILON 10e-6
#define N 100

int main()
{
    int i;
    double x0=1.5, x1=2.0, x2;

    cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"Iter     x0         x1          x2       f(x0)       f(x1)       f(x2)"<<endl;
	cout<<"-------------------------------------------------------------------------"<<endl;
	for(i = 1; i<N; i++)
    {
		x2 = ( x0*F(x1) - x1*F(x0) )/( F(x1) - F(x0) );
		printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", i, x0, x1, x2, F(x0), F(x1), F(x2));
		if(fabs(F(x2))<EPSILON) {
            cout<<endl<<"Root = "<< x2 <<endl;
            return 0;
		}
		else{
            x0 = x1;
            x1 = x2;
        }
	}

    return 0;
}