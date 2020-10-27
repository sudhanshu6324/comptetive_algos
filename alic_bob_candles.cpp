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
     
     
    ll fun(ll n,ll k){
        return n - n/k;
    }
     
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
            vector<int> v;
            for(i=0;i<n;i++){
                cin>>x;
                v.push_back(x);
            }
            i = 0;
            j = n-1;
            ll ans1 = 0,ans2 = 0;
            ll prev = 0,turn = 0,cur,mo = 0;
            while(i <= j){
                cur = 0;
                mo++;
                if(turn == 0){
                    while(i <= j && cur <= prev){
                        cur += v[i++];
                    }
                    ans1 += cur;
                    prev = cur;
                }else{
                    while(i <= j && cur <= prev){
                        cur += v[j--];
                    }
                    ans2 += cur;
                    prev = cur;
                }
                turn = !turn;
            }
            cout<<mo<<" "<<ans1<<" "<<ans2<<endl;
        }
        return 0;
    }
