#include<bits/stdc++.h>

using namespace std;

int n, start[100], finish[100], compatibility[100];


void readInput()
{
    start[0] = 0;
    finish[0] = 0;
    compatibility[0] = 0;

    cin>>n;
    for(int i = 1; i<=n; i++)
    {
        cin>>start[i];
        cin>>finish[i];
        compatibility[i] = 1;
    }

    cout<<endl<<"Given table:"<<endl;
    for(int i=1; i<=n; i++ )
        cout<<start[i]<<"  ";
    cout<<endl;
    for(int i=1; i<=n; i++ )
        cout<<finish[i]<<"  ";


}

void sortByFinishedTime()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(finish[i]>finish[j])
            {
                int temp1 = finish[i];
                int temp2 = start[i];
                finish[i] = finish[j];
                start[i] = start[j];
                finish[j] = temp1;
                start[j] = temp2;
            }
        }
    }

    cout<<endl<<"Sorted table:"<<endl;
    for(int i=1; i<=n; i++ )
        cout<<start[i]<<"  ";
    cout<<endl;
    for(int i=1; i<=n; i++ )
        cout<<finish[i]<<"  ";

}


void iterative()
{
    for(int i=1; i<=n; i++)
    {
        if(compatibility[i] !=0)
        {
            for(int j = i+1; j<=n; j++)
            {
                if(start[j]<finish[i])
                    compatibility[j] = 0;
            }
        }
    }
}


void recursiveSelector(int i){
    int m = i + 1;
    while (m <= n && start[m]<finish[i]){
        compatibility[m] = 0;
        m++;
    }
    if(m <= n){
        recursiveSelector(m);
    } else return ;
}


int main()
{
    freopen("input.txt", "r", stdin);
    readInput();

    sortByFinishedTime();

    //iterative();
    recursiveSelector(0);

    cout<<endl;
    for(int i=1; i<=n; i++)
    {
        if(compatibility[i] == 1)
            cout<<start[i]<< "  "<<finish[i]<<endl;
    }

    return 0;
}