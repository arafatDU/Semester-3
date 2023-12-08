#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a, i<b; i++)
#define ff first
#define ss second
#define INF 1e9
#define N 100



int main()
{
    freopen("in_dijkstra.txt", "r", stdin);
    int num_vertex, num_edges;
    cin>>num_vertex>>num_edges;

    vector<int> dist(num_vertex+1, INF);
    vector<vector<pair<int,int>>> graph(num_vertex+1);

    for(int i=0; i<num_edges; i++)
    {
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    } 
    int src; cin>>src;
    dist[src] = 0;
    set<pair<int,int>> s;
    // {wt, vertex}
    s.insert({0, src});
    while(!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for(auto i: graph[x.second]){
            if(dist[i.first] > dist[x.second] + i.second){
                s.erase({dist[i.first], i.first});
                dist[i.first] = dist[x.second] + i.second;
                s.insert({dist[i.first], i.first});
            }
        }
    }
    for(int i=1; i<num_vertex+1; i++){
        if(dist[i]<INF){
            cout<<dist[i]<<" ";
        }else{
            cout<<-1<<" ";
        }
    }

    cout<<endl;

}