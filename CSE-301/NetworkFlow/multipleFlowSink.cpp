#include<bits/stdc++.h>
using namespace std;
#define SIZE 50


int graph[SIZE][SIZE],vertex_num,edge_num,max_flow,src_num,des_num;
vector<int> path,parent(SIZE);
vector<bool> isVisited(SIZE,false);
vector<string> vertices,src,des;

void read_input();
bool BFS(int source,int destination);
void fulkerson(int source,int destination);
void reduction();
int index_of(string str);
int main(){
    freopen("mss.txt","r",stdin);
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
    for(int i=0;i<=vertex_num+2;i++){
        for(j=0;j<=vertex_num+2;j++){
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    fulkerson(vertex_num+1,vertex_num+2);
    cout<<"Maxflow: "<<max_flow<<endl;
    return 0;
}

void read_input(){
    src.push_back("v0");
    des.push_back("v0");
    vertices.push_back("v0");
    int i,j,u,v;
    string from,to;
    // for(i=0;i<SIZE;i++){
    //     for(j=0;j<SIZE;j++){
    //         graph[i][j]=INT_MAX;
    //     }
    // }
    cin>>edge_num;
    getchar();
    // cout << "Vertex Num: " << vertex_num << " Edge num: " << edge_num << endl;
    for(i=0;i<edge_num;i++){
        cin>>from>>to;
        // u;
        // v;c
        if(find(vertices.begin(),vertices.end(),from)==vertices.end()){
            vertices.push_back(from);
        }
        if(find(vertices.begin(),vertices.end(),to)==vertices.end()){
            vertices.push_back(to);
        }
        cin>>graph[index_of(from)][index_of(to)];
        getchar();
    }
    cin>>src_num>>des_num;
    getchar();
    for(i=0;i<src_num;i++){
        cin>>from;
        src.push_back(from);
    }
    for(i=0;i<des_num;i++){
        cin>>from;
        des.push_back(from);
    }
    vertex_num=vertices.size();
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

void reduction(){
    for(auto s:src){
        // cout<<"s: "<<s<<endl;
        int cap=0;
        for(auto d:graph[index_of(s)]){
            cap+=d;
        }
        // cout<<"Cap: "<<cap<<endl;
        graph[vertex_num+1][index_of(s)]=cap;
    } 
    for(auto d:des){
        int cap=0;
        for(int s=1;s<=vertex_num;s++){
            cap+=graph[s][index_of(d)];
        }
        graph[index_of(d)][vertex_num+2]=cap;
    }
}

int index_of(string str){
    int i=0;
    for(auto s:vertices){
        if(s==str){
            return i;
        }
        i++;
    }
    return -1;
}