#include<bits/stdc++.h>
 
using namespace std;
long long int red[100001],green[100001],blue[100001];
long long int findit(int i,int j,int k)
{
	long long int temp=(red[i]-green[j])*(red[i]-green[j])
+(red[i]-blue[k])*(red[i]-blue[k])+(green[j]-blue[k])*(green[j]-blue[k]);
	return temp;
}
 
 
int main()
{    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		long long int r,g,b;
		cin>>r>>g>>b;
 
		//long long int red[r],green[g],blue[b];
		for(int i=0;i<r;i++)
			cin>>red[i];
		for(int i=0;i<g;i++)
			cin>>green[i];
		for(int i=0;i<b;i++)
			cin>>blue[i];
		sort(red,red+r);
		sort(green,green+g);
		sort(blue,blue+b);
		int i=0,j=0,k=0;
		long long int ans = 2000000000000000000;
		while((i<r)&&(j<g)&&(k<b))
		{
			long long int temp=findit(i,j,k);
			ans = min(ans,temp);
 
			if((red[i]>=green[j])&&(red[i]>=blue[k]))
			{
				long long int temp2=2000000000000000000;
				if((j+1)<g)
					temp2=findit(i,j+1,k);
				long long int temp3=2000000000000000000;
				if((k+1)<b)
					temp3=findit(i,j,k+1);
				if(temp2<temp3)
				{
					j++;
				}
				else if(temp3<temp2)
				{
					k++;
				}
				else if(temp3!=2000000000000000000)
				{
					j++;
				}
				else
					break;
 
			}
			else if((red[i]<=green[j])&&(green[j]>=blue[k]))
			{
				long long int temp2=2000000000000000000;
                                if((i+1)<r)
                                        temp2=findit(i+1,j,k);
                          
                                long long int temp3=2000000000000000000;
                                if((k+1)<b)
                                        temp3=findit(i,j,k+1);
 
				if(temp2<temp3)
                                {
                                        i++;
                                }
                                else if(temp3<temp2)
                                {
                                        k++;
                                }
				else if(temp3!=2000000000000000000)
                                {
                                        i++;
                                }
                                else
                                {
                                        break;
                                }
 
                          
			}
			else
			{
				long long int temp2=2000000000000000000;
                                if((i+1)<r)
                                        temp2=findit(i+1,j,k);
                                
                                long long int temp3=2000000000000000000;
                                if((j+1)<g)
                                        temp3=findit(i,j+1,k);
				if(temp2<temp3)
                                {
                                        i++;
                                }
                                else if(temp3<temp2)
                                {
                                        j++;
                                }
				else if(temp3!=2000000000000000000)
                                {
                                        j++;
                                }
                                else
                                {
                                        break;
                                }
 
                                
			}
 
 
		}
		cout<<ans<<"\n";
	}
}
