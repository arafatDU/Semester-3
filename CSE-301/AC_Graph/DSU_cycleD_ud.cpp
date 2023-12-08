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


int main()
{
    freopen("cycle.txt", "r", stdin);
    
    for(int i=0; i<N; i++)
        make_set(i);

    int num_vertex, num_edges;
    cin>>num_vertex>>num_edges;

    vvi adjM(num_vertex+1, vi(num_vertex+1, 0));
    vii edges(num_edges);
    for(int i=0; i<num_edges; i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
        adjM[u][v] = 1;
        adjM[v][u] = 1;
    }
    
    // cycle detection
    bool cycle = false;
    for(auto p: edges){
        int u = p.first;
        int v = p.second;
        int x = find_set(u);
        int y = find_set(v);

        if(x == y){
            cycle = true;
        }else{
            union_sets(x, y);
        }
    }

    if(cycle){
        cout<<"Cycle present"<<endl;
    }else{
        cout<<"Cycle Not Present"<<endl;
    }

    return 0;
}