#include<bits/stdc++.h>

using namespace std;
int numOfItems, weight[100], capacity=10;
float benefit[100], value[100];


void readInput()
{
    weight[0] = 0;
    benefit[0] = 0;
    value[0] = 0;

    cin>>numOfItems;
    cout<<numOfItems<<endl;
    for(int i=1; i<=numOfItems; i++)
    {
        cin>>weight[i];
        cin>>benefit[i];
        value[i] = (benefit[i]/weight[i]);
    }

    cout<<"Items: ";
    for(int i=1; i<=numOfItems; i++)
        cout<<i<<"  ";
    cout<<endl;
    cout<<"Weight: ";
    for(int i=1; i<=numOfItems; i++)
        cout<<weight[i]<<"  ";
    cout<<endl;
    cout<<"Benefit: ";
    for(int i=1; i<=numOfItems; i++)
        cout<<benefit[i]<<"  ";
    cout<<endl;
    cout<<"Value: ";
    for(int i=1; i<=numOfItems; i++)
        cout<<value[i]<<"  ";
    cout<<endl;
}

void sortByValue()
{
    for(int i=1; i<=numOfItems; i++)
    {
        for(int j=i+1; j<=numOfItems; j++)
        {
            if(value[i]<value[j])
            {
                int temp1 = value[i];
                int temp2 = weight[i];
                int temp3 = benefit[i];
                value[i] = value[j];
                weight[i] = weight[j];
                benefit[i] = benefit[j];
                value[j] = temp1;
                weight[j] = temp2;
                benefit[j] = temp3;
            }
        }
    }


    cout<<endl;
    cout<<"Weight: ";
    for(int i=1; i<=numOfItems; i++)
        cout<<weight[i]<<"  ";
    cout<<endl;
    cout<<"Benefit: ";
    for(int i=1; i<=numOfItems; i++)
        cout<<benefit[i]<<"  ";
    cout<<endl;
    cout<<"Value: ";
    for(int i=1; i<=numOfItems; i++)
        cout<<value[i]<<"  ";
    cout<<endl;

}



void iterative()
{
    int i, count=0;
    float profit=0;
    for(i=1; i<numOfItems; i++)
    {
        count += weight[i];
        if(count<capacity)
        {
            profit += benefit[i];
            cout<<weight[i]<<" ml of "<<i<<"  - "<<benefit[i]<<endl;
        }else{
            break;
        }
        
    }
    count -= weight[i];
    float rest = capacity - count;

    cout<<rest<<" ml of "<<i<<"  - "<<rest*value[i]<<endl;
    profit += rest*value[i];
    cout<<endl<<"Profit: "<<profit<<endl;
    
}

int main()
{
    freopen("fractional_knapsack.txt", "r", stdin);
    readInput();

    sortByValue();

    iterative();

    return 0;
}