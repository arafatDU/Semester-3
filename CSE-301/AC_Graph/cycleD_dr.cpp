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

bool isCycle(int src, vvi &adj, vector<bool> &visited, vector<bool> &stack)
{
    stack[src] = true;
    if(!visited[src]){
        visited[src] = true;
        for(auto x: adj[src]){
            if(!visited[x] and isCycle(x, adj, visited, stack)) return true;
            if(stack[x]) return true;
        }
    }
    stack[src] = false;    

    return false;
}



int main()
{
    freopen("cycle.txt", "r", stdin);

    int num_vertex, num_edges, cnt=0;
    cin>>num_vertex>>num_edges;

    vvi adjList(num_vertex+1);
    vector<bool> visited(num_vertex+1, false);
    vector<bool> stack(num_vertex+1, 0);


    for(int i=0; i<num_edges; i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
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
        if(!visited[i] && isCycle(i, adjList, visited, stack)){
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