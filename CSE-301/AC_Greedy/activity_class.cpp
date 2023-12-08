#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a,i<b;i++)
#define ff first
#define ss second


vector<pair<string,vi>> v;   // v[0].first = name and v[0].second[0] = start and v[0].second[1] = end
int n, take = 1;

void recursiveSelector(int i){
    int m = i + 1;
    while (m < n && v[m].second[0] < v[i].second[1]){
        v[m].second[2] = 0;
        m++;
    }
    if(m < n){
        take++;
        recursiveSelector(m);
    } else return ;
}



void iterative()
{
    int end = v[0].second[1];
    cout<<"Starting from "<<v[0].second[0]<<"  "<<v[0].first<<" ---> End "<<v[0].second[1]<<endl;
    for(int i=1; i<n; i++){
        if(v[i].second[0] >= end){
            cout<<"Starting from "<<v[i].second[0]<<"  "<<v[i].first<<" ---> End "<<v[i].second[1]<<endl;
            take++;
            end = v[i].second[1];
        }
    }

    cout<<"Total class: "<<take<<endl;

}


int main()
{
    freopen("activity_cls.txt", "r", stdin);
    cin>>n;

    v.resize(n);

    for(int i=0; i<n; i++)
    {
        string name;
        cin>>name;
        v[i].first = name;
        int start, end;
        cin>>start>>end;
        v[i].second.push_back(start);
        v[i].second.push_back(end);
        v[i].second.push_back(1);   // compatiability
        //v[i].seccond.push_back({start, end});
    }

    // if n = 3 there are three vector<int>
    // vector<int> a    ---> a[0] = start, a[1] = end
    // vector<int> b    ---> b[0] = start, b[1] = end
    // vector<int> c    ---> c[0] = start, c[1] = end


    sort(v.begin(), v.end(), [&](pair<string,vi> &a, pair<string,vi> &b){
                                 return a.second[1] < b.second[1]; });

    
    //iterative();

    recursiveSelector(0);
    for(int i=0; i<n; i++){
        if(v[i].second[2] == 1){  // check compatiability
            cout<<"Starting from "<<v[i].second[0]<<"  "<<v[i].first<<" ---> End "<<v[i].second[1]<<endl;
        }
    }
    cout<<"Total class: "<<take<<endl;


    return 0;
}