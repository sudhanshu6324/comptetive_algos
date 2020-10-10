    // link :: https://www.spoj.com/problems/IOIPALIN/
    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    typedef double db;
    #define debug(x) cout<<#x<<" :: "<<x<<endl;
    #define boost1 ios::sync_with_stdio(0)
    #define boost2 cin.tie(0)
    #define size1 5005
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
     
    int dp[size1][size1];
    string a;
     
    int fun(int l,int r){
        if(l >= r){
            return 0;
        }
        if(dp[l][r] != -1)
            return dp[l][r];
        if(a[l] == a[r]){
            return dp[l][r] = fun(l+1,r-1);
        }
        return dp[l][r] = 1 + min(fun(l+1,r),fun(l,r-1));
    }
     
    int main()
    {
        boost1;
        boost2;
        int n,m,i,j,t,x,y,w;
        cin>>n;
        cin>>a;
        mem1(dp);
        cout<<fun(0,n-1);
     
        return 0;
    }
     
