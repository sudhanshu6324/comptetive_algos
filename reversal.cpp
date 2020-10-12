    #include<bits/stdc++.h>
    #define ll long long
    #define pb push_back
     
     
    using namespace std;
     
    int main(){
        // int t;
        // cin>>t;
        // while(t--){
        //     cin>>
        // }
        ll n,m,temp,l,r,mid,ans1,prev,room;
        cin>>n>>m;
        vector<ll> ans;
        ans.pb(1);
        // cin>>temp;
         prev=1;
        for(ll i=0;i<n;i++){
            
            cin>>temp;
             if(i!=n-1)ans.pb(temp+prev);
            prev+=temp;
        }
        
        
        for(ll i=0;i<m;i++){
            l=0,r=ans.size()-1;
            ans1=INT_MIN;
            cin>>temp;
            while(l<=r){
                mid=(r+l)/2;
                if(ans[mid]>temp) r=mid-1;
                else if(ans[mid]<temp){
                    
                    //ans1=max(ans1,mid);
                    if(ans1<mid){
                        ans1=mid;
                        room = temp - ans[mid] + 1;
                    }
                    l=mid+1;
                }
                else if(ans[mid]==temp){
                    // ans1=max(ans1,mid);
                    // room = temp - ans[mid] + 1;
                    if(ans1<mid){
                        ans1=mid;
                        room = temp - ans[mid] + 1;
                    }
                  break;  
                } 
            }
            cout<<ans1+1<<' '<<room<<endl;
        }
        
        
        
      return 0;
    }