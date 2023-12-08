#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a, i<b; i++)
#define ff first
#define ss second


int main()
{
    freopen("g_representation.txt", "r", stdin);

    int n, m;       // n = number of vertex, m = no of edge
    cin>>n>>m;

    vvi adjm(n+1, vi(n+1,0));

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adjm[u][v] = 1;
        adjm[v][u] = 1;
    }

    // display
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<n+1; j++)
            cout<<adjm[i][j]<<"  ";
        cout<<endl;
    }

    if(adjm[3][7]){
        cout<<"There is a edge 3 to 7"<<endl;
    }else{
        cout<<"No edge"<<endl;
    }
    cout<<endl<<endl;


    // Adj list
    cin>>n>>m;
    vi adjList[n+1];

    for(int i=1; i<n+1; i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout<<"Adj List of the given graph: "<<endl;
    for(int i=1; i<n+1; i++){
        cout<<i<<" --> ";
        for(auto x: adjList[i])
            cout<<x<<" ";
        cout<<endl;
    }




    return 0;
}