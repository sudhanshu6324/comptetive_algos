#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double db;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define boost1 ios::sync_with_stdio(0)
#define boost2 cin.tie(0)
#define size1 100005
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
 
 
long long a[size1];
int main()
{
    boost1;
    //boost2;
    long long n,m,i,j,t,x,y,w;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int idx = 0;
    //sort()
    for(int i=63;i>=0;i--){
        ll maxi = -99999999999;
        int max_idx = -1;
        ll one = 1;
        for(j=idx;j<n;j++){
            if(a[j] > maxi && (a[j] & (one<<i))) {
                maxi = a[j];
                max_idx = j;
            }
        }
        if(max_idx == -1 || idx >= n) continue;
 
        swap(a[idx],a[max_idx]);
        for(j=0;j<n;j++){
            if(j != idx && a[j]&(one<<i)){
                a[j] ^= maxi;
            }
        }
        idx++;
    }
    ll res = 0;
    for(int i=0;i<n;i++){
        res ^= a[i];
    }
 
    cout<<res;
    return 0;
}
 