#include<bits/stdc++.h>
using namespace std;
#define SIZE 50
#define inf 100
int graph[SIZE][SIZE],vertex_num,edge_num,max_flow,supersource,supersink;
vector<int> path,parent(SIZE),supply;
vector<bool> isVisited(SIZE,false);

void read_input();
bool BFS(int source,int destination);
void fulkerson(int source,int destination);
void reduction();
int main(){
    freopen("ff.txt","r",stdin);
    int i,j;
    read_input();

    // for(int i=0;i<=vertex_num;i++){
    //     for(j=0;j<=vertex_num;j++){
    //         cout<<graph[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;
    reduction();
    for(i=0;i<=supersink;i++){
        for(j=0;j<=supersink;j++){
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    fulkerson(supersource,supersink);
    cout<<"Maxflow: "<<max_flow<<endl;
    return 0;
}

void read_input(){
    int i,j,u,v;
    cin>>vertex_num>>edge_num;
    for(i=0;i<edge_num;i++){
        cin>>u>>v;
        cin>>graph[u][v];
    }
    supply.resize(vertex_num+1);
    // supply[0]=0;
    for(i=1;i<=vertex_num;i++){
        cin>>supply[i];
    }
    cout<<endl;
}

bool BFS(int source,int destination){
    path.clear();
    parent.clear();
    isVisited.assign(isVisited.size(),false);
    queue<int> q;
    q.push(source);
    parent[source]=-1;
    parent[destination]=-2;
    isVisited[source]=true;
    while(!q.empty()){
        int u=q.front(),i;
        q.pop();
        isVisited[u]=true;
        for(i=1;i<=supersink;i++){
            if(graph[u][i]>0&&!isVisited[i]){
                q.push(i);
                isVisited[i]=true;
                parent[i]=u;
            }
        }
        
    }
    if(parent[destination]==-2){
        return false;
    }
    stack<int> st;
    int j=destination;
    st.push(j);
    while(parent[j]!=-1){
        st.push(parent[j]);
        j=parent[j];
    }
    while(!st.empty()){
        path.push_back(st.top());
        st.pop();
    }
    return true;
}

void fulkerson(int source,int destination){
    while(BFS(source,destination)){
        int u,v,min=INT_MAX;
        for(int i=0;i<path.size()-1;i++){
            u=path[i];
            v=path[i+1];
            if(graph[u][v]<min){
                min=graph[u][v];
            }
        }
        max_flow+=min;
        // printf("mf: %d\n", max_flow);
        for(int i=0;i<path.size()-1;i++){
            u=path[i];
            v=path[i+1];
            graph[u][v]-=min;
        }
        
    }
}

void reduction(){
    supersource = vertex_num + 1;
    supersink = vertex_num + 2; 
    // for(int i=1;i<=vertex_num;i++){
    //     for(int j=1;j<=vertex_num;j++){
    //         graph[i][j+vertex_num]=graph[i][j];
    //         graph[i][j]=0;
    //     }
    //     graph[i][i+vertex_num]= inf;
    //     graph[supersource][i] = inf;
    // }
    // for(int i=1;i<=vertex_num;i++){
    //     int cap=0;
    //     for(int j=1;j<=vertex_num;j++){
    //         cap+=graph[i][j+vertex_num];
    //     }
    //     graph[i+vertex_num][supersink]=cap-inf;
    // }
    for(int i=1;i<=vertex_num;i++){
        if(supply[i]<0){
            graph[i][supersink]=-supply[i];
        }
        else{
            graph[supersource][i]=supply[i];
        }
    }
}