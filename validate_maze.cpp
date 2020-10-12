// link :: https://www.spoj.com/problems/MAKEMAZE/
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
 
int a[25][25],vis[25][25],n,m;
 
bool valid(int x,int y){
    return (a[x][y] == 0) && x >=0 && x < m && y >= 0 && y < n;
}
int main()
{
    boost1;
    //boost2;
    int i,j,t,x,y,w,u,vv;
    string str[22];
    cin>>t;
    while(t--){
        cin>>m>>n;
        for(i=0;i<m;i++){
            cin>>str[i];
        }
        vector<pii> v;
        mem(a);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(str[i][j] == '#')
                    a[i][j] = 1;
                if(a[i][j] == 0 && (i == 0 || j == 0 || i == m-1 || j == n-1))
                    v.pb(make_pair(i,j));
            }
        }
        if(v.size() != 2){
            cout<<"invalid"<<endl;
            continue;
        }
        int flag = 0;
        mem(vis);
 
        for(i=0;i<v.size();i++){
            u = v[i].fi;
            vv = v[i].se;
            mem(vis);
            vis[u][vv] = 1;
            queue<pii> q;
            q.push(make_pair(u,vv));
            int c = 0;
            while(!q.empty()){
                x = q.front().first;
                y = q.front().second;
                q.pop();
 
                if(valid(x+1,y) && !vis[x+1][y]){
                    q.push(make_pair(x+1,y));
                    vis[x+1][y] = 1;
                }
                if(valid(x,y+1) && !vis[x][y+1]){
                    q.push(make_pair(x,y+1));
                    vis[x][y+1] = 1;
                }
                if(valid(x-1,y) && !vis[x-1][y]){
                    q.push(make_pair(x-1,y));
                    vis[x-1][y] = 1;
                }
                if(valid(x,y-1) && !vis[x][y-1]){
                    q.push(make_pair(x,y-1));
                    vis[x][y-1] = 1;
                }
                if(!(x == u && y == vv) && (x == 0 || y == 0 || x == m-1 || y == n-1)){
                    c++;
                   // break;
                }
            }
            if(c>1){
                flag = 0;
                break;
            }else if(c ==1){
                flag = 1;
            }
        }
        if(flag)
            cout<<"valid"<<endl;
        else
            cout<<"invalid"<<endl;
    }
 
    return 0;
}
