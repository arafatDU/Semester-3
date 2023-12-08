#include<bits/stdc++.h>
using namespace std;

int graph[50][50],vertex_num,edge_num,supersource,supersink,max_flow;
set<int> setU,setV;
vector<int> path,parent(50);
vector<bool> isVisited(50);

void read_input();
void reduction();
bool BFS(int source,int destination);
void fulkerson(int source,int destination);

int main(){
    freopen("bi.txt","r",stdin);
    read_input();
    reduction();
    fulkerson(supersource,supersink);
    for(int i=0;i<=vertex_num+2;i++){
        for(int j=0;j<=vertex_num+2;j++){
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<"Maximum mathcing for the bipartite graph: "<<max_flow<<endl;
    return 0;
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
        for(i=1;i<=vertex_num+2;i++){
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

void read_input(){
    cin>>vertex_num>>edge_num;
    int u,v;
    supersink=vertex_num+2;
    supersource=vertex_num+1;
    // setU.insert(0);
    // setV.insert(0);
    for(int i=0;i<edge_num;i++){
        cin>>u>>v;
        setU.insert(u);
        setV.insert(v);
        graph[u][v]=1;
    }
}

void reduction(){
    for(auto u:setU){
        graph[supersource][u]=1;
    }
    for(auto v:setV){
        graph[v][supersink]=1;
    }
}