#include<bits/stdc++.h>
using namespace std;

#define NMAX 3
#define EPS 1e-6

int main(){
    double pivot,mp,determinant=0;
    int p;

    double matrix[NMAX][NMAX+NMAX]={
        {2,-1,-1,1,0,0},
        {1,2,1,0,1,0},
        {1,-1,2,0,0,1}
    };

    //print to see
    for( int i=0;i<NMAX;i++){
        for(int j=0;j<NMAX+NMAX;j++){
            printf("%0.1lf\t",matrix[i][j]);
        }printf("\n");
    }

    printf("After\n");

    for(int i=0;i<NMAX-1;i++){
        pivot=matrix[i][i];
        if(fabs(pivot)<EPS){
            for(p=i+1;p<NMAX;p++){
                if(matrix[p][i]!=0.0) break;
            }
            for(int a=0;a<NMAX+1;a++){//swap
                int temp=matrix[i][a];
                matrix[i][a]=matrix[p][a];
                matrix[p][a]=temp;
            }
        }
        for(int j=i+1;j<NMAX;j++){
            pivot=matrix[i][i];
            mp=matrix[j][i]/pivot;
            for(int k=0;k<NMAX+NMAX;k++){
                matrix[j][k]-=mp*matrix[i][k];
            }
        }
    }

    //print again
     for(int i=0;i<NMAX;i++){
        for(int j=0;j<NMAX+NMAX;j++){
            printf("%0.1lf\t",matrix[i][j]);
        }printf("\n");
    }
    printf("\n");

    for(int i=0;i<NMAX;i++){
        determinant+=matrix[i][i];
    }

    printf("determinant: %f\n",determinant);

    if(fabs(determinant)<EPS){
        printf("Inverse doesn't exist\n");
        exit(1);
    }


   
    printf("\n");

// Need some modify as just Lower Triangle is 0


    // for(int i=0;i<NMAX;i++){
    //     double diagonal=matrix[i][i];
    //     for(int k=0;k<NMAX+NMAX;k++){
    //         matrix[i][k]/=diagonal;
    //     }
    // }
    printf("\nInverse matrix:\n");
    printf("\nDone till Lower triangle 0, Now calculate inverse easy.\n");
    // for(int i=0;i<NMAX;i++){
    //     for (int j=NMAX;j<2*NMAX;j++){
    //         printf("%0.4lf\t\t",matrix[i][j]);
    //     }printf("\n");
    // }

    printf("\n");


}