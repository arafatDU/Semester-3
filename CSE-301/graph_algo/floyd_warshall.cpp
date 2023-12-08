#include<bits/stdc++.h>
using namespace std;

#define SIZE 100
#define INF 1000000

int adj[SIZE][SIZE];
int d[SIZE][SIZE];
int p[SIZE][SIZE];
map<string, int> name_index_map;
int edges, n=0;

void readInput()
{
    int i, j, w;
    string s;
    cin>>edges;

    while(edges--)
    {
        cin>>s;
        if(name_index_map[s] == 0)
            name_index_map[s] = ++n;

        i = name_index_map[s];
        cin>>s;
        if(name_index_map[s] == 0)
            name_index_map[s] = ++n;

        j = name_index_map[s];

        cin>>w;
        adj[i][j] = w;
    }


}


void printMatrix(int mat[SIZE][SIZE])
{
    int u, v;
    for (u = 1; u <= n; u++ )
    {
        for(v = 1; v <= n; v++)
        {
            cout << mat[u][v] << " ";
        }
        cout <<endl;
    }
}
void initialize_prededecessor()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == j || adj[i][j] == INF) p[i][j] = 0;
            else if(i != j && adj[i][j] <INF) p[i][j] = i;
        }
    }
}

void floyd_warshall()
{
    initialize_prededecessor();

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(d[i][k] != INF && d[k][j] != INF)
                {
                    if(d[i][k] + d[k][j] < d[i][j])
                    {
                        d[i][j] = d[i][k] + d[k][j];
                        p[i][j] = p[k][j];
                    }
                }
            }
        }
    }

}


void printPath(int s,int d)
{
    if (p[s][d]== INF){
        cout<<"No Path"<<endl;
        return;
    }
    else if(p[s][d]==s){
        for (auto vertices : name_index_map){
            if (vertices.second == s){
                cout << vertices.first << " -> ";
                break;
            }
        }
    }
    else{
        printPath(s,p[s][d]);
        printPath(p[s][d],d);
    }
    
}


int main()
{
    //string src, des;
    freopen("input_floydWarshall.txt", "r", stdin);
    readInput();
    printMatrix( adj );
    //cout<<n<<endl<<name_index_map.size()<<endl;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i != j && adj[i][j] == 0) adj[i][j] = INF;
            d[i][j] = adj[i][j];
        }
    }
    cout<<endl;       
    printMatrix( d );
    cout<<endl;

    floyd_warshall();

    printMatrix( d );
    cout<<endl;
    printMatrix( p );
    
    cout<<"\n\nEnter source: ";
    string source, dest;
    cin>>source>>dest;
    cout<<"\nEnter destination: ";

    cout<<endl<<name_index_map[source]<<" "<<name_index_map[dest]<<endl;
    cout<<"\nShortest path from "<<source<<" to "<<dest<<": ";
    printPath(name_index_map[source], name_index_map[dest]);
    cout<<endl;



    return 0;
}
