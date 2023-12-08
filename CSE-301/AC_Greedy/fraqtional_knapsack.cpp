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
    freopen("fq_knapsack.txt", "r", stdin);

    int n, w, ans=0;
    cin>>n;
    vii v(n);

    for(int i=0; i<n; i++)
        cin>>v[i].ff>>v[i].ss;

    cin>>w;

    sort(v.begin(), v.end(), [&](pii &a, pii &b){
                                return (double)a.ff/a.ss > (double)b.ff/b.ss;
    });


    for(int i=0; i<n; i++)
    {
        if(w >= v[i].ss){
            cout<<v[i].ss<<" gram = "<<v[i].ff<<" TK"<<endl;
            ans += v[i].ff;
            w -= v[i].ss;
            continue;
        }

        double vPERw = (double)v[i].ff/v[i].ss;
        cout<<w<<" gram = "<<vPERw*w<<" TK"<<endl;
        ans += vPERw*w;
        w = 0;
        break;
    }

    cout<<"Ans: "<<ans<<endl;


    return 0;
}