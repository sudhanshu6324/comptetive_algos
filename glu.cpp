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
     
    int main() {
     
        // boost1;
        // boost2;
        // freopen("input.txt", "r", stdin); // redirects standard input
    	// freopen("output.txt", "w", stdout); // redirects standard outputreturn 0;
     
    	ll n,m,i,j,k,l,t,w,x,y,z,r;
        cin>>t;
        while(t--){
            cin>>l>>r>>m;
            ll lim = r - l;
            ll mini = max((ll)1,m - lim);
            ll maxi = m + lim;
            ll a = -1,b,c;
            for(i=l;i<=r;i++){
                ll temp = (mini % i == 0) ? mini : (((mini/i) * i ) + i);
                if(temp <= maxi){
                    a = i;
                    break;
                }
            }
            if(a != -1){
                ll n = (mini % a == 0) ? mini/a : ( (mini/a) + 1 );
                ll temp = m - a * n;
                b = l;
                c = l + abs(temp);
                if(temp >= 0){
                    swap(b,c);
                }
     
                cout<<a<<" "<<b<<" "<<c<<endl;
            }
        }
        return 0;
    }
