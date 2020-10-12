#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double db;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define boost1 ios::sync_with_stdio(0)
#define boost2 cin.tie(0)
#define size1 30005
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
 
ll a[size1];
 
ll _mergeSort(ll arr[], ll temp[], ll left, ll right);
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right);
 
 
ll mergeSort(ll arr[], ll array_size)
{
    ll temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 
 
ll _mergeSort(ll arr[], ll temp[], ll left, ll right)
{
    ll mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
 
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
 
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
 
 
ll merge(ll arr[], ll temp[], ll left,
          ll mid, ll right)
{
    ll i, j, k;
    ll inv_count = 0;
 
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
 
            inv_count = inv_count + (mid - i);
        }
    }
 
 
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    while (j <= right)
        temp[k++] = arr[j++];
 
 
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}
 
// Driver code
int main()
{
    ll t,n,i;
    string str[size1];
    string s;
 
    cin>>t;
    while(t--){
        map<string,int> mp;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>str[i];
        }
        for(i=0;i<n;i++){
            cin>>s;
            mp[s] = i;
        }
        for(i=0;i<n;i++){
            a[i] = mp[str[i]];
        }
        ll ans = mergeSort(a, n);
        cout<<ans<<endl;
    }
 
    return 0;
}