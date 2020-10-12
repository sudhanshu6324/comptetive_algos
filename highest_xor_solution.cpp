#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double db;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define boost1 ios::sync_with_stdio(0)
#define boost2 cin.tie(0)
#define size1 200005
#define mod 1000000007
#define vll         vector < ll >
#define vpll        vector < pair < ll ,ll> >
#define pii         pair < int,int >
#define pll         pair < ll,ll >
#define fi          first
#define se          second
#define pb(x)       push_back(x)
#define endl        "\n"
#define mem1(x)     memset(x,-1,sizeof x)
#define mem(x)      memset(x,0,sizeof x)
#define mem63(x)    memset(x,63,sizeof x)
 
int dp[size1],a[size1];
 
 
int main()
{
    boost1;
    boost2;
    int n,m,i,j,t,x,y,w,maxi = 0;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    vector<pair<int,int> > v;
    v.push_back({-1,-1});
    for(i=0;i<m;i++){
        cin>>x>>y;
        v.push_back({x,y});
    }
 
    for(i=1;i<=n;i++){
        a[i] += a[i-1];
    }
 
    sort(v.begin(),v.end());
 
    int prev= 0;
 
    for(i=0;i<v.size();i++){
        maxi = 0;
        prev = j=max(prev+v[i].se,v[i].fi);
        for(;j <= n && j < v[i].fi + v[i].se && (i==v.size()-1 || j < v[i+1].fi);j++){
            dp[j] = max(dp[j-1], dp[j-v[i].se] + a[j] - a[j-v[i].se]);
            maxi = max(maxi,dp[j]);
        }
        if(i != v.size() - 1){
            for(j=v[i].fi + v[i].se;j<v[i+1].fi;j++){
                dp[j] = maxi;
            }
        }
    }
    cout<<maxi<<endl;
    return 0;
}