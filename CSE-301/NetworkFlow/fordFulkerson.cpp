#include<bits/stdc++.h>
using namespace std;
#define SIZE 50
int graph[SIZE][SIZE],vertex_num,edge_num,max_flow;
vector<int> path,parent(SIZE);
vector<bool> isVisited(SIZE,false);

void read_input();
bool BFS(int source,int destination);
void fulkerson(int source,int destination);
int main(){
    freopen("ford.txt","r",stdin);
    int i,j;
    read_input();
    for(int i=0;i<6;i++){
        for(j=0;j<6;j++){
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
    fulkerson(0,5);
    cout<<"Maxflow: "<<max_flow<<endl;
    return 0;
}

void read_input(){
    int i,j,u,v;
    // for(i=0;i<SIZE;i++){
    //     for(j=0;j<SIZE;j++){
    //         graph[i][j]=INT_MAX;
    //     }
    // }
    cin>>vertex_num>>edge_num;
    for(i=0;i<edge_num;i++){
        cin>>u>>v;
        u--;
        v--;
        cin>>graph[u][v];
    }
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
        for(i=0;i<vertex_num;i++){
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
        for(int i=0;i<path.size()-1;i++){
            u=path[i];
            v=path[i+1];
            graph[u][v]-=min;
        }
        
    }
}