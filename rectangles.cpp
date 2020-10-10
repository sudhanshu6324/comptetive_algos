// link :: https://www.spoj.com/problems/AE00/
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
 
 
 
int main()
{
    boost1;
    //boost2;
    int n,m,i,j,t,x,y,w;
 
    ll sum = 0;
    cin>>n;
    for(i=1;i<=n;i++){
        if(n/i - (i-1) <= 0){
            break;
        }
       // debug(sum);
        sum += n/i - (i-1);
    }
    cout<<sum;
    return 0;
}
