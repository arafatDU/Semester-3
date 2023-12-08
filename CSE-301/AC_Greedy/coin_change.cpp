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
    freopen("coin_change.txt", "r", stdin);

    int n;
    cin>>n;

    vi a(n);

    for(int i=0; i<n; i++)
        cin>>a[i];

    int x; 
    cin>>x;

    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;

    for(int i=0; i<n; i++)
    {
        ans += x/a[i];
        if(x/a[i] != 0) cout<<a[i]<<" need "<<x/a[i]<<endl;
        x -= (x/a[i])*a[i];
    }

    cout<<endl<<"Ans: "<<ans<<endl;

    return 0;
}