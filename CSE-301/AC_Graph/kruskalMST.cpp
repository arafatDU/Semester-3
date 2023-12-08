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
#define N 100

// Disjoint set union
vi parent(N);
vi size(N);

void make_set(int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v){
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int kruskal(vvi edges)
{
    int cost = 0;

    sort(edges.begin(), edges.end());
    
    for(auto i: edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];

        int a = find_set(u);
        int b = find_set(v);

        if(a == b){
            continue;
        }else{
            cout<<u<<" --> "<<v<<"  cost:"<<w<<endl;
            cost += w;
            union_sets(u, v);
        }
    }

    return cost;
}


int main()
{
    freopen("in_kruskal.txt", "r", stdin);
    
    for(int i=0; i<N; i++)
        make_set(i);

    int num_vertex, num_edges;
    cin>>num_vertex>>num_edges;

    vvi edges;

    for(int i=0; i<num_edges; i++)
    {
        int u,v,w; cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }


    int cost = kruskal(edges);
    cout<<"Total cost: "<<cost<<endl;

    return 0;
}