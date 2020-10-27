    #include<bits/stdc++.h>
     
    using namespace std;
    vector<int> adj[100001];
    int flag=0;
    int count=0;
    int dfs(int i,int p)
    {
     ios_base::sync_with_stdio(false);
         cin.tie(NULL);
    	int f=0;
    	int odd=0;
    	int even=0;
    	for(int j=0;j<adj[i].size();j++)
    	{
     
    		if(adj[i][j]!=p)
    		{
    			f=1;
    			int ret = dfs(adj[i][j],i);
    			if(ret%2==0)
    				odd=1;
    			else
    				even=1;
    		}
    	}
    	if(f==0)
    		return 0;
     
    	if((odd==1)&&(even==1))
    	{
    		flag=1;
    		return 0;
    	}
    	else if(odd==1)
    	{
    		return 1;
    	}
    	else
    	{
    		return 0;
    	}
    	return 0;
     
     
    }
     
    int dfs2(int i,int p)
    {
    	
    int cc=0;
    int f=0;
    	for(int j=0;j<adj[i].size();j++)
    	{
    		
    		if(adj[i][j]!=p)
    		{
    			if(adj[adj[i][j]].size()==1)
    			{
    				f=1;
    			}
    			else
    			{
    				int ret = dfs2(adj[i][j],i);
    				cc+=ret;
    				cc++;
    			}
    		}
    	}
    	return cc+f;
    }
     
     
     
    int main()
    {
    		int n,a,b;
    		cin>>n;
     
    		for(int i=0;i<n-1;i++)
    		{
    			cin>>a>>b;
    			adj[a-1].push_back(b-1);
    			adj[b-1].push_back(a-1);
    		}
    		int ans=0;
    		for(int i=0;i<n;i++)
    		{
    			if(adj[i].size()>1)
    			{
    				dfs(i,-1);
    				ans= dfs2(i,-1);
    				break;
    			}
    		}
    		if(flag==1)
    			cout<<3<<" ";
    		else
    			cout<<1<<" ";
    	
    		cout<<ans<<"\n";
     
     
    	
    }
