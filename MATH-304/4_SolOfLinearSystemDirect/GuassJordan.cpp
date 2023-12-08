#include<bits/stdc++.h>
using namespace std;

#define NMAX 3
#define EPS 10e-6

int main()
{	
	int i, j, k, ip, jp;
	double mij, temp, determinant=1;
	double x[NMAX][NMAX +1] = { {4, 1, 1, 8}, {2, 5, 2, 3}, {1, 2, 4, 11} };
	
	for(i = 0; i<NMAX; i++)
	{
		for(j= 0; j< NMAX+1; j++)
		{
			if(j==0 || j == 4) printf(" | ");
			printf("%7.2lf ", x[i][j]);
		}
		printf("|\n");
	}
	
	
	// Lower triangle --> 0 
	for(i=0; i<NMAX-1; i++)
	{
		for(j=i+1; j< NMAX; j++)
		{
			mij = x[j][i]/x[i][i];
			for(k=i; k<NMAX+1; k++)
			{
				x[j][k] = x[j][k] - mij*x[i][k];
			}
		}
			
		printf("Round= %d\n", i+1);
		for(ip=0; ip<NMAX; ip++)
		{
			for(jp=0; jp<NMAX +1; jp++)
			{
				if(jp==0 || jp == NMAX) printf(" | ");
				printf("%7.2lf ", x[ip][jp]);	
			}
			printf("|\n");
		}
	}
	
	
	
	// calculate determinant
	for(i = 0; i<NMAX; i++)
		for(j = 0; j<NMAX; j++)
			if(i == j) determinant *= x[i][j];
			
	printf("\nDeterminent = %.2lf\n\n", determinant);
	
	
	
	//Upper Triangle --> 0
	for(i = NMAX-1; i>0; i--)
	{
		for(j = i-1; j>=0; j--)
		{
			mij = x[j][i]/x[i][i];
			for(k = 0; k<NMAX+1; k++)
			{
				x[j][k] = x[j][k] - mij*x[i][k];
			}
		}
		printf("Round= %d\n", NMAX - i);
		for(ip=0; ip<NMAX; ip++)
		{
			for(jp=0; jp<NMAX +1; jp++)
			{
				if(jp==0 || jp == NMAX) printf(" | ");
				printf("%7.2lf ", x[ip][jp]);	
			}
			printf("|\n");
		}
			
		
	}	
	
	
	
	printf("\n-----------------------------\n");
	printf("-----------------------------\n");
	
	
	
		
	
	return 0;
}