#include<iostream>
#include<math.h>

#define n 3
using namespace std;


int main()
{
    int i, j;
    double system[n][n+1] = {
    	{4, 1, 1, 8},
    	{2, 5, 2, 3},
    	{1, 2, 4, 11}
    };
    
    //i have to check if this matrix is diagonally dominant or not
    for(i=0;i<n;i++)
    {
        int sum=0;
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                sum+=fabs(system[i][j]);
            }

        }
        if(fabs(system[i][i])<sum)
        {
            cout<<"Not Diagonally Dominant"<<endl;
            return 0;
        }
    }
    double previous_solution[n];
    double new_solution[n];
    for(i=0;i<n;i++)
    {
        previous_solution[i]=0.0;
        new_solution[i]=0.0;
    }
    int flag=0;
    int iteration=0;
    cout<<"iteration"<<" "<<"x\t"<<"y\t"<<"z"<<endl;
    while(n)
    {
        iteration++;
        for(i=0;i<n;i++)
        {
            new_solution[i]=system[i][n];
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    new_solution[i]-=new_solution[j]*system[i][j];
                }
            }
            new_solution[i]=new_solution[i]/system[i][i];
        }
        
        
        
        
        cout<<"   "<<iteration<<"    ";
        for(i=0;i<n;i++)
        {
            printf("%10.6lf     ", new_solution[i]);
             //cout<<new_solution[i]<<"\t";
        }
        cout<<endl;
        
        
        
        
        for(i=0;i<n;i++)
        {
            if(fabs(previous_solution[i]-new_solution[i])>.000001)
            {
                flag=1;
            }
            else 
            {
                flag=0;
            }
        }
        if(flag==0)
        {
            break;
        }
        else 
        {
            for(i=0;i<n;i++)
            {
                previous_solution[i]=new_solution[i];
            }
        }
    }
    cout<<"Iterration="<<iteration<<endl<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"x["<<i<<"] = "<<new_solution[i]<<endl;
    }
   // cout<<iteration;
}