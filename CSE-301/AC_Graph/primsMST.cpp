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


// graph
vector<int> graph[N];
int costMST=0;
vector<int> dist[N], parent[N];
vector<bool> visited[N];


void primsMST(int src)
{
    for(int i=0; i<N; i++)
        dist[i].push_back(INF);

    set<vector<int>> s;
    dist[src].push_back(0);
    s.insert({0, src});

    while(!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        visited[x[1]].push_back(true);

        int u = x[1];
        //int v = parent[x[1]];
        int w = x[0];
        cout<<u<<" "<<" "<<w<<endl;

        costMST += w;
    }

}


int main()
{
    freopen("in_kruskal.txt", "r", stdin);

    int num_vertex, num_edges;
    cin>>num_vertex>>num_edges;

    for(int i=0; i<num_edges; i++)
    {
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back(v);
        graph[u].push_back(w);
        graph[v].push_back(u);
        graph[v].push_back(u);
    }
    // Display graph
    
    primsMST(0);


    
    cout<<"Total cost: "<<costMST<<endl;

    return 0;
}