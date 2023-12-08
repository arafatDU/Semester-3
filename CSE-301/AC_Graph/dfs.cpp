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

//        1
//     2      3
//   4 5 6    7

int const N = 100;
vi adjList[N];
vvi adjM(N, vi(N, 0));
bool vis[N];



void dfs(int src)
{
    //preorder
    vis[src] = true;
    cout<<src<<" ";

    //Inorder
    for(int x: adjList[src])
    {
        if(!vis[x]){
            dfs(x);
        }
    }


}

int main()
{
    freopen("in_bfs.txt", "r", stdin);

    int num_vertex, num_edges;
    cin>>num_vertex>>num_edges;

    adjM.resize(num_vertex+1, vi(num_vertex+1,0));
    
    for(int i=1; i<num_vertex+1; i++)
    {
        int u,v;
        cin>>u>>v;
        adjM[u][v] = 1;
        adjM[v][u] = 1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    // display
    for(int i=1; i<num_vertex+1; i++)
    {
        for(int j=1; j<num_vertex+1; j++)
            cout<<adjM[i][j]<<"  ";
        cout<<endl;
    }

    cout<<"Adj List of the given graph: "<<endl;
    for(int i=1; i<num_vertex+1; i++){
        cout<<i<<" --> ";
        for(auto x: adjList[i])
            cout<<x<<" ";
        cout<<endl;
    }



    // DFS ---- 1 2 4 5 6 7 3
    for(int i=0; i<N; i++)
        vis[i] = false;
    
    int src = 1;

    cout<<"DFS Traversal: "<<endl;
    dfs(src);
    cout<<endl<<endl;



    


    return 0;
}



