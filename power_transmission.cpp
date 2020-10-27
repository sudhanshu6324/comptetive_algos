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
        cin>>n;
        ll X[n],Y[n];
        for(i=0;i<n;i++){
            cin>>X[i]>>Y[i];
        }
     
        map<pair<ll,ll>,ll > mp;
        int vis[n][n];
        mem(vis);
        ll lines = 0;
        for(i=0;i<n;i++){
            map<pair<int,int>,vector<int> > mp1;
            for(j=i+1;j<n;j++){
                if(vis[i][j]) continue;
                ll yy = Y[j] - Y[i];
                ll xx = X[j] - X[i];
                int flag = 1;
                if(yy * xx < 0){
                    flag = -1;
                }
                yy = abs(yy);
                xx = abs(xx);
     
                if(xx == 0){
                    if(mp1[{1,0}].size() == 0){
                        mp[{1,0}]++;
                    }
                    mp1[{1,0}].pb(j);
                }else if(yy == 0){
                    if(mp1[{0,1}].size() == 0){
                        mp[{0,1}]++;
                    }
                    mp1[{0,1}].pb(j);
                }else{
                    ll g = __gcd(xx,yy);
                    xx /= g;
                    yy /= g;
                    if(mp1[{flag * yy,xx}].size() == 0){
                        mp[{flag * yy,xx}]++;
                    }
                    mp1[{flag * yy,xx}].pb(j);
                }
            }
            lines += mp1.size();
            //debug(mp1.size());
            for(auto y : mp1){
                //cout<<"hell"<<endl;
               // debug1(y.first.first,y.fi.se);
                for(auto x : y.second){
                    vis[i][x] = 1;
                    vis[x][i] = 1;
                }
            }
            for(auto y : mp1){
                for(auto x : y.second){
                    for(auto xx : y.second){
                        //debug1(x,xx);
                        vis[x][xx] = 1;
                    }
                }
            }
        }
        //debug(lines);
        ll ans = lines * (lines - 1) / 2;
     
        for(auto x : mp){
            ans -= x.second * (x.second - 1)/2;
        }
        cout<<ans<<endl;
        return 0;
    }
