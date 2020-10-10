// link :: https://www.spoj.com/problems/NY10E/
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
 
ll dp[100][15];
 
void fun(){
    int i,j,k;
    mem(dp);
    for(i=0;i<10;i++){
        dp[1][i] = 1;
    }
    for(k=2;k<65;k++){
        for(i=0;i<=9;i++){
            for(j=i;j<=9;j++){
                dp[k][i] += dp[k-1][j];
            }
        }
    }
    for(i=1;i<65;i++){
        for(j=1;j<10;j++){
            dp[i][0] += dp[i][j];
        }
    }
}
int main()
{
    fun();
    boost1;
    //boost2;
    int n,m,i,j,t,x,y,w;
    cin>>t;
    while(t--){
        cin>>x>>n;;
        cout<<x<<" "<<dp[n][0]<<endl;
    }
 
    return 0;
}
