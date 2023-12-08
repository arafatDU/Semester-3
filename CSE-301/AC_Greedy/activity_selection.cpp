#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a, i<b; i++)
#define ff first
#define ss second


int main()
{
    freopen("activity.txt", "r", stdin);

    vector<vector<int>> v;
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int start, end;
        cin>>start>>end;
        v.push_back({start, end});
    }

    // if n = 3 there are three vector<int>
    // vector<int> a    ---> a[0] = start, a[1] = end
    // vector<int> b    ---> b[0] = start, b[1] = end
    // vector<int> c    ---> c[0] = start, c[1] = end


    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b){
                                 return a[1] < b[1]; });

    int take = 1;
    int end = v[0][1];
    cout<<"Starting from "<<v[0][0]<<" ---> End "<<v[0][1]<<endl;
    for(int i=1; i<n; i++){
        if(v[i][0] >= end){
            cout<<"Starting from "<<v[i][0]<<" ---> End "<<v[i][1]<<endl;
            take++;
            end = v[i][1];
        }
    }



    return 0;
}