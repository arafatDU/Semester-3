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


int main()
{
    freopen("in_bfs.txt", "r", stdin);

    int num_vertex, num_edges, cnt=0;
    cin>>num_vertex>>num_edges;

    vvi adjList(num_vertex+1);
    vi indeg(num_vertex+1, 0);


    for(int i=0; i<num_edges; i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        indeg[v]++;
    }
    cout<<"Adj List of the given graph: "<<endl;
    for(int i=1; i<num_vertex+1; i++){
        cout<<i<<" --> ";
        for(auto x: adjList[i])
            cout<<x<<" ";
        cout<<endl;
    }

    queue<int> pq;
    for(int i=1; i<=num_vertex; i++)
    {
        if(indeg[i] == 0) pq.push(i);
    }

    while(!pq.empty())
    {
        cnt++;
        int node = pq.front();
        cout<<node<<" ";
        pq.pop();

        for(int x: adjList[node]){
            indeg[x]--;
            if(indeg[x] == 0){
                pq.push(x);
            }
        }
    }

    cout<<endl;
    return 0;
}