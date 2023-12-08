#include<bits/stdc++.h>
using namespace std;

#define EPS 1e-6
#define n 3

double A[n][n]={{4,-1,0},
                {-1,4,-1},
                {0,-1,4}};
double X_old[n]={1,0,0},X_new[n];
double lambda_old=1,lambda_new;
int iter=0;

void power_iteration();
double get_max();

int main(){
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
    printf("Iter    |   ( X_1          X_2            X_3 )^T  \t|  lambda_old\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
    printf("%2d\t|  %7lf\t%7lf\t%7lf\t|\n",iter++,X_old[0],X_old[1],X_old[2]);
    power_iteration();
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
    printf("Approximate eigenvalue = %lf\n",lambda_old);
    printf("Corresponding eigenvectors = ( %lf",X_old[0]);
    for(int i=1;i<n;i++){
        printf(", %lf",X_old[i]);
    }
    printf(" )^T\n");
    return 0;
}

void power_iteration(){
    int i,j,k;
    memset(X_new,0,sizeof(X_new));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            X_new[i]+=A[i][j]*X_old[j];
        }
    }
    lambda_new=get_max();
    for(i=0;i<n;i++){
        X_new[i]/=lambda_new;
        X_old[i]=X_new[i];
    }
    printf("%2d\t|  %7lf\t%7lf\t%7lf\t|  %lf\n",iter++,X_new[0],X_new[1],X_new[2],lambda_new);
    if(fabs(lambda_new-lambda_old)<EPS){
        return;
    }
    lambda_old=lambda_new;
    power_iteration();
}

double get_max(){
    double max=-__INT_MAX__+1.0;
    for(int i=0;i<n;i++){
        if(fabs(X_new[i])>max){
            max=fabs(X_new[i]);
        }
    }
    return max;
}