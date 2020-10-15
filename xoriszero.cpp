#include<bits/stdc++.h>
#define ll long long int

using namespace std;
ll n;
ll arr[100001];
vector<ll> adj[100001];
ll ans=0;
unordered_map<ll,ll> findit(ll i, ll p)
{
	//cout<<"i is:"<<i<<"\n";
	int flg=0;
	unordered_map<ll,ll> mp1,mp2,mpans;
	for(int j=0;j<adj[i].size();j++)
	{
		if(adj[i][j]!=p)
		{
			if(flg==0)
				mp1=findit(adj[i][j], i);
			else if(flg==1)
				mp2=findit(adj[i][j], i);
			flg++;
		}
	}
	if(flg==0)
	{
		mpans[arr[i]]=1;
		return mpans;
	}
	else if(flg==1)
	{
		ans+=mp1[arr[i]];
		for(auto it = mp1.begin();it!=mp1.end();it++)
			mpans[(it->first)^arr[i]]=it->second;
		mpans[arr[i]]++;	
		return mpans;
	}
	else
	{
		for(auto it=mp1.begin();it!=mp1.end();it++)
		{
			ans+=(mp2[(it->first)^arr[i]]*it->second);
		}
		ans+=mp1[arr[i]];
		ans+=mp2[arr[i]];
		for(auto it=mp1.begin();it!=mp1.end();it++)
		{
			mpans[it->first]+=it->second;
		}
		for(auto it=mp2.begin();it!=mp2.end();it++)
		{
			mpans[it->first]+=it->second;
		}
		mpans[arr[i]]++;
		return mpans;
	}
	return mpans;


		
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	ll u,v;
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	findit(0, -1);
	cout<<ans<<"\n";
}


	

	
	


