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
        cin>>t;
        while(t--){
            cin>>n;
            map<int,int> mp,mp1;
            vector<pair<int,int> > v;
            for(i=0;i<n;i++){
                cin>>x>>y;
                mp[x]++;
                mp1[x] += y;
            }
            for(auto x : mp){
                v.push_back({x.second,mp1[x.first]});
            }
            sort(v.begin(),v.end());
            int k = v.size() - 1;
            int maxi = v[k].first;
     
            priority_queue<int> pq;
            int ans1 = 0,ans2 = 0;
            while(true){
                if(maxi == 0) {
                    break;
                }
                while(k >= 0 && v[k].first >= maxi){
                    pq.push(v[k].second);
                    k--;
                }
     
                if(pq.size() == 0) {
                    maxi--;
                    continue;
                }
     
                ans1 += maxi;
                ans2 += min(maxi,pq.top());
     
                pq.pop();
     
                maxi--;
            }
     
            cout<<ans1<<" "<<ans2<<endl;
        }
        return 0;
    }
