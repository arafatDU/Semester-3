#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a, i<b; i++)
#define ff first
#define ss second
#define MAX 1000000

bool isCycle(int src, vvi &adj, vector<bool> &visited, int parent)
{
    visited[src] = true;
    for(auto x: adj[src])
    {
        if(x != parent){
            if(visited[x]) return true;
            if(!visited[x] && isCycle(x, adj, visited, src)) return true;
        }
    }

    return false;
}



int main()
{
    freopen("cycle.txt", "r", stdin);

    int num_vertex, num_edges, cnt=0;
    cin>>num_vertex>>num_edges;

    vvi adjList(num_vertex+1);
    vector<bool> visited(num_vertex+1, false);


    for(int i=0; i<num_edges; i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    cout<<"Adj List of the given graph: "<<endl;
    for(int i=1; i<num_vertex+1; i++){
        cout<<i<<" --> ";
        for(auto x: adjList[i])
            cout<<x<<" ";
        cout<<endl;
    }

    bool cycle = false;

    for(int i=0; i<num_vertex+1; i++){
        if(!visited[i] && isCycle(i, adjList, visited, -1)){
            cycle = true;
        }
    }

    if(cycle){
        cout<<"Cycle is present"<<endl;
    }else{
        cout<<"Cycle is not present"<<endl;
    }



    cout<<endl;
    return 0;
}