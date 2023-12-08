#include<bits/stdc++.h>
using namespace std;

#define f(x) ((x)*(x) + 1)

int main()
{
    int n=10, i;
    double a=0.0, b=2.0, h;
    double x[n+1], y[n+1], yy[n+1];

    h = (b - a)/n;
    // input
    x[0] = a;
    for(i = 1; i<n; i++)
    {
        x[i] = a + h;
        a = x[i];
    }
    x[n] = b;


    for(i = 0; i<n+1; i++) y[i] = f(x[i]);
    for(i = 1; i<n+1; i++) yy[i] = (y[i] - y[i-1])/h;

    cout<<"--------------------------------------------------"<<endl;
	cout<<"Iter     x[i]      f(x[i])     f'(x[i])      "<<endl;
	cout<<"--------------------------------------------------"<<endl;

    for(i = 0; i<n+1; i++)
    {
        if(i == 0){
            printf("%3d %10.6lf %10.6lf  ", i, x[i], y[i]);
            cout<<"    -----"<<endl;
            continue;
        }
        printf("%3d %10.6lf %10.6lf  %10.6lf\n", i, x[i], y[i],  yy[i]);  
    }

    cout<<"--------------------------------------------------"<<endl;

    return 0;
}