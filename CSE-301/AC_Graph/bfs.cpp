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
vvi adjM(N, vi(N, MAX));
bool vis[N];

vi previous(N);
vi path;

void generatePath(int x){
    if(x == -1) return;
    generatePath(previous[x]);
    path.push_back(x);
}

bool BFS_path(int source,int destination,int num_vertex)
{
    int m = MAX;
    for(int i=0; i<N; i++) vis[i] = false;

    queue <int> q;
    q.push(source);
    vis[source] = true;
    previous[source] = -1;

    while(!q.empty()){
        int v = q.front();
        if(v==destination){
            generatePath(v);
            return true;
        }
        q.pop();
        // for(int i=1; i<=num_vertex; i++){
        //     if(!vis[i] && adjM[v][i] != MAX){
        //         if(adjM[v][i] < m) m = adjM[v][i];
        //         previous[i] = v;
        //         q.push(i);
        //         vis[i] = true;
        //     }
        // }
        for(int x: adjList[v])
        {
            if(!vis[x] && adjM[v][x]!= MAX){
                previous[x] = v;
                q.push(x);
                vis[x] = true;
            }
        }
    }
    return false;
}







void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        
        for(int x : adjList[node]){
            if(!vis[x]){
                vis[x] = true;
                q.push(x);
            }
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



    // BFS ---- 1 2 3 4 5 6 7
    for(int i=0; i<N; i++)
        vis[i] = false;
    
    int src = 1;

    cout<<"BFS Traversal: "<<endl;
    bfs(src);
    cout<<endl<<endl;



    // path
    int dest = 3;
    if(BFS_path(src, dest, num_vertex)){
        cout<<"Path exist"<<endl;
        for(auto x: path){
            cout<<x<<" ";
        }
        cout<<endl;
    }else{
        cout<<"NO Path"<<endl;
    }


    return 0;
}



