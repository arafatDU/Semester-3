#include<bits/stdc++.h>
using namespace std;

#define F(x) ((x)*(x) - 3*(x) + 2)
#define F1(x) (2*(x) - 3)
//#define F(x) ((x)*(x)*(x) + 4*(x)*(x) - 10)
//#define F1(x) (3*(x)*(x) + 8*(x))
#define EPSILON 10e-6
#define N 100

int main()
{
    int i;
    double x0=0, x1;

    cout<<"----------------------------------------------------------"<<endl;
	cout<<"Iter     x0         x1        f(x0)      f'(x0)     f(x1)    "<<endl;
	cout<<"----------------------------------------------------------"<<endl;
	for(i = 1; i<N; i++)
    {
		x1 = x0 - (F(x0)/F1(x0));
		printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", i, x0, x1,  F(x0), F1(x0), F(x1));
		if(fabs(F(x1))<EPSILON) {
            cout<<endl<<"Root = "<< x1 <<endl;
            return 0;
		}
		else x0 = x1;
	}

    return 0;
}