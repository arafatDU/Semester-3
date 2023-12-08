#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a, i<b; i++)
#define ff first
#define ss second


int main()
{
    freopen("opti_pattern.txt", "r", stdin);

    int n;   // given n size of array that storing file computation cost
    cin>>n;

    vector<int> a(n);

    for(int i=0; i<n; i++)
        cin>>a[i];

    priority_queue<int, vector<int>, greater<int> > minheap;

    for(int i=0; i<n; i++)
        minheap.push(a[i]);

    int min_cost = 0; 

    while(minheap.size() > 1){
        int e1 = minheap.top();
        minheap.pop();
        int e2 = minheap.top();
        minheap.pop();

        min_cost += (e1 + e2);
        minheap.push(e1 + e2);
    }

    cout<<"Minimum cost: "<<min_cost<<endl;



    return 0;
}