#include<bits/stdc++.h>
using namespace std;

#define F(x) ((x)*(x)*(x) + 4*(x)*(x) - 10)
#define EPSILON 10e-6
#define N 100

int main()
{
    int i;
    double a=1.25, b=1.5, c;

    if(F(a)*F(b)>0){
        cout<<"No root exist!"<<endl;
        return 0;
    }
    cout<<"---------------------------------------------------------------------"<<endl;
	cout<<"Iter     a         b          c        f(a)        f(b)        f(c)"<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	for(i = 1; i<N; i++)
    {
		c = (a+b)/2;
		printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", i, a, b, c, F(a), F(b), F(c));
		if(fabs(F(c))<EPSILON) {
            cout<<endl<<"Root = "<< c <<endl;
            return 0;
		}
		if(F(a)*F(c)<0) b = c;
		else a = c;
	}

    return 0;
}