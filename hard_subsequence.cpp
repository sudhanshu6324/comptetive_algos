    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    typedef double db;
    #define debug(x) cout<<#x<<" :: "<<x<<endl;
    #define debug1(x,y) cout<<#x<<" :: "<<x<<"   "<<#y<<" :: "<<y<<endl;
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
    #define flush       fflush(stdout)
     
     
     
    int main()
    {
        //boost1;
        //boost2;
    //    freopen("input.txt", "r", stdin); // redirects standard input
    //	freopen("output.txt", "w", stdout); // redirects standard output
     
        ll n,m,i,j,t,x,y,w,k;
        cin>>n>>k;
        string str;
        cin>>str;
        int last[n];
        mem1(last);
        for(i=0;i<n;i++){
            for(j=i-1;j>=0;j--){
                if(str[j] == str[i]){
                    last[i] = j;
                    break;
                }
            }
        }
        ll dp[n+1][n+1];
        mem(dp);
        set<char> s;
        for(i=0;i<n;i++){
            s.insert(str[i]);
            dp[1][i] = s.size();
        }
        for(int l=2;l<=n;l++){
            for(i=0;i<n;i++){
                dp[l][i] = dp[l][i-1] + dp[l-1][i-1] - (last[i]-1 >= 0 ? dp[l-1][last[i]-1] : 0);
                //debug1(i,dp[l][i]);
            }
        }
        ll cnt,cost;
        cnt = cost = 0;
        for(i=n;i>=1;i--){
           // debug(dp[i][n-1]);
            if(cnt + dp[i][n-1] < k){
                cnt += dp[i][n-1];
                cost += dp[i][n-1] * (n - i);
            }else if(cnt + dp[i][n-1] == k){
                cnt = k;
                cost += dp[i][n-1] * (n - i);
                break;
            }else{
                cost += (n-i) * (k - cnt);
                cnt = k;
                break;
            }
        }
        if(cnt < k){
            cnt++;
            cost += n;
        }
        //debug(cnt);
        if(cnt < k){
            cout<<(-1)<<endl;
            return 0;
        }
        cout<<cost<<endl;
        return 0;
    }
